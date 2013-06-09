#include	"Gif.hpp"
#include	"BomberMan.hh"
#include	"BomberOptions.hh"
#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"MenuManager.hh"
#include        "SoundManager.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberMan::BomberMan() : gdl::Game()
    {
      this->_intro = true;
      this->_menu = false;
      this->_game = false;
      this->_loading = false;
      this->_currentGame = 0;
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
      this->_initializeSound();
      this->_initializeIntro();
      this->_initializeInput();
      this->_initializeEvent();
      this->_initializeMenu();
      this->_initializeOptions();
      this->_initializeLoading();
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
      this->_introVideo = new Display::Video("./resources/videos/IntroBomberLight.avi",
					     "./resources/sounds/IntroBomberLight.mp3");
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

    void	BomberMan::_initializeSound() const
    {
      Sound::SoundManager::getInstance();
    }

    void	BomberMan::_initializeOptions() const
    {
      BomberOptions::getOptions();
    }

    void	BomberMan::_initializeLoading() const
    {
      Display::Gif::getGif();
    }

    void	BomberMan::update(void)
    {
      Input::InputManager::getInputManager()->treatInput(this->input_);
      if (this->_intro)
	this->_updateIntro();
      else if (this->_loading)
	this->_updateLoading();
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
      if (this->_introVideo->isFinished() || this->input_.isKeyDown(gdl::Keys::Escape))
	{
	  this->_introVideo->stopSound();
	  Sound::SoundManager::getInstance()->playSound("./resources/sounds/musicIntro2.mp3", true);
	  this->startMenu(Display::MenuEnum::MAIN);
	}
    }

    void	BomberMan::_updateMenu()
    {
      Display::MenuManager::getMenuManager()->update();
    }

    void	BomberMan::_updateGame()
    {
      if (this->_currentGame)
	this->_currentGame->update(this->gameClock_);
    }

    void	BomberMan::_updateLoading()
    {
      std::cout << "UpdateLoad" << std::endl;
      if (this->_currentGame)
	if (this->_currentGame->isLoaded())
	  {
	    this->_loading = false;
	    this->_game = true;
	  }
    }

    void	BomberMan::draw(void)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.0, 0.0, 0.0, 1.0f);
      glClearDepth(1.0f);
      glMatrixMode(GL_MODELVIEW);
      if (this->_intro)
	this->_drawIntro();
      else if (this->_loading)
	this->_drawLoading();
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
      this->_introVideo->draw();
    }

    void	BomberMan::_drawLoading() const
    {
      std::cout << "DrawLoad" << std::endl;
      Display::Gif::getGif()->draw();
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
    }

    void	BomberMan::startMenu(Display::MenuEnum::eMenu menu)
    {
      this->_intro = false;
      this->_menu = true;
      this->_game = false;
      this->_loading = false;
      Display::MenuManager::getMenuManager()->menu(menu);
    }

    void	BomberMan::startGame()
    {
      this->_intro = false;
      this->_menu = false;
      this->_game = false;
      this->_loading = true;
      this->_currentGame = new BomberGame;//(BomberOptions::getOptions()->isQuickGame());
    }
  }
}
