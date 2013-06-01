//
// BomberMan.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:48:53 2013 julien fortin
// Last update Sat Jun  1 16:54:48 2013 julien fortin
//

#include	<exception>
#include	<GL/gl.h>
#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"BomberMan.hh"
#include	<iostream>

namespace BomberMan
{
  BomberMan*	BomberMan::_bomberMan = 0;

  BomberMan*	BomberMan::getBomberMan()
  {
    if (!BomberMan::_bomberMan)
      BomberMan::_bomberMan = new BomberMan;
    if (!BomberMan::_bomberMan)
      throw std::exception(); //
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
    this->_game = false;

    this->_currentGame = 0;
  }

  BomberMan::~BomberMan()
  {
  }

  void	BomberMan::initialize(void)
  {
    this->_initializeWindow();
    this->_initializeIntro();
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

  void	BomberMan::_initializeIntro()
  {
    this->_intro = true;
    /* Thread video intro */
  }

  void	BomberMan::_initializeInput() const
  {
    Input::InputManager::getInputManager();
    Input::InputManager::init();
  }

  void	BomberMan::_initializeEvent() const
  {
    Event::EventManager::getEventManager();
  }

  void	BomberMan::_initializeMenu() const
  {
    //Menu::MenuManager::getMenuManager();
  }

  void	BomberMan::update(void)
  {
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

    // Condition Intro fini
    {
      this->_intro = false;

      // Lancer le menu d'accueil
      {

      }
    }
  }

  void	BomberMan::_updateMenu()
  {
    std::cout << "UPDATE INTRO\n";
  }

  void	BomberMan::_updateGame()
  {
    std::cout << "UPDATE INTRO\n";
    // if (this->_currentGame)
    //   {}
  }

  void	BomberMan::draw(void)
  {
  }

  void	BomberMan::unload(void)
  {
    Input::InputManager::deleteInputManager();
    Event::EventManager::deleteEventManager();
  }
}
