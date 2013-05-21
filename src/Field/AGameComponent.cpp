//
//  AGameComponent.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "AGameComponent.hh"

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

IAsset *       AGameComponent::getAsset() const
{
    return this->_asset;
}

void                    AGameComponent::setAsset(IAsset * asset)
{
    this->_asset = asset;
}

ISound *       AGameComponent::getSound() const
{
    return this->_sound;
}

void                    AGameComponent::setSound(ISound * sound)
{
    this->_sound = sound;
}

IAnimation *   AGameComponent::getAnimation() const
{
    return this->_animation;
}

void                    AGameComponent::setAnimation(ISound *animation)
{
    this->_animation = animation;
}