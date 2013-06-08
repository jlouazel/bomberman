#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"

#include "FManager.hh"
#include "AObject.hpp"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
  namespace Field
    {
      class Empty : public AGameComponent
        {
	private:
	  Display::AObject *_textureExplosion;
	  bool		   _explosion;
	  gdl::Clock   *_clock;
	  int		_frame;
	  int		_playerTakeDomage;
        public:
	  Empty(float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
	  ~Empty();

	  void	explode(int);
	  void	draw(gdl::GameClock const &);
	  void  update(gdl::GameClock const &, Manager *);
	  bool  operator==(IGameComponent *);
	  int	getPlayerTakeDomage() const;
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
