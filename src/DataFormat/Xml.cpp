#include <iostream>

#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "ADataFormat.hh"
#include "Parser.hh"
#include "FormatError.hh"
#include "eFormat.hh"
#include "Xml.hh"

static eBaliseState	parseBaliseState(std::string const & str) {
  return str[1] == '/' ? CLOSING : OPENING;
}

static bool		testIfBalise(std::string const & str) {
  return str[0] == '<' ? true : false;
}

static std::string	parseBaliseName(std::string const & str, eBaliseState state) {
  unsigned int i;
  std::string name;

  if (state == OPENING)
    i = 1;
  else
    i = 2;
  for (; i < str.length(); i++) {
    switch (str[i]) {
    case ' ':
      return name;
    case '>':
      return name;
    default:
      name += str[i];
    }
  }
  return name;
}

static std::string const getEmplacement(std::string const & infile, std::pair<int, std::string const> line) {
  std::stringstream s;
  s << infile << ":" << line.first << ":";
  return s.str();
}

static void	checkConformity(std::string const & infile, std::pair<int, std::string const> line) {
  bool chev = false, quotes = false, car = false;
  for (unsigned int i = 0; i != line.second.length(); i++) {
    switch (line.second[i]) {
    case '"':
      if (quotes == false)
	quotes = true;
      else
	quotes = false;
    case '<':
      chev = true;
      break;
    case ' ':
      if ((car == false && chev == true) || (i > 0 && line.second[i - 1] == '/'))
	throw (Error("incorrect xml syntax", getEmplacement(infile, line), "invalid space caracter before balise name declaration"));
      break;
    case '>':
      if (chev == false)
	throw (Error("incorrect xml syntax", getEmplacement(infile, line), "'<' is needed before closing one"));
      if (line.second[i - 1] == ' ')
	throw (Error("incorrect xml syntax", getEmplacement(infile, line), "invalid space caracter before '>'"));
      chev = false;
      break;
    default:
      car = true;
      break;
    }
  }
  if (chev == true)
    throw (Error("incorrect xml syntax", getEmplacement(infile, line), "missing '>' at the end of expression"));
  if (quotes == true)
    throw (Error("incorrect xml syntax", getEmplacement(infile, line), "mismatched '\"'"));
}

static bool isUseless(std::string const &str) {
  for (unsigned int i = 0; i < str.length(); i++)
    if (str[i] != ' ')
      return false;
  return true;
}

static void epurXmlDatas(std::list<std::pair<int, std::string> > & epur,
			 std::pair<int, std::string const> content) {
  std::string recup;
  for (unsigned int i = 0; i < content.second.length(); i++) {
    switch (content.second[i]) {
    case '<':
      if (recup.empty() == false && isUseless(recup) == false)
	epur.push_back(std::make_pair(content.first, recup));
      recup.clear();
      recup += content.second[i];
      break;
    case '>':
      recup += content.second[i];
      epur.push_back(std::make_pair(content.first, recup));
      recup.clear();
      break;
    default:
      recup += content.second[i];
      break;
    }
  }
  if (recup.empty() == false && isUseless(recup) == false)
    epur.push_back(std::make_pair(content.first, recup));
}

static Xml::Balise *getUpperNonClosed(std::list<Xml::Balise *> const & balises, std::list<Xml::Balise *>::const_iterator it) {
  Xml::Balise * tmp = 0;
  for (std::list<Xml::Balise *>::const_iterator it2 = balises.begin(); it2 != it; ++it2) {
    if ((*it2)->Xml::Balise::getAssociated() == 0)
      tmp = *it2;
  }
  return tmp;
}

static void assignAssociated(std::list<Xml::Balise *> const & balises) {
  for (std::list<Xml::Balise *>::const_iterator it = balises.begin(); it != balises.end(); ++it) {
    if ((*it)->Xml::Balise::getState() == CLOSING && (*it)->Xml::Balise::getAssociated() == 0)
      for (std::list<Xml::Balise *>::const_iterator it2 = balises.begin(); it2 != it; ++it2) {
	if ((*it2)->Xml::Balise::getState() == OPENING && (*it2)->Xml::Balise::getName() == (*it)->Xml::Balise::getName()) {
	  (*it)->Xml::Balise::setParent((*it2)->Xml::Balise::getParent());
	  (*it2)->Xml::Balise::setAssociated(*it);
	  (*it)->Xml::Balise::setAssociated(*it2);
	  Xml::Balise *bal = getUpperNonClosed(balises, it2);
	  (*it2)->Xml::Balise::setParent(bal);
	  (*it)->Xml::Balise::setParent(bal);
	  (*it)->Xml::Balise::setChildren((*it2)->Xml::Balise::getChilden());
	  if (bal) {
	    bal->Xml::Balise::addChild(*it);
	    bal->Xml::Balise::addChild(*it2);
	  }
	}
      }
  }
}

std::string const stateChar(Xml::Balise *balise) {
  if (balise->Xml::Balise::getState() == CLOSING)
    return " (CLOSING)";
  return " (OPENING)";
}

Xml::Xml(std::string const & infile) : ADataFormat(XML, infile) {
  std::map<int, std::string const>::const_iterator it;
  std::list<std::pair<int, std::string> > epur;

  for (it = this->getContent().begin(); it != this->getContent().end(); ++it)
    epurXmlDatas(epur, *it);
  for (std::list<std::pair<int, std::string> >::iterator it2 = epur.begin(); it2 != epur.end(); ++it2)
    checkConformity(infile, *it2);
  for (std::list<std::pair<int, std::string> >::iterator it2 = epur.begin(); it2 != epur.end(); ++it2) {
    if (testIfBalise(it2->second) == true) {
      eBaliseState eS = parseBaliseState(it2->second);
      std::string name = parseBaliseName(it2->second, eS);
      if (name.empty() == true)
	throw (Error("invalid xml syntax", getEmplacement(infile, *it2), "balise name can't be empty"));
      Balise *bal = new Balise(name, eS);
      this->_balises.push_back(bal);
    }
    else {
      if (this->_balises.back()->getState() == CLOSING)
	throw (Error("invalid content declaration", getEmplacement(infile, *it2), "ambigous statement \"" + Parser::epurString(it2->second) + "\""));
      this->_balises.back()->setContent(Parser::epurString(it2->second));
    }
  }
  assignAssociated(this->_balises);
  for (std::list<Balise *>::iterator it2 = this->_balises.begin(); it2 != this->_balises.end(); ++it2) {
    if ((*it2)->getAssociated() == 0) {
      if ((*it2)->getState() == OPENING)
	throw (Error("invalid xml syntax", infile, "balise \"<" + (*it2)->getName() + ">\" has no related closing one"));
      else
	throw (Error("invalid xml syntax", infile, "balise \"</" + (*it2)->getName() + ">\" has no related opening one"));
    }
  }
  // for (std::list<Balise *>::iterator it2 = this->_balises.begin(); it2 != this->_balises.end(); ++it2) {
  //   std::cout << "Balise : " << (*it2)->Balise::getName() << stateChar(*it2) << std::endl;
  //   std::cout << "Associated : " << (*it2)->Balise::getAssociated()->Balise::getName() << stateChar((*it2)->Balise::getAssociated()) << std::endl;
  //   if (!(*it2)->Balise::getParent())
  //     std::cout << "Herited from : DOM" << std::endl;
  //   else
  //     std::cout << "Herited from : " << (*it2)->Balise::getParent()->Balise::getName() << std::endl;
  //   std::cout << "Content : " << (*it2)->Balise::getContent() << std::endl;
  //   std::cout << "Enfants :" << std::endl;
  //   for (std::list<Balise *>::const_iterator it3 = (*it2)->Balise::getChilden().begin(); it3 != (*it2)->Balise::getChilden().end(); ++it3) {
  //     std::cout << "- " << (*it3)->Balise::getName() << stateChar(*it3) << std::endl;
  //   }
  //   std::cout << std::endl;
  // }
}

static void	eraseBalises(Xml::Balise *bal) {
  delete bal;
}

Xml::~Xml() {
  std::for_each(this->_balises.begin(), this->_balises.end(), eraseBalises);
}

Xml::Balise::Balise(std::string const & name, eBaliseState state)
  : _name(name),
    _state(state),
    _parent(0),
    _children(0),
    _associated(0)
{
}


Xml::Balise::~Balise() {
}

Xml::Balise *				Xml::Balise::getParent() const {
  return this->_parent;
}

void					Xml::Balise::setParent(Balise *parent) {
  if (parent)
    this->_parent = parent;
}

std::string const &			Xml::Balise::getName() const {
  return this->_name;
}

void					Xml::Balise::setName(std::string const & name) {
  this->_name = name;
}

std::string const &			Xml::Balise::getContent() const {
  return this->_content;
}

void					Xml::Balise::setContent(std::string const & content) {
  this->_content = content;
}

std::list<Xml::Balise *> const &	Xml::Balise::getChilden() const {
  return this->_children;
}

void					Xml::Balise::addChild(Balise *child) {
  this->_children.push_back(child);
}

Xml::Balise *				Xml::Balise::getAssociated() const {
  return this->_associated;
}

void					Xml::Balise::setAssociated(Balise *balise) {
  this->_associated = balise;
}

eBaliseState				Xml::Balise::getState() const {
  return this->_state;
}

void					Xml::Balise::setChildren(std::list<Xml::Balise *> const & children) {
  this->_children = children;
}

void					Xml::generate(std::string const & outFileName) const {
  std::ofstream file(outFileName.c_str(), std::ios::in | std::ios::trunc);
  if (file) {
    for (std::list<Balise *>::const_iterator it = this->_balises.begin(); it != this->_balises.end(); ++it) {
      file << "<";
      if ((*it)->getState() == CLOSING)
	file << "/";
      file << (*it)->getName()<< ">" << std::endl;
      if ((*it)->getState() == OPENING)
	if ((*it)->getContent().empty() == false)
	file << (*it)->getContent() << std::endl;
    }
    file.close();
  }
  else
    throw (Error("file error", "generate method", "the file " +  outFileName + " can't be openened"));
}
