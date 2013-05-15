//
//  Field.cpp
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#include "Field.hh"

Field::Field()
{
    
}

Field::~Field()
{
    
}

std::list<IGameComponent *> &	Field::getGameComponent(int x, int y) const
{
    return this->_map;
}