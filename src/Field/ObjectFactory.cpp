//
//  ObjectFactory.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "ObjectFactory.hh"
#include "FieldError.hh"

BomberMan::Field::ObjectFactory::ObjectFactory()
{
    this->learn(::std::pair<BomberMan::Field::BOMB, BomberMan::Field::NONE>, new Object(BomberMan::Field::BOMB, BomberMan::Field::NONE, 3, 3));
    this->learn(::std::pair<BomberMan::Field::BUFF, BomberMan::Field::LIFE>, new Object(BomberMan::Field::BUFF, BomberMan::Field::LIFE, 2, 10));
    this->learn(::std::pair<BomberMan::Field::BUFF, BomberMan::Field::SPEED>, new Object(BomberMan::Field::BUFF, BomberMan::Field::SPEED, 1, 10));
    this->learn(::std::pair<BomberMan::Field::BUFF, BomberMan::Field::RANGE>, new Object(BomberMan::Field::BUFF, BomberMan::Field::RANGE, 1, 10));
}

BomberMan::Field::ObjectFactory::~ObjectFactory()
{
}

void        BomberMan::Field::ObjectFactory::learn(::std::pair<BomberMan::Field::eObjectType, BomberMan::Field::eBuffType> type, Object * object)
{
    this->_objects.insert(::std::pair<type, object>);
}

BomberMan::Field::Object *    ObjectFactory::create(::std::pair<eObjectType, eBuffType> type) const
{
    ::std::map<::std::pair<eObjectType, eBuffType>, Object *>::iterator it;
    
    if ((it = this->_objects.find(type)) != this->_objects.end())
        return new Object(*it->second);
    else
        throw FieldError("Failed to create an instance of type 'Object'", "ObjectFactory::create", "Trying to create an unknown object");
}