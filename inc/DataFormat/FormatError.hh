#ifndef __BomberMan_Format_Error__
#define __BomberMan_Format_Error__

#include <exception>
#include <string>

namespace BomberMan
{
    namespace DataFormat
    {
        class FormatError : public std::exception
        {
            std::string	_what;
            std::string	_where;
            std::string	_details;

        public:
            FormatError(std::string, std::string, std::string);
            ~FormatError() throw();

            std::string	getWhat() const;
            std::string	getWhere() const;
            std::string	getDetails() const;
        };
    }
}

#else
namespace BomberMan
{
  namespace DataFormat
  {
    class FormatError;
  }
}

#endif
