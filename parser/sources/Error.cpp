#include <string>
#include "Error.hh"

Error::Error(std::string const & what, std::string const & where, std::string const & details)
  : _what(what),
    _where(where),
    _details(details)
{
}

Error::~Error() throw()
{
}

std::string const &   Error::getWhat() const
{
  return (this->_what);
}

std::string const &   Error::getWhere() const
{
  return (this->_where);
}

std::string const &   Error::getDetails() const
{
  return (this->_details);
}
