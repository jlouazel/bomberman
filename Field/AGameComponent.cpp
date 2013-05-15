//
//  AGameComponent.cpp
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#include "AGameComponent.hh"

IAsset *	AGameComponent::getAsset() const
{
    return this->_asset;
}

ISound *	AGameComponent::getDefaultSound() const
{
    return this->_default_sound;
}

float		AGameComponent::getX() const
{
    return this->_x;
}

float		AGameComponent::getY() const
{
    return this->_y;
}