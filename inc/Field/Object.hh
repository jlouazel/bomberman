#ifndef __BOMBERMAN__OBJECT__
#define __BOMBERMAN__OBJECT__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"

#include "Enums.hh"
#include "AObject.hpp"
#include "IAnimation.hh"
#include "ISound.hh"
#include "FManager.hh"

namespace BomberMan
{
  namespace Field
  {
    class Object : public AGameComponent
    {
      eObjectType		_object_type;
      eBuffType		_buff_type;
      int             _power;
      int             _timer;

    public:
      Object(float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim, eObjectType, eBuffType, int, int);
      Object(const Object &);
      ~Object();

      eObjectType getObjectType() const;
      eBuffType   getBuffType() const;
      int         getPower() const;
      void        setPower(int);
      int         getTimer() const;
      void        explode(int, eDirection);

      void  draw(gdl::GameClock const & gameClock);
      void  update(gdl::GameClock const & gameClock, Manager *);
      bool  operator==(IGameComponent *);
    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Object;
  }
}

#endif /* defined(__BomberMan__Object__) */
