#ifndef	__BOMBERGAME_HH__
#define	__BOMBERGAME_HH__

#include	<map>
#include	<list>
#include	<GameClock.hpp>
#include	"Camera.hpp"
#include	"Player.hh"
#include	"Texture2d.hpp"
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
      std::map<std::string, Display::AObject *>	_infos;
      // Object score
      // camera + bordel opengl

      bool	_loading;

    protected:
    public:
      ~BomberGame();
      BomberGame();

      bool				isLoaded() const;

      void				update(gdl::GameClock const&);
      void				draw(gdl::GameClock const&) const;
      void				drawForPlayer2D(gdl::GameClock const&, int) const;
      void				drawForPlayer3D(gdl::GameClock const&, int) const;

      Field::Manager*			getManager() const;
      std::list<Field::Player *>	getPlayers() const;
      void				save();

      void updateCamera(gdl::GameClock const & gameClock, gdl::Input & input);
      void eventPlayer();
      bool                checkIfIWin(int) const;
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
