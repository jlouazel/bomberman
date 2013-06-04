#include	"BomberGame.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame(std::list<Field::Player *> &players)
    {
      this->_manager = new Field::Manager;
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
