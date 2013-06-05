#ifndef __BOMBERMAN_HH__
#define __BOMBERMAN_HH__

#include <Game.hpp>
#include "BomberGame.hh"

namespace BomberMan
{
  namespace Core
  {
    const int	BOMBER_WIDTH	= 1920;
    const int	BOMBER_HEIGHT	= 1080;

    class BomberMan : public gdl::Game
    {
    private:
      BomberMan(BomberMan const&);
      BomberMan	&operator=(BomberMan const&);

    private:
      bool		_intro;
      bool		_menu;
      bool		_game;

    private:
      BomberGame*	_currentGame;

    private:
      void		_initializeWindow();
      void		_initializeResources() const;
      void		_initializeIntro();
      void		_initializeInput() const;
      void		_initializeEvent() const;
      void		_initializeMenu() const;

      void		_drawIntro() const;
      void		_drawMenu() const;
      void		_drawGame() const;

      void		_updateIntro();
      void		_updateMenu();
      void		_updateGame();

    private:
      void		_startMenu();
      void		_startGame();


    public:
      BomberMan();
      virtual ~BomberMan();

      virtual void	initialize(void);
      virtual void	update(void);
      virtual void	unload(void);
      virtual void	draw(void);
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
