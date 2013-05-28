//
//  Object.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Object.hh"

namespace BomberMan
{
    namespace Field
    {
        Object::Object(float x, float y, BomberMan::Display::IAsset * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim, eObjectType objectType, eBuffType buffType, int power, int timer)
        :   _object_type(objectType), _buff_type(buffType), _power(power), _timer(timer)
        {
            this->_x = x;
            this->_y = y;
            this->_asset = asset;
            this->_sound = sound;
            this->_animation = anim;
        }
        
        Object::Object(const Object & other)
        :   _object_type(other._object_type), _buff_type(other._buff_type), _power(other._power), _timer(other._timer)
        {
            this->_x = other._x;
            this->_y = other._y;
            this->_asset = other._asset;
            this->_sound = other._sound;
            this->_animation = other._animation;
        }
        
        Object::~Object()
        {
        }
        
        eObjectType Object::getObjectType() const
        {
            return this->_object_type;
        }
        
        eBuffType   Object::getBuffType() const
        {
            return this->_buff_type;
        }
        
        void        Object::setPower(int power)
        {
            this->_power = power;
        }
        
        int         Object::getPower() const
        {
            return this->_power;
        }
        
        int         Object::getTimer() const
        {
            return this->_timer;
        }
        
        void        Object::explode(int damages, eDirection direction)
        {
            if (this->_object_type == BOMB)
            {
                // propagation++
                static_cast<void>(damages);
                static_cast<void>(direction);
            }
            // propagation
            delete this;
        }
    }
}