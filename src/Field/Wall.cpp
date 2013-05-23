//
//  Wall.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Wall.hh"

BomberMan::Field::Wall::Wall()
{
}

BomberMan::Field::Wall::~Wall()
{
}

int     BomberMan::Field::Wall::getPv() const
{
    return this->_pv;
}

void    BomberMan::Field::Wall::setPv(int pv)
{
    this->_pv = pv;
}

void    BomberMan::Field::Wall::explode(int damages, eDirection direction)
{
   static_cast<void>(direction);
   if (this->_breakable == true)
    {
        this->_pv -= damages;
        // changement d'asset (breches?)
        if (this->_pv < 0)
            ::std::cout << "Je casse" << ::std::endl;
    }
    // propagation
}