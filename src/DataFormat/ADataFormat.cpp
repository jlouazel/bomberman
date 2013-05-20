#include <map>
#include <string>
#include <fstream>
#include <utility>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ADataFormat.hh"
#include "Parser.hh"
#include "Error.hh"

ADataFormat::ADataFormat(eFormat format, std::string const & infile)
:   _format(format),
    _infile(infile.c_str()) {
  struct stat st;
  if (stat(infile.c_str(), &st) == 0) {
      if(st.st_mode & S_IFDIR)
          throw (Error("invalid format", "parser", "\"" + infile + "\" is a directory"));
      else if(st.st_mode & S_IFREG) {
	if (this->_infile.is_open() == false)
	  throw (Error("invalid file", "parser", "unable to open \"" + infile + "\", maybe you don't have the permission to open it"));
	if (Parser::checkExtend(format, infile) == false)
	  throw (Error("invalid file type", "parser", "this is not a " + Parser::typeToString(format) + " file"));
	char c;
	int line = 1;
	std::string recup;
	while (this->_infile.good())
	  {
	    c = this->_infile.get();
	    if (this->_infile.good()) {
	      if (c == '\n') {
		this->_content.insert(std::make_pair(line++, recup));
		recup.clear();
	      }
	      else
		recup += c;
	    }
	  }
      }
      else
	throw (Error("invalid format", "parser", "\"" + infile + "\" is an unknown format file"));
    }
  else
    throw (Error("unknown file", "parser", "the file \"" + infile + "\" doesn't exists"));
}

ADataFormat::~ADataFormat() {
  this->_infile.close();
}

eFormat 									ADataFormat::getFormat() const {
  return this->_format;
}

std::ifstream const &						ADataFormat::getInFile() const {
  return this->_infile;
}

std::map<int, std::string const> const &	ADataFormat::getContent() const {
  return this->_content;
}
