//
//  Object.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Object__
#define __BomberMan__Object__

#include "AGameComponent.h"

class Object : public AGameComponent
{
    eObjectType		_object_type;
    eBuffType		_buff_type;
    int				_power;
    ???				_timer;
    
public:
    Object();
    ~Object();
    
    eObjectType     getObjectType() const;
    eBuffType		getBuffType() const;
    int             getPower() const;
    ???             getTimer() const;
    void			explode(int)
};

#endif /* defined(__BomberMan__Object__) */
