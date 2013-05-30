#include "CoreError.hh"

namespace BomberMan
{
  namespace Engine
  {
    CoreError::CoreError(std::string what, std::string where, std::string details)
      :   _what(what), _where(where), _details(details)
    {
    }

    CoreError::~CoreError() throw()
    {
    }

    std::string	CoreError::getWhat() const
    {
      return this->_what;
    }

    std::string	CoreError::getWhere() const
    {
      return this->_where;
    }

    std::string	CoreError::getDetails() const
    {
      return this->_details;
    }
  }
}
