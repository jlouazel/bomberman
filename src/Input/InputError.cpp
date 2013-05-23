//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "InputError.hh"

namespace BomberMan
{
  namespace Input
  {
    InputError::InputError(::std::string what, ::std::string where, ::std::string details)
      :   _what(what),
	  _where(where),
	  _details(details)
    {
    }

    InputError::~InputError() throw()
    {
    }

    ::std::string		InputError::getWhat() const
    {
      return this->_what;
    }

    ::std::string		InputError::getWhere() const
    {
      return this->_where;
    }

    ::std::string		InputError::getDetails() const
    {
      return this->_details;
    }
  }
}
