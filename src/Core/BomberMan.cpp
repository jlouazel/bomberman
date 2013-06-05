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
      this->_initializeResources();
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

    void	BomberMan::_initializeResources() const
    {
      Display::Resources::getResources();
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
      Display::MenuManager::getMenuManager();
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
	this->_startMenu();
    }

    void	BomberMan::_updateMenu()
    {
      if (this->_menu) // On stop le menu direct ppur rentrer sur le jeu;
	{
	  this->_startGame();
	  return;
	}
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
      Input::InputManager::deleteInputManager();
      Event::EventManager::deleteEventManager();
      Display::MenuManager::deleteMenuManager();
      Display::Resources::deleteResources();
    }

    void	BomberMan::_startMenu()
    {
      this->_intro = false;
      this->_game = false;
      this->_menu = true;
      Display::MenuManager::getMenuManager()->menu(Display::Menu::MAIN);
    }

    void	BomberMan::_startGame()
    {
      this->_intro = false;
      this->_menu = false;
      this->_game = true;
      this->_currentGame = new BomberGame;
    }
  }
}



    /*
    static void	updateObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->update(gameClock);
    }

    void	BomberMan::update(void)
    {

      // this->_currentGame->updateCamera(gameClock_, input_);
      std::cout << "X = " << this->_currentGame->getPlayers().front()->getX() / 220 << std::endl;
      std::cout << "Y = "<< this->_currentGame->getPlayers().front()->getY() / 220 << std::endl;
      for (unsigned int y = 0; y != this->_currentGame->getManager()->Field::Manager::getHeight(); y++)
      	for (unsigned int x = 0; x != this->_currentGame->getManager()->Field::Manager::getWidth(); x++)
      	  for (std::list<Field::IGameComponent *>::iterator it = this->_currentGame->getManager()->Field::Manager::get(x, y).begin(); it != this->_currentGame->getManager()->Field::Manager::get(x, y).end(); ++it)
	    if (y > (this->_currentGame->getPlayers().front()->getX() / 220) - 10 && y < (this->_currentGame->getPlayers().front()->getX() / 220) + 7 && x > (this->_currentGame->getPlayers().front()->getY() / 220) - 10 && x < (this->_currentGame->getPlayers().front()->getY() / 220) + 7)
	      updateObjs(*it, gameClock_);
      updateObjs(this->_currentGame->getPlayers().front(), gameClock_);
    }

    void	BomberMan::draw(void)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
      glClearDepth(1.0f);
      glMatrixMode(GL_MODELVIEW);
      this->_drawGame();
      Event::EventManager::getEventManager()->cleanEvent();
    }

    static void	affObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock, gdl::Input input)
    {
      comp->draw(gameClock, input);
    }

    void	BomberMan::_drawGame() const
    {
      // this->_currentGame->getManager()->Field::Manager::get(0, 0).front()->getAsset()->draw();
      for (unsigned int y = 0; y != this->_currentGame->getManager()->Field::Manager::getHeight(); y++)
	for (unsigned int x = 0; x != this->_currentGame->getManager()->Field::Manager::getWidth(); x++)
	  for (std::list<Field::IGameComponent *>::iterator it = this->_currentGame->getManager()->Field::Manager::get(x, y).begin(); it != this->_currentGame->getManager()->Field::Manager::get(x, y).end(); ++it)
	    if (y > (this->_currentGame->getPlayers().front()->getX() / 220) - 10 && y < (this->_currentGame->getPlayers().front()->getX() / 220) + 7 && x > (this->_currentGame->getPlayers().front()->getY() / 220) - 10 && x < (this->_currentGame->getPlayers().front()->getY() / 220) + 7)
	      affObjs(*it, gameClock_, input_);

      // for (std::list<Field::Player *>::iterator it2 = this->_currentGame->getPlayers().begin(); it2 != this->_currentGame->getPlayers().end(); ++it2)
      // 	{
      // 	  std::cout << "KIKOU J'aime la police" << std::endl;
      // 	  affObjs(*it2, gameClock_, input_);
      // 	  std::cout << "Dans mon slip" << std::endl;
      // 	}
      affObjs(this->_currentGame->getPlayers().front(), gameClock_, input_);
    }

    void	BomberMan::unload()
    {
    }
    */
