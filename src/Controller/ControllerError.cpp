//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "ControllerError.hh"

BomberMan::ControllerError::ControllerError(::std::string & what, ::std::string & where, ::std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

BomberMan::ControllerError::~ControllerError() throw()
{
}

::std::string & BomberMan::ControllerError::getWhat() const
{
    return this->_what;
}

::std::string & BomberMan::ControllerError::getWhere() const
{
    return this->_where;
}

::std::string & BomberMan::ControllerError::getDetails() const
{
    return this->_details;
}