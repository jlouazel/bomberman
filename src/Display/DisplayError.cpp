//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "DisplayError.hh"

namespace BomberMan
{
    namespace Display
    {
        DisplayError::DisplayError(std::string what, std::string where, std::string details)
        :   _what(what), _where(where), _details(details)
        {
        }
        
        DisplayError::~DisplayError() throw()
        {
        }
        
        std::string	DisplayError::getWhat() const
        {
            return this->_what;
        }
        
        std::string	DisplayError::getWhere() const
        {
            return this->_where;
        }
        
        std::string	DisplayError::getDetails() const
        {
            return this->_details;
        }
    }
}