//
// MenuManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 18:26:57 2013 julien fortin
// Last update Sun Jun  2 20:17:06 2013 julien fortin
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
      this->_menu[Menu::MAIN] = new MainMenu;
      this->_currentMenu = 0;
    }

    MenuManager::~MenuManager()
    {
      if (this->_currentMenu)
	delete this->_currentMenu;
      this->_currentMenu = 0;
    }

    void	MenuManager::update()
    {
      if (this->_currentMenu)
	this->_currentMenu->update();
    }

    void	MenuManager::draw()
    {
      if (MenuManager::getMenuManager()->_currentMenu)
	MenuManager::getMenuManager()->_currentMenu->draw();
    }

    void	MenuManager::menu(Menu::eMenu menu)
    {
      if (this->_menu.count(menu) > 0)
	this->_currentMenu = this->_menu[menu];
    }
  }
}
