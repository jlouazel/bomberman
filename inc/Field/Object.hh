#ifndef __BOMBERMAN__OBJECT__
#define __BOMBERMAN__OBJECT__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"

#include "Vector.hpp"
#include "Enums.hh"
#include "AObject.hpp"
#include "IAnimation.hh"
#include "ISound.hh"
#include "FManager.hh"
#include "Empty.hh"

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
      float	      _runningTimer;

    public:
      Object(float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim, eObjectType, eBuffType, int, int);
      Object(const Object &);
      ~Object();

      eObjectType getObjectType() const;
      eBuffType   getBuffType() const;
      int         getPower() const;
      void        setPower(int);
      int         getTimer() const;
      void	  setX(float);
      void	  setY(float);
      void        explode(int);
      void	  bombExplode(int, eDirection, Manager *);
      bool	  checkCase(int x, int y, Manager *manager);
      void  draw(gdl::GameClock const & gameClock);
      void  update(gdl::GameClock const & gameClock, Manager *);
      void  initialize();
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
