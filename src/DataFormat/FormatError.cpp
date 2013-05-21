//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "FormatError.hh"

BomberMan::DataFormat::FormatError::FormatError(::std::string & what, ::std::string & where, ::std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

BomberMan::DataFormat::FormatError::~FormatError() throw()
{
}

::std::string &   BomberMan::DataFormat::FormatError::getWhat() const
{
    return this->_what;
}

::std::string &   BomberMan::DataFormat::FormatError::getWhere() const
{
    return this->_where;
}

::std::string &   BomberMan::DataFormat::FormatError::getDetails() const
{
    return this->_details;
}