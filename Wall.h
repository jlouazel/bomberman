//
//  Wall.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Wall__
#define __BomberMan__Wall__

#include "AGameComponent.h"

class Wall : public AGameComponent
{
    bool	_breakable;
    int		_pv;
    
public:
    Wall();
    ~Wall();
    
    void	explode(int);
};

#endif /* defined(__BomberMan__Wall__) */
