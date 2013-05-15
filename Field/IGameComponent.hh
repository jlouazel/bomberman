//
//  IGameComponent.h
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#ifndef BomberMan_IGameComponent_h
#define BomberMan_IGameComponent_h

#include "Field.hh"

class IGameComponent
{
public:
    virtual ~IGameComponent(){}
    
    virtual void		explode() = 0;
    virtual IAsset *	getAsset() const = 0;
    virtual ISound *	getDefaultSound() const = 0;
    virtual	float		getX() const = 0;
    virtual float		getY() const = 0;
};

#endif
