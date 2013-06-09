#ifndef __BOMBERMAN__WALL__
#define __BOMBERMAN__WALL__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"
#include "Enums.hh"
#include "Object.hh"
#include "FManager.hh"

namespace BomberMan
{
  namespace Field
  {
    class Wall : public AGameComponent
    {
      bool	_breakable;
      int	_pv;
      Object *	_content;
      int	_whoDestroyedMe;

    public:
      Wall(bool breakable, int pv, float x, float y, Display::AObject * asset, Display::ISound * sound = 0, Display::IAnimation * anim = 0);
      ~Wall();

      void	explode(int, Manager *, int);
      int     getPv() const;
      void    setPv(int);
      void  draw(gdl::GameClock const & gameClock);
      void  update(gdl::GameClock const & gameClock, Manager *);
      bool  operator==(IGameComponent *other);
      bool	isBreakable() const;
      Object *	getContent() const;
      void	setContent(Object *);
      int	getWhoDestroyedMe() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Wall;
  }
}

#endif
