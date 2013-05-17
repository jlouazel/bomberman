//
//  Field.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Field.h"

Field::Field(unsigned int width, unsigned int height)
:   _width(width),
    _height(height),
    _map(width * height, std::list<IGameComponent *>)
{
}

Field::~Field()
{
}

std::list<IGameComponent *> &   Field::get(unsigned int x, unsigned int y)
{
    unsigned int    pos;
    
    pos = y * this->_width + x;
    return this->_map[pos];
}

unsigned int                    Field::getWidth() const
{
    return this->_width;
}

unsigned int                    Field::getHeight() const
{
    return this->height;
}
