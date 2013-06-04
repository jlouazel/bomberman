//
// BomberGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 02:46:34 2013 julien fortin
// Last update Tue Jun  4 01:34:28 2013 Happy
//

#ifndef	__BOMBERGAME_HH__
#define	__BOMBERGAME_HH__

#include <list>
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
      // Object score
      // camera + bordel opengl

    protected:
    public:
      ~BomberGame();
      BomberGame(/*vector de player*/);
      Field::Manager * getManager() const;
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
