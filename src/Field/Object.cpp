//
//  Object.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Object.hh"

BomberMan::Field::Object::Object(eObjectType objectType, eBuffType buffType, int power, int timer)
:   _object_type(objectType),
    _buff_type(buffType),
    _power(power),
    _timer(timer)
{
    /*this->_asset = asset;
    this->_sound = sound;
    this->_animation = anim;*/
}

BomberMan::Field::Object::Object(const Object & other)
:   _object_type(other._object_type),
    _buff_type(other._buff_type),
    _power(other._power),
    _timer(other._timer)
{
}

BomberMan::Field::Object::~Object()
{
}

BomberMan::Field::eObjectType BomberMan::Field::Object::getObjectType() const
{
    return this->_object_type;
}

BomberMan::Field::eBuffType   BomberMan::Field::Object::getBuffType() const
{
    return this->_buff_type;
}

void        BomberMan::Field::Object::setPower(int power)
{
    this->_power = power;
}

int         BomberMan::Field::Object::getPower() const
{
    return this->_power;
}

int         BomberMan::Field::Object::getTimer() const
{
    return this->_timer;
}

void        BomberMan::Field::Object::explode(int damages, eDirection direction)
{
  static_cast<void>(damages);
  static_cast<void>(direction);
}
