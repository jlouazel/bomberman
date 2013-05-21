//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "EventError.hh"

BomberMan::Event::EventError::EventError(::std::string & what, ::std::string & where, ::std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

BomberMan::Event::EventError::~EventError() throw()
{
}

::std::string &   BomberMan::Event::EventError::getWhat() const
{
    return this->_what;
}

::std::string &   BomberMan::Event::EventError::getWhere() const
{
    return this->_where;
}

::std::string &   BomberMan::Event::EventError::getDetails() const
{
    return this->_details;
}