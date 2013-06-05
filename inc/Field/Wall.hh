#ifndef __BomberMan__Wall__
#define __BomberMan__Wall__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>

#include "AGameComponent.hh"
#include "Enums.hh"

namespace BomberMan
{
    namespace Field
    {
        class Wall : public AGameComponent
        {
            bool	_breakable;
            int		_pv;

        public:
            Wall(bool breakable, int pv, float x, float y, Display::AObject * asset, Display::ISound * sound = 0, Display::IAnimation * anim = 0);
            ~Wall();

            void	explode(int, eDirection);
            int     getPv() const;
            void    setPv(int);
	  void  draw(gdl::GameClock const & gameClock);
          void  update(gdl::GameClock const & gameClock);
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
