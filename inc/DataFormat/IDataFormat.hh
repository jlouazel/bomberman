#ifndef	IDATAFORMAT_HH__
#define	IDATAFORMAT_HH__

#include <map>
#include <fstream>

#include "eFormat.hh"

namespace BomberMan
{
    namespace DataFormat
    {
        class IDataFormat {
        public:
            virtual ~IDataFormat() {};
            
            virtual std::map<int, std::string const> const &    getContent() const = 0;
            virtual eFormat           						   	getFormat() const = 0;
            virtual std::ifstream const &                       getInFile() const = 0;
            virtual void                                        generate(std::string const &) const = 0;
        };
    }
}

#endif
