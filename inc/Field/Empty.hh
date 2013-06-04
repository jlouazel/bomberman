#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"

#include "AObject.hpp"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
  namespace Field
    {
      class Empty : public AGameComponent
        {
        public:
	  Empty(float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
	  ~Empty();

	  void	explode(int, eDirection);
	  void	draw(gdl::GameClock const & gameClock, gdl::Input & input);
	  void  update(gdl::GameClock const & gameClock);
        };
    }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Empty;
  }
}

#endif
