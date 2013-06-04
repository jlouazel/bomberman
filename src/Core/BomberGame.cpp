//
// BomberGame.cpp for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 02:50:41 2013 julien fortin
// Last update Tue Jun  4 12:10:26 2013 Happy
//

#include	"BomberGame.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame(std::list<Field::Player *> &players)
    {
      // Field::Manager::initInstance(1, 1);
      this->_manager = new Field::Manager(10, 10);
      this->_players = players;
      std::list<Field::Player *>::iterator it = this->_players.begin();
      for (; it != this->_players.end(); ++it)
	{
	  this->_camera.push_back(new Display::Camera());
	  (*it)->setCamera(this->_camera.back());
	}
    }

    BomberGame::~BomberGame()
    {
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
