//
//  Player.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void    Player::move()
{
}

void    Player::setBomb()
{
}

void    Player::acquireObject()
{
}

void    Player::run()
{
}

int     Player::getNbBombMax() const
{
    return this->_nb_bomb_max;
}

void    Player::setNbBombMax(int nb)
{
    this->_nb_bomb_max = nb;
}

int     Player::getNbBombSet() const
{
    return this->_nb_bomb_set;
}

float   Player::getSpeed() const
{
    return this->_speed;
}

void    Player::setSpeed(float speed)
{
    this->_speed = speed;
}

int		Player::getPV() const
{
    return this->_pv;
}

void    Player::setPv(int pv)
{
    this->_pv = pv;
}

void    Player::explode(int damages, Field::eDirection direction)
{
    this->setPv(this->_pv - damages);
    // animation dmg
    if (this->_pv <= 0)
        std::cout << "J'suis mort" << std::endl;
    // propagation
}
