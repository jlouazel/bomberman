#ifndef	__BOMBERGAME_HH__
#define	__BOMBERGAME_HH__

#include	<list>
#include	<GameClock.hpp>
#include	"Camera.hpp"
#include	"Player.hh"
#include	"FManager.hh"
#include	"Empty.hh"

namespace BomberMan
{
  namespace Core
  {
    class BomberGame
    {
    private:
      Field::Manager *			_manager;
      std::list<Field::Player *>	_players;
      std::list<Display::Camera *>      _camera;
      // Object score
      // camera + bordel opengl

    protected:
    public:
      ~BomberGame();
      BomberGame();

      void				update(gdl::GameClock const&);
      void				draw(gdl::GameClock const&) const;

      Field::Manager*			getManager() const;
      std::list<Field::Player *>	getPlayers() const;

      void updateCamera(gdl::GameClock const & gameClock, gdl::Input & input);
    };
  }
}
#else
namespace BomberMan
{
  namespace Core
  {
    class BomberGame;
  }
}
#endif
