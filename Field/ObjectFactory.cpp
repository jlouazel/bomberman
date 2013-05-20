//
//  ObjectFactory.cpp
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "ObjectFactory.hh"

ObjectFactory::ObjectFactory()
{
    this->learn(std::pair<BOMB, NONE>, new Object(BOMB, NONE, 3, 3));
    this->learn(std::pair<BUFF, LIFE>, new Object(BUFF, LIFE, 2, 10));
    this->learn(std::pair<BUFF, SPEED>, new Object(BUFF, SPEED, 1, 10));
    this->learn(std::pair<BUFF, RANGE>, new Object(BUFF, RANGE, 1, 10));
}

ObjectFactory::~ObjectFactory()
{
}

void        ObjectFactory::learn(std::pair<eObjectType, eBuffType> type, Object * object)
{
    this->_objects.insert(std::pair<type, object>);
}

Object *    ObjectFactory::create(std::pair<eObjectType, eBuffType> type) const
{
    std::map<std::pair<eObjectType, eBuffType>, Object *>::iterator it;
    
    if ((it = this->_objects.find(type)) != this->_objects.end())
        return new Object(it->second);
    else
        throw Error("Failed to create an instance of type 'Object'", "ObjectFactory::create", "Trying to create an unknown object");
}