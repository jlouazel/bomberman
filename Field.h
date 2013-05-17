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
    enum eObjectType { BOMB, BUFF };
    enum eBuffType { LIFE, SPEED, RANGE };
    
    class Field
    {
        std::vector<std::vector<std::list<IGameComponent *> > >	_map;
        
    public:
        std::list<IGameComponent *>	&	getGameComponent(unsigned int, unsigned int);
        std::list<IGameComponent *> &	operator[][](unsigned int, unsigned int);
    };
}

#endif /* defined(__BomberMan__Field__) */
