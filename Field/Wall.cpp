//
//  Wall.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Wall.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

int     Wall::getPv() const
{
    return this->_pv;
}

void    Wall::setPv(int pv)
{
    this->_pv = pv;
}

void    Wall::explode(int damages, eDirection direction)
{
    if (this->_breakable == true)
    {
        this->_pv -= damages;
        // changement d'asset (breches?)
        if (this->_pv < 0)
            std::cout << "Je casse" << std::endl;
    }
    // propagation
}