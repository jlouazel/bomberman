#include	"BomberMan.hh"
#include	"Resources.hh"
#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"MenuManager.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberMan::BomberMan() : gdl::Game()
    {
      this->_intro = true;
      this->_menu = false;
      this->_game = false;
    }

    BomberMan::~BomberMan()
    {
      if (this->_currentGame)
	delete this->_currentGame;
      this->unload();
    }

    void	BomberMan::initialize()
    {
      this->_initializeWindow();
      this->_initializeIntro();
      this->_initializeInput();
      this->_initializeEvent();
      this->_initializeMenu();
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
    }

    void	BomberMan::_initializeEvent() const
    {
      Event::EventManager::getEventManager();
    }

    void	BomberMan::_initializeInput() const
    {
      Input::InputManager::getInputManager()->init();
    }

    void	BomberMan::_initializeMenu() const
    {
      Display::MenuManager::getMenuManager()->init(const_cast<BomberMan* const>(this));
    }

    void	BomberMan::update(void)
    {
      Input::InputManager::getInputManager()->treatInput(this->input_);
      if (this->_intro)
	this->_updateIntro();
      else
	{
	  if (this->_menu)
	    this->_updateMenu();
	  else if (this->_game)
	    this->_updateGame();
	}
      Event::EventManager::getEventManager()->cleanEvent();
    }

    void	BomberMan::_updateIntro()
    {
      if (this->_intro) // On stop l'intro direct pour passer sur le menu;
	this->startMenu(Display::MenuEnum::MAIN);
    }

    void	BomberMan::_updateMenu()
    {
      // if (this->_menu) // On stop le menu direct ppur rentrer sur le jeu;
      // 	{
      // 	  this->_startGame();
      // 	  return;
      // 	}
      Display::MenuManager::getMenuManager()->update();
    }

    void	BomberMan::_updateGame()
    {
      if (this->_currentGame)
	this->_currentGame->update(this->gameClock_);
    }

    void	BomberMan::draw(void)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
      glClearDepth(1.0f);
      glMatrixMode(GL_MODELVIEW);
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
      if (this->_currentGame)
	this->_currentGame->draw(this->gameClock_);
    }

    void	BomberMan::unload(void)
    {
      //Input::InputManager::deleteInputManager();
      // Event::EventManager::deleteEventManager();
      // Display::MenuManager::deleteMenuManager();
      //Display::Resources::deleteResources();
    }

    void	BomberMan::startMenu(Display::MenuEnum::eMenu menu)
    {
      this->_intro = false;
      this->_menu = true;
      this->_game = false;
      Display::MenuManager::getMenuManager()->menu(menu);
    }

    void	BomberMan::startGame()
    {
      this->_intro = false;
      this->_menu = false;
      this->_game = true;
      this->_currentGame = new BomberGame;
    }
  }
}
