//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "EventError.hh"

EventError::EventError(std::string & what, std::string & where, std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

EventError::~EventError() throw()
{
}

std::string &   EventError::getWhat() const
{
    return this->_what;
}

std::string &   EventError::getWhere() const
{
    return this->_where;
}

std::string &   EventError::getDetails() const
{
    return this->_details;
}