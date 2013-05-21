//
//  IGameComponent.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_IGameComponent_h
#define BomberMan_IGameComponent_h

#include <iostream>

#include "Display.hh"
#include "Enums.hh"

class IGameComponent
{
public:
    virtual ~IGameComponent(){}

    virtual void                	explode(int, eDirection) = 0;
    virtual float               	getX() const = 0;
    virtual void                    setX(float) = 0;
    virtual float               	getY() const = 0;
    virtual void                    setY(float) = 0;
    virtual IAsset *   	getAsset() const = 0;
    virtual void                	setAsset(IAsset *) = 0;
    virtual ISound *   	getSound() const = 0;
    virtual void                	setSound(ISound *) = 0;
    virtual IAnimation *   getAnimation() const = 0;
    virtual void					setAnimation(IAnimation *) = 0;
};

#endif
