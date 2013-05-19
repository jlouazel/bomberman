//
//  Error.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Error.h"

Error::Error(std::string & what, std::string & where, std::string & details)
:   _what(what),
    _where(where),
    _details(details)
{
}

Error::~Error()
{
}