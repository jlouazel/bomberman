#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ADataFormat.hh"
#include "Parser.hh"
#include "FormatError.hh"
#include "eFormat.hh"
#include "Xml.hh"

namespace BomberMan
{
  namespace DataFormat
  {
    static
    eBaliseState                parseBaliseState(std::string const & str) {
      return str[1] == '/' ? CLOSING : OPENING;
    }

    static
    bool                    testIfBalise(std::string const & str) {
      return str[0] == '<' ? true : false;
    }

    static
    std::string const           getEmplacement(std::string const & infile, int line) {
      std::stringstream s;
      s << infile << ":" << line << ":";
      return s.str();
    }

    static
    void                    isUnexpected(std::string const & infile, int line, char c) {
      if (c == '/' ||
	  c == '=' ||
	  c == '?' ||
	  c == '$' ||
	  c == '"')
	throw (FormatError("invalid xml syntax", getEmplacement(infile, line), "unexpected character"));
    }

    static
    std::string             parseBaliseName(std::string const & infile, unsigned int line, std::string const & str, eBaliseState state) {
      unsigned int i;
      std::string name;

      if (state == OPENING)
	i = 1;
      else
	i = 2;
      for (; i < str.length(); i++) {
	isUnexpected(infile, line, str[i]);
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

    static
    attr const              parseAttributes(std::string const & infile, int line, std::string const & str, eBaliseState state) {
      unsigned int i;
      attr attributes;

      if (state == OPENING)
	i = 1;
      else
	i = 2;
      for (; i < str.length(); i++) {
	isUnexpected(infile, line, str[i]);
	if (str[i] == ' ' || str[i] == '\t') {
	  while (str[i++] && (str[i] == ' ' || str[i] == '\t'));
	  break;
	}
	else if (str[i] == '>')
	  return attributes;
      }
      while (str[i] && str[i] != '>') {
	std::string att, attrContent;
	while (str[i] && str[i] != '=') {
	  switch (str[i]) {
	  case ' ':
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "invalid space character in attribute's name declaration"));
	  case '>':
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "an attribute must have a content"));
	  case '"':
	    isUnexpected(infile, line, str[i]);
	  default:
	    att += str[i];
	  }
	  i++;
	}
	if (str[++i] != '"')
	  throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "invalid space caracter before balise name declaration"));
	while (str[++i] && str[i] != '"') {
	  switch (str[i]) {
	  case '"':
	    break;
	  case '>':
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "an attribute must have a content"));
	  case '=':
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "an attribute must have a content"));
	  default:
	    attrContent += str[i];
	  }
	}
	if (Parser::epurString(att).empty() == true || Parser::epurString(attrContent).empty() == true)
	  throw (FormatError("incorrect xml syntax", getEmplacement(infile, line), "an attribute and his content can't be empty"));
	attributes.push_back(std::make_pair(Parser::epurString(att), Parser::epurString(attrContent)));
	while (str[i++] && (str[i] == ' ' || str[i] == '\t'));
      }
      return attributes;
    }

    static
    void                    checkConformity(std::string const & infile, std::pair<int, std::string const> line) {
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
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line.first), "invalid space caracter before balise name declaration"));
	  break;
	case '>':
	  if (chev == false)
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line.first), "'<' is needed before closing one"));
	  if (line.second[i - 1] == ' ')
	    throw (FormatError("incorrect xml syntax", getEmplacement(infile, line.first), "invalid space caracter before '>'"));
	  chev = false;
	  break;
	default:
	  car = true;
	  break;
	}
      }
      if (chev == true)
	throw (FormatError("incorrect xml syntax", getEmplacement(infile, line.first), "missing '>' at the end of expression"));
      if (quotes == true)
	throw (FormatError("incorrect xml syntax", getEmplacement(infile, line.first), "mismatched '\"'"));
    }

    static
    bool                    isUseless(std::string const &str) {
      for (unsigned int i = 0; i < str.length(); i++)
	if (str[i] != ' ')
	  return false;
      return true;
    }

    static
    void                    epurXmlDatas(std::list<std::pair<int, std::string> > & epur,
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

    static
    Xml::Balise *               getUpperNonClosed(std::list<Xml::Balise *> const & balises, std::list<Xml::Balise *>::const_iterator it) {
      Xml::Balise * tmp = 0;
      for (std::list<Xml::Balise *>::const_iterator it2 = balises.begin(); it2 != it; ++it2) {
	if ((*it2)->Xml::Balise::getAssociated() == 0)
	  tmp = *it2;
      }
      return tmp;
    }

    static
    void                    assignAssociated(std::list<Xml::Balise *> const & balises) {
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

    static
    void                    eraseBalises(Xml::Balise *bal) {
      delete bal;
    }

    std::string const           stateChar(Xml::Balise *balise) {
      if (balise->Xml::Balise::getState() == CLOSING)
	return " (CLOSING)";
      return " (OPENING)";
    }

    Xml::Xml() : ADataFormat(XML, "")
    {
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
	  std::string name = parseBaliseName(infile, it2->first, it2->second, eS);
	  if (name.empty() == true)
	    throw (FormatError("invalid xml syntax", getEmplacement(infile, it2->first), "balise name can't be empty"));
	  Balise *bal = new Balise(name, eS);
	  bal->setAttributes(parseAttributes(infile, it2->first, it2->second, eS));
	  this->_balises.push_back(bal);
	}
	else {
	  if (this->_balises.back()->getState() == CLOSING)
	    throw (FormatError("invalid content declaration", getEmplacement(infile, it2->first), "ambigous statement \"" + Parser::epurString(it2->second) + "\""));
	  this->_balises.back()->setContent(Parser::epurString(it2->second));
	}
      }
      assignAssociated(this->_balises);
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

    Xml::Balise *               Xml::Balise::getParent() const {
      return this->_parent;
    }

    void                    Xml::Balise::setParent(Balise *parent) {
      if (parent)
	this->_parent = parent;
    }

    std::string const &         Xml::Balise::getName() const {
      return this->_name;
    }

    void                    Xml::Balise::setName(std::string const & name) {
      this->_name = name;
    }

    std::string const &         Xml::Balise::getContent() const {
      return this->_content;
    }

    void                    Xml::Balise::setContent(std::string const & content) {
      this->_content = content;
    }

    std::list<Xml::Balise *> const &  Xml::Balise::getChilden() const {
      return this->_children;
    }

    void                    Xml::Balise::addChild(Balise *child) {
      this->_children.push_back(child);
    }

    Xml::Balise *               Xml::Balise::getAssociated() const {
      return this->_associated;
    }

    void                    Xml::Balise::setAssociated(Balise *balise) {
      this->_associated = balise;
    }

    eBaliseState                Xml::Balise::getState() const {
      return this->_state;
    }

    void                    Xml::Balise::setChildren(std::list<Xml::Balise *> const & children) {
      this->_children = children;
    }

    attr const & Xml::Balise::getAttributes() const {
      return this->_attributes;
    }

    std::string const  Xml::Balise::getAttrValue(std::string const & attName) const
    {
      for (std::list<std::pair<std::string const, std::string const> >::const_iterator it = this->getAttributes().begin(); it != this->getAttributes().end(); ++it)
	{
	  if (it->first.empty() == false && it->first == attName)
	    return it->second;
	}
      return "";
    }

    void Xml::Balise::setAttributes(std::list<std::pair<std::string const, std::string const> > const & attr) {
      for (std::list<std::pair <std::string const, std::string const> >::const_iterator it = attr.begin(); it != attr.end(); ++it) {
	for (std::list<std::pair <std::string const, std::string const> >::const_iterator it2 = attr.begin(); it2 != it; ++it2)
	  if (it->first == it2->first)
	    throw (FormatError("incorrect xml syntax", "balise's attribute declaration", "two attributes have the same name in one balise"));
	this->_attributes.push_back(*it);
      }
    }

    void                    Xml::generate(std::string const & outFileName) const {
      std::ofstream file(outFileName.c_str(), std::ios::in | std::ios::trunc);
      if (file) {
	for (std::list<Balise *>::const_iterator it = this->_balises.begin(); it != this->_balises.end(); ++it) {
	  file << "<";
	  if ((*it)->getState() == CLOSING)
	    file << "/";
	  file << (*it)->getName();
	  for (std::list<std::pair <std::string const, std::string const> >::const_iterator it2 = (*it)->getAttributes().begin(); it2 != (*it)->getAttributes().end(); ++it2)
	    file << " " << it2->first << "=\"" << it2->second << "\"";
	  file << ">" << std::endl;
	  if ((*it)->getState() == OPENING)
	    if ((*it)->getContent().empty() == false)
	      file << (*it)->getContent() << std::endl;
	}
	file.close();
      }
      else
	throw (FormatError("file error", "generate method", "the file " +  outFileName + " can't be openened"));
    }

    void		Xml::addBalises(std::list<Balise *> & bals)
    {
      this->_balises = bals;
    }

    void		Xml::Balise::addAttribute(std::pair<std::string, std::string> att)
    {
      this->_attributes.push_back(att);
    }

    std::list<Xml::Balise *> const & Xml::getBalises() const
    {
      return this->_balises;
    }

    Xml::Balise *	Xml::getBalisesWthName(std::string const & name) const
    {
      for (std::list<Xml::Balise *>::const_iterator it = this->_balises.begin(); it != this->_balises.end(); ++it)
	if ((*it)->getName() == name && (*it)->getState() == OPENING)
	  return *it;
      return 0;
    }

    Xml::Balise *	Xml::getBalisesWtAttribute(std::string const & name, attr const & atts) const
    {
      std::list<Xml::Balise *>::const_iterator it;
      for (it = this->_balises.begin(); it != this->_balises.end(); ++it)
	if ((*it)->getName() == name && (*it)->getState() == OPENING)
	  {
	    attr::const_iterator it2;
	    for (it2 = atts.begin(); it2 != atts.end(); ++it2)
	      {
		for (attr::const_iterator it3  = (*it)->getAttributes().begin(); it3 != (*it)->getAttributes().end(); ++it3)
		  {
		    if ((*it3).first != (*it2).first || (*it3).second != (*it2).second)
		      break;
		    return *it;
		  }
	      }
	  }
      return 0;
    }


    void		Xml::deleteBalisesWthName(std::string const & name)
    {
      for (std::list<Xml::Balise *>::iterator it = this->_balises.begin(); it != this->_balises.end(); ++it)
	if ((*it)->getName() == name)
	  {
	    it = this->_balises.erase(it);
	    return ;
	  }
    }
  }
}
