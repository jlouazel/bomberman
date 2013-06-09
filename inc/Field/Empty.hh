#ifndef __BOMBERMAN__EMPTY__
#define __BOMBERMAN__EMPTY__

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
	  bool		_isGround;
	  gdl::Clock   *_clock;
	  int		_frame;
	  int		_playerTakeDomage;
	  int		_idBomb;
        public:
	  Empty(bool isGround, float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
	  ~Empty();

	  void	explode(int, Manager *, int);
	  void	draw(gdl::GameClock const &);
	  void	draw2d(gdl::GameClock const &);
	  void  update(gdl::GameClock const &, Manager *);
	  bool  operator==(IGameComponent *);
	  int	getPlayerTakeDomage() const;
	  void	setFrame(int);
	  int	getIdBomb() const;
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
