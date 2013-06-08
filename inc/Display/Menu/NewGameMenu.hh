//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  8 01:11:33 2013 julien fortin
//

#ifndef	__NEWGAMEMENU_HH__
#define	__NEWGAMEMENU_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class NewGameMenu : public IMenu
    {
    private:
      NewGameMenu(NewGameMenu const&);
      NewGameMenu	&operator=(NewGameMenu const&);

      Menu*			_menu;
      unsigned int		_cursor;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_hover;

      void	_cursorMove();

      static const unsigned int	_nbOnglet = 2;

    protected:
    public:
      virtual ~NewGameMenu();
      NewGameMenu(Core::BomberMan* const);

      virtual void		update();
      virtual void		draw();
      virtual MenuEnum::eMenu	getType() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class NewGameMenu;
  }
}
#endif
