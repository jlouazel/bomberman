//
// MenuManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 18:04:00 2013 julien fortin
// Last update Sat Jun  1 22:31:58 2013 julien fortin
//

#ifndef	__MENUMANAGER_HH__
#define	__MENUMANAGER_HH__

#include	<map>
#include	"MenuEnum.hh"
#include	"IMenu.hh"

namespace BomberMan
{
  namespace Display
  {
    class MenuManager
    {
    private:
      ~MenuManager();
      MenuManager();
      MenuManager(MenuManager const&);
      MenuManager	&operator=(MenuManager const&);

    private:
      static MenuManager*		_menuManager;

      IMenu*				_currentMenu;
      std::map<Menu::eMenu, IMenu*>	_menu;

    protected:
    public:

      void			update();
      void			draw();
      void			menu(Menu::eMenu);

      static MenuManager*	getMenuManager();
      static void		deleteMenuManager();
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class MenuManager;
  }
}
#endif
