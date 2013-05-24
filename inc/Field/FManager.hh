//
//  Manager.h
//  BomberMan
//
//  Created by manour_m on 23/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan_Field_Manager__
#define __BomberMan_Field_Manager__

#include <vector>
#include <iostream>
#include <utility>
#include <list>

#include "IGameComponent.hh"

namespace BomberMan
{
    namespace Field
    {
        class Manager
        {
            unsigned int                                                        _width;
            unsigned int                                                        _height;
            ::std::vector< ::std::list<BomberMan::Field::IGameComponent *> > 	_map;
            
        public:
            Manager(unsigned int width, unsigned int height);
            ~Manager();
            
            ::std::list<BomberMan::Field::IGameComponent *> &    get(unsigned int, unsigned int);
            unsigned int                                                getWidth() const;
            unsigned int                                                getHeight() const;
        };
    }
}


#endif /* defined(__BomberMan__Manager__) */
