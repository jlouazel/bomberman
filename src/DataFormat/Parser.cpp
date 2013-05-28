#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "Parser.hh"

std::string				BomberMan::DataFormat::Parser::concatStr(std::string const & s1, std::string const & s2, std::string const & s3) {
  std::stringstream ss;

    ss << s1 << s2 << s3;
    return ss.str();
}

std::string const 			BomberMan::DataFormat::Parser::typeToString(eFormat format) {
  switch (format) {
  case XML:
    return "xml";
  case JSON:
    return "json";
  default:
    return "unknown";
  }
  return 0;
}

bool						BomberMan::DataFormat::Parser::checkExtend(eFormat format, std::string const & filename) {
  std::vector< std::string> trunc = splitString(filename, ".");
  if (trunc.back() == typeToString(format))
    return true;
  return false;
}

BomberMan::DataFormat::IDataFormat *				BomberMan::DataFormat::Parser::getAppropriateContainer(std::string const &filename) {
  std::vector< std::string>  parsedName = splitString(filename, ".");
  if (parsedName.back() == "xml")
    return new Xml(filename);
    throw (FormatError("invalid format", "parser", "the format \"" + parsedName.back() + "\" is not managed by the parser"));
  return 0;
}

std::vector< std::string>	BomberMan::DataFormat::Parser::splitString(std::string const &s, std::string const &delim) {
  std::vector< std::string>	vec;
  std::string			str = s, tmp;
  size_t			i = 0;

  while (str.size() > 0 && (i = str.find_first_of(delim)) != std::string::npos)
    {
      tmp = str.substr(0, i);
      if (tmp.size())
	vec.push_back(tmp);
      str = str.substr(i + 1, str.size());
    }
  tmp = str;
  if (tmp.size())
    vec.push_back(str);
  return vec;
}

static bool 				ifEnd(std::string const & str, unsigned int i) {
  for (; i < str.length(); i++) {
    switch (str[i]) {
    case ' ':
      break;
    case '\t':
      break;
    default:
      return false;
    }
  }
  return true;
}

std::string const 			BomberMan::DataFormat::Parser::epurString(std::string const & str) {
  bool car = false;
  std::string ret;
  for (unsigned int i = 0; i < str.length(); i++) {
    switch (str[i]) {
    case ' ':
      if (ifEnd(str, i) == true ||car == false)
	break;
      ret += str[i];
      break;
    case '\t':
      if (ifEnd(str, i) == true || car == false)
	break;
      ret += str[i];
      break;
    default:
      car = true;
      ret += str[i];
      break;
    }
  }
  return ret;
}
