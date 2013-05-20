#ifndef	ADATAFORMAT_HH__
#define	ADATAFORMAT_HH__

#include <map>
#include <string>
#include <fstream>

#include "eFormat.hh"
#include "IDataFormat.hh"

class ADataFormat : public IDataFormat {
protected:
  eFormat							_format;
  std::ifstream						_infile;
  std::map<int, std::string const>	_content;

  explicit ADataFormat(eFormat, std::string const &);

public:
  virtual ~ADataFormat();

  eFormat 									getFormat() const;
  std::ifstream const & 					getInFile() const;
  std::map<int, std::string const> const & 	getContent() const;
  virtual void								generate(std::string const &) const = 0;
};

#endif
