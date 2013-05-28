//
//  Error.h
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan_Field_Error__
#define __BomberMan_Field_Error__

#include <exception>
#include <string>

namespace BomberMan
{
    namespace Field
    {
        class FieldError : public std::exception
        {
            std::string _what;
            std::string _where;
            std::string _details;
            
        public:
            FieldError(std::string, std::string, std::string);
            ~FieldError() throw();
            
            std::string getWhat() const;
            std::string getWhere() const;
            std::string getDetails() const;
        };
    }
}

#endif /* defined(__BomberMan__Error__) */
