//
//  Field.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Field__
#define __BomberMan__Field__

#include <vector>
#include <list>

#include "IGameComponent.h"
#include "Player.h"
#include "Wall.h"
#include "Empty.h"
#include "Object.h"

namespace Field
{
    enum eObjectType    { BOMB, BUFF };
    enum eBuffType      { NONE, LIFE, SPEED, RANGE };
    
    class Field
    {
        unsigned int								_width;
        unsigned int								_height;
        std::vector<std::list<IGameComponent *> > &	_map;
        
    public:
        Field(unsigned int width, unsigned int height);
        ~Field();
        
        std::list<IGameComponent *>	&	get(unsigned int, unsigned int);
        unsigned int					getWidth() const;
        unsigned int                    getHeight() const;
    };
}

#endif /* defined(__BomberMan__Field__) */
