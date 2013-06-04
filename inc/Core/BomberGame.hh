//
// BomberGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 02:46:34 2013 julien fortin
// Last update Tue Jun  4 12:10:33 2013 Happy
//

#ifndef	__BOMBERGAME_HH__
#define	__BOMBERGAME_HH__

#include <list>
#include "Camera.hpp"
#include "Player.hh"
#include "FManager.hh"
#include "Empty.hh"

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
      BomberGame(std::list<Field::Player *> &);
      Field::Manager * getManager() const;
      std::list<Field::Player *> getPlayers() const;
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
