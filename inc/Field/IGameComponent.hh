#ifndef BomberMan_IGameComponent_h
#define BomberMan_IGameComponent_h

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include <iostream>

#include "FManager.hh"
#include "Enums.hh"
#include "AObject.hpp"
#include "ISound.hh"
#include "IAnimation.hh"

namespace BomberMan
{
  namespace Field
  {
    class IGameComponent
    {
    public:
      virtual ~IGameComponent(){}

      virtual void					explode(int) = 0;
      virtual void  draw(gdl::GameClock const &) = 0;
      virtual void  update(gdl::GameClock const &, Manager *) = 0;

      virtual float					getX() const = 0;
      virtual void					setX(float) = 0;
      virtual float					getY() const = 0;
      virtual void					setY(float) = 0;
      virtual Display::AObject *		getAsset() const = 0;
      virtual void					setAsset(Display::AObject *) = 0;
      virtual Display::ISound *		getSound() const = 0;
      virtual void					setSound(Display::ISound *) = 0;
      virtual Display::IAnimation *	getAnimation() const = 0;
      virtual void					setAnimation(Display::IAnimation *) = 0;
      virtual bool			operator==(IGameComponent *) = 0;
      virtual bool			isEnd() const = 0;
      virtual void                                      setExplosion(bool) = 0;
      virtual bool                                      getExplosion() const = 0;
    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class IGameComponent;
  }
}

#endif
