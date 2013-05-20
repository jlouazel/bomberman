//
//  AGameComponent.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "AGameComponent.h"

float                   AGameComponent::getX() const
{
    return this->_x;
}

void                    AGameComponent::setX(float x)
{
    this->_x = x;
}

float                   AGameComponent::getY() const
{
    return this->_y;
}

void                    AGameComponent::setY(float y)
{
    this->_y = y;
}

Display::IAsset *       AGameComponent::getAsset() const
{
    return this->_asset;
}

void                    AGameComponent::setAsset(Display::IAsset * asset)
{
    this->_asset = asset;
}

Display::ISound *       AGameComponent::getSound() const
{
    return this->_sound;
}

void                    AGameComponent::setSound(Display::ISound * sound)
{
    this->_sound = sound;
}

Display::IAnimation *   AGameComponent::getAnimation() const
{
    return this->_animation;
}

void                    AGameComponent::setAnimation(Display::ISound *animation)
{
    this->_animation = animation;
}