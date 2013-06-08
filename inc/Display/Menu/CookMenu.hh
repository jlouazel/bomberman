//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  8 12:34:41 2013 julien fortin
//

#ifndef	__COOKMENU_HH__
#define	__COOKMENU_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class CookMenu : public IMenu
    {
    private:
      CookMenu(CookMenu const&);
      CookMenu	&operator=(CookMenu const&);

      Menu*                     _menu;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_player;
      std::map<unsigned int, IOnglet*>	_back;
      IOnglet*	_left;
      IOnglet*	_right;

      unsigned int	_current;
      unsigned int	_cursor;

    protected:
    public:
      virtual ~CookMenu();
      CookMenu(Core::BomberMan* const);

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
    class CookMenu;
  }
}
#endif
