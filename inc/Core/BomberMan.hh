#ifndef __BOMBERMAN_HH__
#define __BOMBERMAN_HH__

#include <Game.hpp>
#include "BomberGame.hh"

#define BOMBER_WIDTH 1920
#define BOMBER_HEIGHT 1080

namespace BomberMan
{
  namespace Core
  {
    class   BomberMan : public gdl::Game
    {
    private:
      BomberGame *_currentGame;

    private:
      void      _drawGame() const;
      void	_initializeWindow();

    public:
      BomberMan() : gdl::Game() {}
      ~BomberMan();
      void	initialize();
      void	update();
      void	draw();
      void	unload();
    };
  }
}

#else
namespace BomberMan
{
    namespace Core
    {
      class BomberMan;
    }
}

#endif
