#include	<algorithm>
#include	<Clock.hpp>
#include	<Game.hpp>
#include	<GameClock.hpp>
#include	<Input.hpp>
#include	"IGameComponent.hh"
#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"KeyBoardManager.hh"
#include	"MenuManager.hh"
#include	"Resources.hh"
#include	"BomberMan.hh"
#include	"EndOfBomberMan.hh"
#include	"Empty.hh"
#include	"Player.hh"
#include	"AObject.hpp"
#include	"Texture3d.hpp"
#include	<iostream>

namespace BomberMan
{
  namespace Core
  {
    BomberMan::~BomberMan()
    {
      if (this->_currentGame)
	delete this->_currentGame;
    }

    void    BomberMan::_initializeWindow()
    {
      this->window_.setTitle("Breaking Bad");
      this->window_.setHeight(BOMBER_HEIGHT);
      this->window_.setWidth(BOMBER_WIDTH);
      this->window_.create();
    }

    void	BomberMan::initialize()
    {
      std::list<Field::Player *> player;
      Display::Vector3f      vectorPosition(0, 0.0, 0);
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);

      player.push_front(new Field::Player(100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
      this->_initializeWindow();
      Input::InputManager::getInputManager()->init();
      this->_currentGame = new BomberGame(player);
      std::list<Field::Player *>::iterator it = player.begin();
      for (; it != player.end(); ++it)
	(*it)->initialize();
    }

    static void	updateObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->update(gameClock);
    }

    void	BomberMan::update(void)
    {
      Input::Controller::KeyBoardManager::getKeyBoardManager()->treatInput(this->input_);

      // this->_currentGame->updateCamera(gameClock_, input_);
      for (unsigned int y = 0; y != this->_currentGame->getManager()->Field::Manager::getHeight(); y++)
      	for (unsigned int x = 0; x != this->_currentGame->getManager()->Field::Manager::getWidth(); x++)
      	  for (std::list<Field::IGameComponent *>::iterator it = this->_currentGame->getManager()->Field::Manager::get(x, y).begin(); it != this->_currentGame->getManager()->Field::Manager::get(x, y).end(); ++it)
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
  }
}
