//
// BomberMan.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:48:53 2013 julien fortin
// Last update Mon Jun  3 11:52:35 2013 Jean-Baptiste Louazel
//

#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"MenuManager.hh"
#include	"Resources.hh"
#include	"BomberMan.hh"
#include	"EndOfBomberMan.hh"

#include	<iostream>

namespace BomberMan
{
  namespace Core
  {
    BomberMan*	BomberMan::_bomberMan = 0;

    BomberMan*	BomberMan::getBomberMan()
    {
      if (!BomberMan::_bomberMan)
	BomberMan::_bomberMan = new BomberMan;
      if (!BomberMan::_bomberMan)
	throw EndOfBomberMan("BomberMan", "getBomberMan", "NULL pointer");
    return BomberMan::_bomberMan;
    }

    void		BomberMan::deleteBomberMan()
    {
      delete BomberMan::_bomberMan;
      BomberMan::_bomberMan = 0;
    }

    BomberMan::BomberMan()
    {
      this->_intro = false;
      this->_menu = false;
      this->_game = true;

      this->_currentGame = new BomberGame;
    }

    BomberMan::~BomberMan()
    {
    }

    void	BomberMan::initialize(void)
    {
      this->_initializeWindow();
      this->_initializeIntro();
      this->_initializeResources();
      this->_initializeInput();
      this->_initializeEvent();
      this->_initializeMenu();

      /* Initialisation ressources GDL */
      /* Initialise Display */
    }

    void	BomberMan::_initializeWindow()
    {
      this->window_.setTitle("Breaking Bad");
      this->window_.setHeight(BOMBER_HEIGHT);
      this->window_.setWidth(BOMBER_WIDTH);
      this->window_.create();
    }

    void	BomberMan::_initializeResources() const
    {
      Display::Resources::getResources();
    }

    void	BomberMan::_initializeIntro()
    {
      this->_intro = false; /* false */
    }

    void	BomberMan::_initializeInput() const
    {
      Input::InputManager::getInputManager()->init();
    }

    void	BomberMan::_initializeEvent() const
    {
      Event::EventManager::getEventManager();
    }

    void	BomberMan::_initializeMenu() const
    {
      Display::MenuManager::getMenuManager();
    }

    void	BomberMan::update(void)
    {
      // transformer this->input_ en EVENT;

      if (this->_intro)
	this->_updateIntro();
      else
	{
	  if (this->_menu)
	    this->_updateMenu();
	  else if (this->_game)
	    this->_updateGame();
	}
    }

    void	BomberMan::_updateIntro()
    {
      std::cout << "UPDATE INTRO\n";
      this->_intro = false;
      this->_menu = false; /* true */
      Display::MenuManager::getMenuManager()->menu(Display::Menu::MAIN);
    }

    void	BomberMan::_updateMenu()
    {
      std::cout << "UPDATE MENU\n";
      Display::MenuManager::getMenuManager()->update();
    }

    void	BomberMan::_updateGame()
    {
      if (this->_currentGame)
        {
	}
    }

    void	BomberMan::draw(void)
    {
      if (this->_intro)
	this->_drawIntro();
      else
	{
	  if (this->_menu)
	    this->_drawMenu();
	  else if (this->_game)
	    this->_drawGame();
	}
    }

    void	BomberMan::_drawIntro() const
    {
    }

    void	BomberMan::_drawMenu() const
    {
      Display::MenuManager::getMenuManager()->draw();
    }

    void	BomberMan::_drawGame() const
    {
      std::cout << "DRAW GAME" << std::endl;
    }

    void	BomberMan::unload(void)
    {
      Input::InputManager::deleteInputManager();
      Event::EventManager::deleteEventManager();
      Display::MenuManager::deleteMenuManager();
      Display::Resources::deleteResources();
    }
  }
}
