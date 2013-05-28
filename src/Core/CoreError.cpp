//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "CoreError.hh"

BomberMan::Core::CoreError::CoreError(::std::string & what, ::std::string & where, ::std::string & details)
:   _what(what), _where(where), _details(details)
{
}

BomberMan::Core::CoreError::~CoreError() throw()
{
}

::std::string & BomberMan::Core::CoreError::getWhat() const
{
    return this->_what;
}

::std::string & BomberMan::Core::CoreError::getWhere() const
{
    return this->_where;
}

::std::string & BomberMan::Core::CoreError::getDetails() const
{
    return this->_details;
}