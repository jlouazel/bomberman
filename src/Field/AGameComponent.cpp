//
//  AGameComponent.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "AGameComponent.hh"

float                               BomberMan::Field::AGameComponent::getX() const
{
    return this->_x;
}

void                                BomberMan::Field::AGameComponent::setX(float x)
{
    this->_x = x;
}

float                               BomberMan::Field::AGameComponent::getY() const
{
    return this->_y;
}

void                                BomberMan::Field::AGameComponent::setY(float y)
{
    this->_y = y;
}

BomberMan::Display::IAsset *        BomberMan::Field::AGameComponent::getAsset() const
{
    return this->_asset;
}

void                                BomberMan::Field::AGameComponent::setAsset(Display::IAsset * asset)
{
    this->_asset = asset;
}

BomberMan::Display::ISound *        BomberMan::Field::AGameComponent::getSound() const
{
    return this->_sound;
}

void                                BomberMan::Field::AGameComponent::setSound(Display::ISound * sound)
{
    this->_sound = sound;
}

BomberMan::Display::IAnimation *    BomberMan::Field::AGameComponent::getAnimation() const
{
    return this->_animation;
}

void                                BomberMan::Field::AGameComponent::setAnimation(Display::IAnimation *animation)
{
    this->_animation = animation;
}