#include	<fmod.h>
#include	<Input.hpp>
#include	<Clock.hpp>
#include	<GameClock.hpp>
#include	"BomberGame.hh"
#include	"SoundManager.hh"
#include	"Texture3d.hpp"
#include	<iostream>

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame()
    {

      this->_manager = new Field::Manager;

      int LightPos[4] = {0,0,3,1};
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glLightiv(GL_LIGHT0,GL_POSITION,LightPos);


      Sound::SoundManager *manager = Sound::SoundManager::getInstance();
      manager->addNewSound("sounds/ambianceGame.mp3");
      // manager->playSound("sounds/ambianceGame.mp3", true);

      Display::Vector3f      vectorPosition(0, 0.0, 0);
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);

      this->_players.push_front(new Field::Player(100, 14, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));

      this->_manager->randomize(this->_players);

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

    static void updateObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock, Field::Manager *manager)
    {
      comp->update(gameClock, manager);
    }

    void	BomberGame::update(gdl::GameClock const & gameClock)
    {
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
	for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
	  for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
	    {
	      if ((*it)->isEnd() == true)
		it = this->_manager->get(x, y).erase(it);
	      else
		updateObjs(*it, gameClock, this->_manager);
	    }
      updateObjs(this->getPlayers().front(), gameClock, this->_manager);
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
	    if (y > ((this->getPlayers().front()->getX() - 110) / 220) - 3 && y < ((this->getPlayers().front()->getX() + 110) / 220) + 4 && x > ((this->getPlayers().front()->getY() - 110) / 220) - 3 && x < ((this->getPlayers().front()->getY() + 110) / 220) + 3)
	      affObjs(*it, gameClock);
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
