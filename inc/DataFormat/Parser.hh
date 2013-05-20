#ifndef	PARSER_HH__
#define	PARSER_HH__

#include <vector>
#include <string>
#include "IDataFormat.hh"
#include "eFormat.hh"

class Parser {
private:
  Parser();
  ~Parser();

public:
  static std::string const			typeToString(eFormat);
  static bool						checkExtend(eFormat, std::string const &);
  static IDataFormat *				getAppropriateContainer(std::string const &);
  static std::vector<std::string>	splitString(std::string const&, std::string const&);
  static std::string const 			epurString(std::string const &);
};

#endif
