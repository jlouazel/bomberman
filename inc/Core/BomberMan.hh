#ifndef __BOMBERMAN_HH__
#define __BOMBERMAN_HH__

#include	<Game.hpp>
#include	"Video.hpp"
#include	"MenuEnum.hh"
#include	"BomberGame.hh"

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
      Display::Video*		_introVideo;
      Display::Video*		_creditVideo;

    private:
      void		_initializeWindow();
      void		_initializeIntro();
      void		_initializeInput() const;
      void		_initializeEvent() const;
      void		_initializeMenu() const;
      void		_initializeSound() const;
      void		_initializeOptions() const;

      void		_drawIntro() const;
      void		_drawMenu() const;
      void		_drawGame() const;

      void		_updateIntro();
      void		_updateMenu();
      void		_updateGame();

    public:
      BomberMan();
      virtual ~BomberMan();

      virtual void	initialize(void);
      virtual void	update(void);
      virtual void	unload(void);
      virtual void	draw(void);

      void		startGame();
      void		startMenu(Display::MenuEnum::eMenu);
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
