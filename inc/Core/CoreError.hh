#ifndef __BomberMan_Core_Error__
#define __BomberMan_Core_Error__

#include <exception>
#include <string>

namespace BomberMan
{
    namespace Engine
    {
        class CoreError : public std::exception
        {
            std::string	_what;
            std::string	_where;
            std::string	_details;

        public:
            CoreError(std::string, std::string, std::string);
            ~CoreError() throw();

            std::string	getWhat() const;
            std::string	getWhere() const;
            std::string	getDetails() const;
        };
    }
}

#else
namespace BomberMan
{
  namespace Engine
  {
    class CoreError;
  }
}

#endif
