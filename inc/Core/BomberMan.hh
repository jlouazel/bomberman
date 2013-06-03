//
// BomberMan.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:44:06 2013 julien fortin
// Last update Mon Jun  3 16:34:30 2013 Happy
//

#ifndef	__BOMBERMAN_HH__
#define	__BOMBERMAN_HH__

#include	<Game.hpp>
#include	<Camera.hpp>
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
      BomberMan();
      BomberMan(BomberMan const&);
      BomberMan	&operator=(BomberMan const&);

    private:
      static BomberMan*	_bomberMan;
      Display::Camera                camera_;

    private:
      bool	_intro;
      bool	_menu;
      bool	_game;

    private:
      BomberGame*		_currentGame;

      //std::map<IPlayer*, IController*>	_playerController;

    private:
      void	_updateIntro();
      void	_updateMenu();
      void	_updateGame();

      void	_initializeWindow();
      void	_initializeResources() const;
      void	_initializeIntro();
      void	_initializeInput() const;
      void	_initializeEvent() const;
      void	_initializeMenu() const;

      void	_drawIntro() const;
      void	_drawMenu() const;
      void	_drawGame() const;

    protected:
    public:
      virtual ~BomberMan();

      virtual void	initialize(void);
      virtual void	update(void);
      virtual void	unload(void);
      virtual void	draw(void);

      static BomberMan*	getBomberMan();
      static void	deleteBomberMan();
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
