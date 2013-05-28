//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "FormatError.hh"

namespace BomberMan
{
    namespace DataFormat
    {
        FormatError::FormatError(std::string what, std::string where, std::string details)
        :   _what(what), _where(where), _details(details)
        {
        }
        
        FormatError::~FormatError() throw()
        {
        }
        
        std::string   FormatError::getWhat() const
        {
            return this->_what;
        }
        
        std::string   FormatError::getWhere() const
        {
            return this->_where;
        }
        
        std::string   FormatError::getDetails() const
        {
            return this->_details;
        }
    }
}