//
//  Empty.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include "AGameComponent.h"

class Empty : public AGameComponent
{
public:
    Empty();
    ~Empty();
    
    void	explode(int);
};

#endif /* defined(__BomberMan__Empty__) */
