//
//  Player.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Player.hh"

BomberMan::Field::Player::Player(int pv, float speed, int max, int set, float x, float y, BomberMan::Display::IAsset * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
:   _pv(pv),
    _speed(speed),
    _nb_bomb_max(max),
    _nb_bomb_set(set)
{
    this->_x = x;
    this->_y = y;
    this->_animation = anim;
    this->_sound = sound;
    this->_asset = asset;
    this->_bomb = new Object(0.0, 0.0, 0, 0, 0, BOMB, NONE, 3, 3);
}

BomberMan::Field::Player::~Player()
{
    delete this->_bomb;
}

void                        BomberMan::Field::Player::move()
{
}

void                        BomberMan::Field::Player::setBomb()
{
}

void                        BomberMan::Field::Player::acquireObject()
{
}

void                        BomberMan::Field::Player::run()
{
}

int                         BomberMan::Field::Player::getNbBombMax() const
{
    return this->_nb_bomb_max;
}

void                        BomberMan::Field::Player::setNbBombMax(int nb)
{
    this->_nb_bomb_max = nb;
}

int                         BomberMan::Field::Player::getNbBombSet() const
{
    return this->_nb_bomb_set;
}

float                       BomberMan::Field::Player::getSpeed() const
{
    return this->_speed;
}

void                        BomberMan::Field::Player::setSpeed(float speed)
{
    this->_speed = speed;
}

BomberMan::Field::Object *  BomberMan::Field::Player::getBomb() const
{
    return this->_bomb;
}

int                         BomberMan::Field::Player::getPv() const
{
    return this->_pv;
}

void                        BomberMan::Field::Player::setPv(int pv)
{
    this->_pv = pv;
}

void                        BomberMan::Field::Player::explode(int damages, eDirection direction)
{
  static_cast<void>(direction);
    this->setPv(this->_pv - damages);
    // animation dmg
    if (this->_pv <= 0)
        ::std::cout << "J'suis mort" << ::std::endl;
}