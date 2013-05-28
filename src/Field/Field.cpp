//
//  Field.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include <sys/types.h>
#include <list>

#include "IGameComponent.hh"
#include "FManager.hh"

namespace BomberMan
{
    namespace Field
    {
        Manager::Manager(unsigned int width, unsigned int height)
        :   _width(width), _height(height), _map(width * height, std::list<IGameComponent *>())
        {
        }

        Manager::~Manager()
        {
        }

        std::list<IGameComponent *> &   Manager::get(unsigned int x, unsigned int y)
        {
            unsigned int    pos;

            pos = y * this->_width + x;
            return this->_map[pos];
        }

        unsigned int                    Manager::getWidth() const
        {
            return this->_width;
        }

        unsigned int                    Manager::getHeight() const
        {
            return this->_height;
        }
    }
}
