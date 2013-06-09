//
// MenuManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 18:26:57 2013 julien fortin
// Last update Sun Jun  9 22:55:14 2013 julien fortin
//

#include	"Menus.hh"
#include	"MenuManager.hh"
#include	"EndOfBomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    MenuManager*	MenuManager::_menuManager = 0;

    MenuManager*	MenuManager::getMenuManager()
    {
      if (!MenuManager::_menuManager)
	MenuManager::_menuManager = new MenuManager;
      if (!MenuManager::_menuManager)
	throw Core::EndOfBomberMan("MenuManager", "getMenuManager", "NULL pointer");
      return MenuManager::_menuManager;
    }

    void		MenuManager::deleteMenuManager()
    {
      delete MenuManager::_menuManager;
      MenuManager::_menuManager = 0;
    }

    MenuManager::MenuManager()
    {
      this->_currentMenu = 0;
      this->_init = false;
    }

    MenuManager::~MenuManager()
    {
      if (this->_currentMenu)
	delete this->_currentMenu;
      this->_currentMenu = 0;
    }

    void	MenuManager::init(Core::BomberMan* const core)
    {
      if (!this->_init)
	{
	  this->_menu[MenuEnum::MAIN] = new MainMenu(core);
	  this->_menu[MenuEnum::NEWGAME] = new NewGameMenu(core);
	  this->_menu[MenuEnum::CUSTOMIZE] = new CustomizeMenu(core);
	  this->_menu[MenuEnum::COOK] = new CookMenu(core);
	  this->_menu[MenuEnum::QUIT] = new Quit;
	  this->_menu[MenuEnum::MAPOPTIONS] = new MapOptionsMenu(core);
	  this->_menu[MenuEnum::PAUSE] = new PauseMenu(core);
	  this->_menu[MenuEnum::LOADING] = new Loading;
	  this->_menu[MenuEnum::LAUNCHGAME] = new LaunchGame(core);
	  this->_menu[MenuEnum::RESUME] = new Resume(core);
	  this->_menu[MenuEnum::CREDITS] = new CreditsMenu(core);
	  this->_menu[MenuEnum::SURRENDER] = new Surrender(core);
	  this->_menu[MenuEnum::LOAD] = new LoadGame(core);
	  this->_menu[MenuEnum::OPTIONS] = new Options(core);
	  this->_init = true;
	}
    }

    void	MenuManager::update()
    {
      if (this->_currentMenu)
	this->_currentMenu->update();
    }

    void	MenuManager::draw()
    {
      if (this->_currentMenu)
	this->_currentMenu->draw();
    }

    void	MenuManager::menu(MenuEnum::eMenu menu)
    {
      if (this->_menu.count(menu) > 0)
	this->_currentMenu = this->_menu[menu];
    }

    IMenu	*MenuManager::getMenu(MenuEnum::eMenu menu)
    {
      if (this->_menu.count(menu) > 0)
        return this->_menu[menu];
      return 0;
    }

    bool	MenuManager::isInit() const
    {
      return this->_init;
    }
  }
}
