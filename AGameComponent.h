//
//  AGameComponent.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__AGameComponent__
#define __BomberMan__AGameComponent__

#include "IGameComponent.h"

class AGameComponent : public IGameComponent
{
protected:
    float                           _x;
    float                           _y;
    Display::IAsset *               _asset;
    Display::ISound *               _sound;
    Display::IAnimation *			_animation;
    
public:
    virtual ~AGameComponent(){}
    
    virtual void                    explode(int, eDirection) = 0;
    virtual float                   getX() const;
    virtual void                    setX(float);
    virtual float                   getY() const;
    virtual void                    setY(float);
    virtual Display::IAsset *       getAsset() const;
    virtual void                    setAsset(Display::IAsset *);
    virtual Display::ISound *       getSound() const;
    virtual void                    setSound(Display::ISound *);
    virtual Display::IAnimation *   getAnimation() const;
    virtual void					setAnimation(Display::IAnimation *);
};

#endif /* defined(__BomberMan__AGameComponent__) */
