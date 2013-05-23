//
//  Empty.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Empty.hh"

BomberMan::Field::Empty::Empty(float x, float y, BomberMan::Display::IAsset * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
{
    this->_x = x;
    this->_y = y;
    this->_asset = asset;
    this->_sound = sound;
    this->_animation = anim;
}

BomberMan::Field::Empty::~Empty()
{
}

void    BomberMan::Field::Empty::explode(int damages, BomberMan::Field::eDirection direction)
{
  static_cast<void>(damages);
  static_cast<void>(direction);
    // propagation
}