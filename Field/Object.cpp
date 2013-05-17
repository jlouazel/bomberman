//
//  Object.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

Field::eObjectType	Object::getObjectType() const
{
    return this->_object_type;
}

Field::eBuffType    Object::getBuffType() const
{
    return this->_buff_type;
}

int                 Object::getPower() const
{
    return this->_power;
}

int                 Object::getTimer() const
{
    return this->_timer;
}

void                Object::explode(int damages)
{
    
}