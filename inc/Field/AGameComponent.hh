//
//  AGameComponent.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__AGameComponent__
#define __BomberMan__AGameComponent__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>
#include "IGameComponent.hh"
#include "AObject.hpp"

namespace BomberMan
{
  namespace Field
  {
    class AGameComponent : public IGameComponent
    {
    protected:
      float					_x;
      float					_y;
      Display::AObject *			_asset;
      Display::ISound *		_sound;
      Display::IAnimation *	_animation;

    public:
      virtual ~AGameComponent(){}

      virtual void					explode(int, eDirection) = 0;
      virtual void  draw(gdl::GameClock const & gameClock) = 0;
      virtual void  update(gdl::GameClock const & gameClock) = 0;
      virtual float					getX() const;
      virtual void					setX(float);
      virtual float					getY() const;
      virtual void					setY(float);
      virtual Display::AObject *		getAsset() const;
      virtual void					setAsset(Display::AObject *);
      virtual Display::ISound *		getSound() const;
      virtual void					setSound(Display::ISound *);
      virtual Display::IAnimation *   getAnimation() const;
      virtual void					setAnimation(Display::IAnimation *);

    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class AGameComponent;
  }
}

#endif /* defined(__BomberMan__AGameComponent__) */
