//
//  IGameComponent.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_IGameComponent_h
#define BomberMan_IGameComponent_h

#include "Display.h"

class IGameComponent
{
public:
    virtual ~IGameComponent(){}

    virtual void                	explode(int) = 0;
    virtual float               	getX() const = 0;
    virtual float               	setX() = 0;
    virtual float               	getY() const = 0;
    virtual float               	setY() = 0;
    virtual Display::IAsset *   	getAsset() const = 0;
    virtual void                	setAsset(Display::IAsset *) = 0;
    virtual Display::ISound *   	getSound() const = 0;
    virtual void                	setSound(Display::ISound *) = 0;
    virtual Display::IAnimation *   getAnimation() const = 0;
    virtual void					setAnimation(Display::IAnimation *) = 0;
};

#endif
