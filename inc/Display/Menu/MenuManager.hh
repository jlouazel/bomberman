//
// MenuManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 18:04:00 2013 julien fortin
// Last update Fri Jun  7 16:51:52 2013 julien fortin
//

#ifndef	__MENUMANAGER_HH__
#define	__MENUMANAGER_HH__

#include	<map>
#include	"BomberMan.hh"
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

      bool				_init;
      IMenu*				_currentMenu;
      std::map<MenuEnum::eMenu, IMenu*>	_menu;

    protected:
    public:

      void			init(Core::BomberMan* const);
      void			update();
      void			draw();
      void			menu(MenuEnum::eMenu);

      bool			isInit() const;

      IMenu*			getMenu(MenuEnum::eMenu);

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
