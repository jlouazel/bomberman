//
//  Error.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan_Format_Error__
#define __BomberMan_Format_Error__

#include <exception>
#include <string>

namespace BomberMan
{
    namespace DataFormat
    {
        class FormatError : public ::std::exception
        {
            ::std::string &	_what;
            ::std::string &   _where;
            ::std::string &   _details;
            
        public:
            FormatError(::std::string &, ::std::string &, ::std::string &);
            ~FormatError() throw();
            
            ::std::string &   getWhat() const;
            ::std::string &   getWhere() const;
            ::std::string &   getDetails() const;
        };
    }
}

#endif /* defined(__BomberMan__Error__) */
