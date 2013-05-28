//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "CoreError.hh"

namespace BomberMan
{
    namespace Core
    {
        CoreError::CoreError(std::string & what, std::string & where, std::string & details)
        :   _what(what), _where(where), _details(details)
        {
        }
        
        CoreError::~CoreError() throw()
        {
        }
        
        std::string & CoreError::getWhat() const
        {
            return this->_what;
        }
        
        std::string & CoreError::getWhere() const
        {
            return this->_where;
        }
        
        std::string & CoreError::getDetails() const
        {
            return this->_details;
        }
    }
}