//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Error.hh"

Error::Error(std::string & what, std::string & where, std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

Error::~Error() throw()
{
}

std::string &   Error::getWhat() const
{
    return this->_what;
}

std::string &   Error::getWhere() const
{
    return this->_where;
}

std::string &   Error::getDetails() const
{
    return this->_details;
}