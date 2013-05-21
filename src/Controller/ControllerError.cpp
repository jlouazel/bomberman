//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "ControllerError.hh"

BomberMan::Input::ControllerError::ControllerError(::std::string what, ::std::string where, ::std::string details)
:   _what(what),
    _where(where),
    _details(details)
{
}

BomberMan::Input::ControllerError::~ControllerError() throw()
{
}

::std::string   BomberMan::Input::ControllerError::getWhat() const
{
    return this->_what;
}

::std::string   BomberMan::Input::ControllerError::getWhere() const
{
    return this->_where;
}

::std::string   BomberMan::Input::ControllerError::getDetails() const
{
    return this->_details;
}