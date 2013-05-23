//
//  ObjectFactory.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include <utility>

#include "ObjectFactory.hh"
#include "FieldError.hh"

BomberMan::Field::ObjectFactory::ObjectFactory()
{
    this->learn(::std::pair<eObjectType, eBuffType>(BOMB, NONE), new Object(BOMB, NONE, 3, 3));
    this->learn(::std::pair<eObjectType, eBuffType>(BUFF, LIFE), new Object(BUFF, LIFE, 2, 10));
    this->learn(::std::pair<eObjectType, eBuffType>(BUFF, SPEED), new Object(BUFF, SPEED, 1, 10));
    this->learn(::std::pair<eObjectType, eBuffType>(BUFF, RANGE), new Object(BUFF, RANGE, 1, 10));
}

BomberMan::Field::ObjectFactory::~ObjectFactory()
{
}

void                        BomberMan::Field::ObjectFactory::learn(::std::pair<eObjectType, eBuffType> type, Object * object)
{
    this->_objects.insert(::std::pair< ::std::pair<eObjectType, eBuffType>, Object *>(type, object));
}

BomberMan::Field::Object *  BomberMan::Field::ObjectFactory::create(::std::pair<eObjectType, eBuffType> type) const
{
    if (this->_objects.find(type) != this->_objects.end())
        return new Object(*(this->_objects.find(type))->second);
    else
        throw FieldError(::std::string("Failed to create an instance of type 'Object'"), ::std::string("ObjectFactory::create"), ::std::string("Trying to create an unknown object"));
}