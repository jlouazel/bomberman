//
// BomberGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 02:46:34 2013 julien fortin
// Last update Sat Jun  1 23:19:06 2013 julien fortin
//

#ifndef	__BOMBERGAME_HH__
#define	__BOMBERGAME_HH__

namespace BomberMan
{
  namespace Core
  {
    class BomberGame
    {
    private:
      // map;
      // Object score
      // playerList = Si on veut jouer en solo ou a plusieurs
      // camera + bordel opengl

      protected:
      public:
      ~BomberGame();
      BomberGame(/*vector de player*/);
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