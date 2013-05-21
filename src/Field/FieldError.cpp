//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "FieldError.hh"

BomberMan::Field::FieldError::FieldError(::std::string & what, ::std::string & where, ::std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

BomberMan::Field::FieldError::~FieldError() throw()
{
}

::std::string &   BomberMan::Field::FieldError::getWhat() const
{
    return this->_what;
}

::std::string &   BomberMan::Field::FieldError::getWhere() const
{
    return this->_where;
}

::std::string &   BomberMan::Field::FieldError::getDetails() const
{
    return this->_details;
}