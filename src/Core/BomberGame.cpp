#include	<Input.hpp>
#include	<Clock.hpp>
#include	<GameClock.hpp>
#include	"BomberGame.hh"
#include	"Texture3d.hpp"

#include	<iostream>

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame()
    {
      // Field::Manager::initInstance(1, 1);
      this->_manager = new Field::Manager;


        Display::Vector3f      vectorPosition(0, 0.0, 0);
        Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
        Display::Vector3f      vectorRot(0.0, 0.0, 0.0);


	this->_players.push_front(new Field::Player(100, 14, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));

	std::list<Field::Player *>::iterator it = this->_players.begin();
      for (; it != this->_players.end(); ++it)
	{
	  this->_camera.push_back(new Display::Camera());
	  (*it)->setCamera(this->_camera.back());
	}

      it = this->_players.begin();
      for (; it != this->_players.end(); ++it)
	(*it)->initialize();
    }

    BomberGame::~BomberGame()
    {
    }

    static void updateObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->update(gameClock);
    }

    void	BomberGame::update(gdl::GameClock const & gameClock)
    {
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
        for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
          for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
            if (y > (this->getPlayers().front()->getX() / 220) - 10 && y < (this->getPlayers().front()->getX() / 220) + 7 && x > (this->getPlayers().front()->getY() / 220) - 10 && x < (this->getPlayers().front()->getY() / 220) + 7)
              updateObjs(*it, gameClock);
      updateObjs(this->getPlayers().front(), gameClock);
    }

    static void affObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->draw(gameClock);
    }

    void	BomberGame::draw(gdl::GameClock const & gameClock) const
    {
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
        for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
          for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
            if (y > (this->getPlayers().front()->getX() / 220) - 10 && y < (this->getPlayers().front()->getX() / 220) + 7 && x > (this->getPlayers().front()->getY() / 220) - 10 && x < (this->getPlayers().front()->getY() / 220) + 7)
              affObjs(*it, gameClock);

      // for (std::list<Field::Player *>::iterator it2 = this->_currentGame->getPlayers().begin(); it2 != this->_currentGame->getPlayers().end(); ++it2)
    //        {
    //          std::cout << "KIKOU J'aime la police" << std::endl;
    //          affObjs(*it2, gameClock_, input_);
    //          std::cout << "Dans mon slip" << std::endl;
    //        }
      affObjs(this->getPlayers().front(), gameClock);
    }

    void	BomberGame::updateCamera(gdl::GameClock const & gameClock, gdl::Input & input)
    {
      // this->_camera.update(gameClock, input);
    }

    Field::Manager * BomberGame::getManager() const
    {
      return this->_manager;
    }

    std::list<Field::Player *> BomberGame::getPlayers() const
    {
      return this->_players;
    }
  }
}
