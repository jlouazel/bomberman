//
//  AGameComponent.h
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#ifndef __BomberMan__AGameComponent__
#define __BomberMan__AGameComponent__

#include "IGameComponent.hh"

class AGameComponent : public IGameComponent
{
protected:
    float		_x;
    float		_y;
    IAsset *	_asset;
    ISound *	_default_sound;
    
public:
    virtual ~AGameComponent(){}
    
    virtual void		explode() = 0;
    virtual IAsset *	getAsset() const;
    virtual ISound *	getDefaultSound() const;
    virtual	float		getX() const;
    virtual float		getY() const;
};

#endif /* defined(__BomberMan__AGameComponent__) */
