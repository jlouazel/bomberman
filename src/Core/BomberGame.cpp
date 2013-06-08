#include	<fmod.h>
#include	<Input.hpp>
#include	<Clock.hpp>
#include	<GameClock.hpp>
#include	"BomberGame.hh"
#include	"SoundManager.hh"
#include	"Texture3d.hpp"
#include	"Texture2d.hpp"
#include	"Wall.hh"
#include	"Player.hh"
#include	<iostream>

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame()
    {
      Sound::SoundManager *manager = Sound::SoundManager::getInstance();
      manager->addNewSound("resources/sounds/ambianceGame.mp3");
      manager->playSound("resources/sounds/ambianceGame.mp3", true);

      this->_manager = new Field::Manager;

      int LightPos[4] = {0,0,3,1};
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glLightiv(GL_LIGHT0,GL_POSITION,LightPos);


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

      Display::Vector3f      vectorPosition_(0, 0, 0);
      Display::Vector3f      vectorLen_(1.5, 2, 0.0);
      Display::Vector3f      vectorRot_(0.0, 0.0, 0.0);
      Display::Vector3f      vectorPosition2_(0, 70, 0);
      Display::Vector3f      vectorLen2_(20, 40, 0.0);
      Display::Vector3f      vectorPosition3_(12, 87, 0);
      Display::Vector3f      vectorLen3_(5, 10, 0.0);
      this->_infos["barrel"] = new Display::Texture2d("images/MMbarrel.png", vectorPosition_, vectorRot_, vectorLen_);
      this->_infos["barrel"]->initialize();
      this->_infos["wall"] = new Display::Texture2d("images/MMcuve.png", vectorPosition_, vectorRot_, vectorLen_);
      this->_infos["wall"]->initialize();
      this->_infos["floor"] = new Display::Texture2d("images/MMfloor.png", vectorPosition_, vectorRot_, vectorLen_);
      this->_infos["floor"]->initialize();
      this->_infos["player"] = new Display::Texture2d("images/MMplayer.png", vectorPosition_, vectorRot_, vectorLen_);
      this->_infos["player"]->initialize();
      this->_infos["walter"] = new Display::Texture2d("images/WWmenu.png", vectorPosition2_, vectorRot_, vectorLen2_);
      this->_infos["walter"]->initialize();
      this->_infos["fiole0"] = new Display::Texture2d("images/Fiole0.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole0"]->initialize();
      this->_infos["fiole10"] = new Display::Texture2d("images/Fiole10.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole10"]->initialize();
      this->_infos["fiole20"] = new Display::Texture2d("images/Fiole20.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole20"]->initialize();
      this->_infos["fiole30"] = new Display::Texture2d("images/Fiole30.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole30"]->initialize();
      this->_infos["fiole40"] = new Display::Texture2d("images/Fiole40.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole40"]->initialize();
      this->_infos["fiole50"] = new Display::Texture2d("images/Fiole50.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole50"]->initialize();
      this->_infos["fiole60"] = new Display::Texture2d("images/Fiole60.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole60"]->initialize();
      this->_infos["fiole70"] = new Display::Texture2d("images/Fiole70.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole70"]->initialize();
      this->_infos["fiole80"] = new Display::Texture2d("images/Fiole80.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole80"]->initialize();
      this->_infos["fiole90"] = new Display::Texture2d("images/Fiole90.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole90"]->initialize();
      this->_infos["fiole100"] = new Display::Texture2d("images/Fiole100.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["fiole100"]->initialize();
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

      float	startx = 88;
      float	starty = 85;

      Field::Player * player = this->getPlayers().front();

      for (int y = -5; y != 5; y++)
      	{
      	  for (int x = -5; x != 5; x++)
      	    {
      	      Field::Player * tmp = this->getPlayers().front();
      	      unsigned int	real_y = static_cast<int>(((tmp->getY() - 110) / 220) + 1) + y;
      	      unsigned int	real_x = static_cast<int>(((tmp->getX() - 110) / 220) + 1) + x;
      	      if (real_y < this->getManager()->Field::Manager::getHeight() && real_x < this->getManager()->Field::Manager::getWidth())
      		{
      		  int	imp = 0;
      		  for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(real_y, real_x).begin(); it != this->getManager()->Field::Manager::get(real_y, real_x).end(); ++it)
      		    {
      		      Display::Vector3f      newPosition(startx + y * 1.5, starty - x * 2 ,0);
      		      if (dynamic_cast<Field::Wall *>(*it) == *it)
      			{
      			  Field::Wall * tmp = static_cast<Field::Wall *>(*it);
      			  if (tmp->isBreakable())
      			    {
      			      this->_infos.at("barrel")->setPosition(newPosition);
      			      this->_infos.at("barrel")->draw();
      			    }
      			  else
      			    {
      			      this->_infos.at("wall")->setPosition(newPosition);
      			      this->_infos.at("wall")->draw();
      			    }
      			  imp = 1;
      			}
      		      else if (!imp)
      			{
			  this->_infos.at("floor")->setPosition(newPosition);
			  this->_infos.at("floor")->draw();
			}
      		    }
      		}
      	    }
      	}

      Display::Vector3f      newPosition2(startx, starty, 0);
      this->_infos.at("player")->setPosition(newPosition2);
      this->_infos.at("player")->draw();
      this->_infos.at("walter")->draw();
      switch (player->getPv())
	{
	case (0):
	  {
	    this->_infos.at("fiole0")->draw();
	    break;
	  }
	case (10):
	  {
	    this->_infos.at("fiole10")->draw();
	    break;
	  }
	case (20):
	  {
	    this->_infos.at("fiole20")->draw();
	    break;
	  }
	case (30):
	  {
	    this->_infos.at("fiole30")->draw();
	    break;
	  }
	case (40):
	  {
	    this->_infos.at("fiole40")->draw();
	    break;
	  }
	case (50):
	  {
	    this->_infos.at("fiole50")->draw();
	    break;
	  }
	case (60):
	  {
	    this->_infos.at("fiole60")->draw();
	    break;
	  }
	case (70):
	  {
	    this->_infos.at("fiole70")->draw();
	    break;
	  }
	case (80):
	  {
	    this->_infos.at("fiole80")->draw();
	    break;
	  }
	case (90):
	  {
	    this->_infos.at("fiole90")->draw();
	    break;
	  }
	case (100):
	  {
	    this->_infos.at("fiole100")->draw();
	    break;
	  }
	default:
	  {
	    this->_infos.at("fiole0")->draw();
	    break;
	  }
	}
    }

    void	BomberGame::updateCamera(gdl::GameClock const & gameClock, gdl::Input & input)
    {
      static_cast<void>(gameClock);
      static_cast<void>(input);
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
