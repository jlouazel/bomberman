#include	"BomberOptions.hh"
#include	<ctime>
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
#include	"Gif.hpp"
#include	"Xml.hh"
#include	"MyGame.hpp"
#include	"EventManager.hh"
#include	"EventEnum.hh"
#include	"Action.hh"
#include	"Pause.hh"
#include	<iostream>
#include	<sstream>

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame()
    {
      this->_loading = true;
      Sound::SoundManager::getInstance()->stopSound("./resources/sounds/musicIntro2.mp3");
      Sound::SoundManager::getInstance()->playSound("./resources/sounds/ambianceGame.mp3", true);

      this->_manager = new Field::Manager;

      int LightPos[4] = {0,0,3,1};
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glLightiv(GL_LIGHT0,GL_POSITION,LightPos);

      Display::Vector3f      vectorPosition(0, 0.0, 0);
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);

      this->_players.push_front(new Field::Player(0, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
      this->_players.push_front(new Field::Player(1, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));

      this->_manager->randomize(this->_players);

      std::list<Field::Player *>::iterator it = this->_players.begin();
      for (; it != this->_players.end(); ++it)
	{
	  this->_camera.push_back(new Display::Camera(BomberOptions::getOptions()->getNbPlayer()));
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
      this->_infos["jesse"] = new Display::Texture2d("images/JPmenu.png", vectorPosition2_, vectorRot_, vectorLen2_);
      this->_infos["jesse"]->initialize();
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
      vectorPosition3_.setX(0);
      vectorPosition3_.setY(0);
      vectorLen3_.setX(100);
      vectorLen3_.setY(100);
      this->_infos["background"] = new Display::Texture2d("images/black.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["background"]->initialize();
      this->_loading = false;
    }

    BomberGame::~BomberGame()
    {
    }

    static void updateObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock, Field::Manager *manager)
    {
      comp->update(gameClock, manager);
    }

    bool	BomberGame::isLoaded() const
    {
      return !this->_loading;
    }

    void	BomberGame::update(gdl::GameClock const & gameClock)
    {
      static int i = 0;
      if (i++ == 0)
	this->save();
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
	for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
	  {
	    for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
	      {
		if ((*it)->isEnd() == true)
		  {
		    if (dynamic_cast<Field::Wall *>(*it) == *it)
		      {
			Field::Wall *actualWall = static_cast<Field::Wall *>(*it);
			Field::Object *buff = actualWall->getContent();
			if (buff)
			  this->_manager->get(x, y).insert(it, buff);
			int	idPlayer = actualWall->getWhoDestroyedMe();
			for (std::list<Field::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
			  if ((*it)->getId() == idPlayer)
			    (*it)->setNbCaisseDestroyed((*it)->getNbCaisseDestroyed() + 1);
		      }
		    it = this->_manager->get(x, y).erase(it);
		  }
		else
		  updateObjs(*it, gameClock, this->_manager);
	      }
	  }
      this->eventPlayer();
      updateObjs(this->getPlayers().front(), gameClock, this->_manager);
    }

    void	BomberGame::eventPlayer()
    {
      int	id;
      const Event::IEvent* event;
      bool      moveOk = false;
      int	i = 0;

      while ((event = Event::EventManager::getEvent()) != NULL)
        {
	  id = event->getPlayerId();
	  Field::Player *actualPlayer;
	  for (std::list<Field::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	    if ((*it)->getId() == id)
	      actualPlayer = (*it);
	  if (dynamic_cast<const Event::Pause *>(event) == event)
	    {
	      std::cout << "KIKOU" << std::endl;
	      event->interaction();
	    }
          else if (dynamic_cast<const Event::Move *>(event) == event && !moveOk)
            {
              const Event::Move *move = dynamic_cast<const Event::Move *>(event);
              actualPlayer->setIsRunning(move->isRunning());
              actualPlayer->setIsMoving(true);
              i++;

              float       angle =  move->getAngle() * 3.14159 / 180.0;
              float       x = -(cosf(angle) * actualPlayer->getSpeed());
              float       z = sinf(angle) * actualPlayer->getSpeed();

              if (actualPlayer->checkMyMove(actualPlayer->getAsset()->getPosition().getZ() + z, actualPlayer->getAsset()->getPosition().getX() + x, this->_manager) == true)
                actualPlayer->move(x, z, angle, this->_manager);
              else
                {
                  if (actualPlayer->checkMyMove(actualPlayer->getAsset()->getPosition().getZ(), actualPlayer->getAsset()->getPosition().getX() + x, this->_manager) == true)
      		    actualPlayer->move(x, 0, angle, this->_manager);
                  else if (actualPlayer->checkMyMove(actualPlayer->getAsset()->getPosition().getZ() + z, actualPlayer->getAsset()->getPosition().getX(), this->_manager) == true)
                    actualPlayer->move(0, z, angle, this->_manager);
                }
              moveOk = true;
            }
          else if (dynamic_cast<const Event::Action *>(event) == event && actualPlayer->getNbBombSet() < actualPlayer->getNbBombMax())
            actualPlayer->setBomb(this->_manager);
          delete event;
        }
      // if (i == 0)
      //   {
      //     this->_isMoving = false;
      //     this->_isRunning = false;
      //   }
    }
  
    static void affObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->draw(gameClock);
    }

    void	BomberGame::drawForPlayer2D(gdl::GameClock const & gameClock, int id_player) const
    {
      this->_infos.at("background")->draw();

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

      // if (BomberOptions::getOptions()->getSkinForPlayer(player->getId()) == BomberOptions::WW)
      // 	this->_infos.at("walter")->draw();
      // else
      	this->_infos.at("jesse")->draw();
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

    void	BomberGame::drawForPlayer3D(gdl::GameClock const & gameClock, int id_player) const
    {
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
	for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
	  for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
	    {
	      if (BomberOptions::getOptions()->getNbPlayer() == 1)
		{
		  if (y > ((this->getPlayers().front()->getX() - 110) / 220) - 2 && y < ((this->getPlayers().front()->getX() + 110) / 220) + 3 && x > ((this->getPlayers().front()->getY() - 110) / 220) - 2 && x < ((this->getPlayers().front()
->getY() + 110) / 220) + 2)
		    affObjs(*it, gameClock);
		}
	      else
		if (y > ((this->getPlayers().front()->getX() - 110) / 220) - 1 && y < ((this->getPlayers().front()->getX() + 110) / 220) + 3 && x > ((this->getPlayers().front()->getY() - 110) / 220) - 2 && x < ((this->getPlayers().front()->getY() + 110) / 220) + 2)
		  affObjs(*it, gameClock);
	    }
      affObjs(this->getPlayers().front(), gameClock);
    }

    void	BomberGame::draw(gdl::GameClock const & gameClock) const
    {
      if (BomberOptions::getOptions()->getNbPlayer() == 2)
	{
	  glViewport(0, 0, WIDTH / 2, HEIGHT);
	  this->drawForPlayer3D(gameClock, 0);      	  
	  glViewport(WIDTH / 2, 0, WIDTH / 2, HEIGHT);
	  this->drawForPlayer3D(gameClock, 1);
	  glViewport(0, 0, WIDTH / 2, HEIGHT);
	  this->drawForPlayer2D(gameClock, 0);      	  
	  glViewport(WIDTH / 2 - 2, 0, WIDTH / 2 - 2, HEIGHT);
	  this->drawForPlayer2D(gameClock, 1);
	}
      else
	{
	  glViewport(0, 0, WIDTH, HEIGHT);
	  this->drawForPlayer3D(gameClock, 0);
	  this->drawForPlayer2D(gameClock, 0);
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

    template <typename T>
    static std::string intToString(T i)
    {
      std::stringstream s;
      s << i;
      return s.str();
    }

    void	BomberGame::save()
    {
      time_t t = time(0);
      struct tm * now = localtime(&t);
      static std::string extend = ".xml";
      static std::string path = ".data/.saves/";
      DataFormat::Xml xml;
      std::list<DataFormat::Xml::Balise *> bals;

      bals.push_back(new DataFormat::Xml::Balise("backup", DataFormat::OPENING));
      bals.back()->addAttribute(std::make_pair("id", intToString(time(0))));

      bals.push_back(new DataFormat::Xml::Balise("infos", DataFormat::OPENING));
      bals.push_back(new DataFormat::Xml::Balise("second", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_sec));
      bals.push_back(new DataFormat::Xml::Balise("second", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("minute", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_min));
      bals.push_back(new DataFormat::Xml::Balise("minute", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("hour", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_hour));
      bals.push_back(new DataFormat::Xml::Balise("hour", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("day", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_mday));
      bals.push_back(new DataFormat::Xml::Balise("day", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("month", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_mon + 1));
      bals.push_back(new DataFormat::Xml::Balise("month", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("year", DataFormat::OPENING));
      bals.back()->setContent(intToString(now->tm_year + 1900));
      bals.push_back(new DataFormat::Xml::Balise("year", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("infos", DataFormat::CLOSING));

      bals.push_back(new DataFormat::Xml::Balise("players", DataFormat::OPENING));
      for (std::list<Field::Player *>::iterator itPl = this->_players.begin(); itPl != this->_players.end(); ++itPl)
	{
	  bals.push_back(new DataFormat::Xml::Balise("player", DataFormat::OPENING));
	  bals.back()->addAttribute(std::make_pair("id", intToString((*itPl)->getId())));
	  bals.back()->addAttribute(std::make_pair("x", intToString((*itPl)->getX())));
	  bals.back()->addAttribute(std::make_pair("y", intToString((*itPl)->getY())));
	  bals.push_back(new DataFormat::Xml::Balise("pv", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getPv()));
	  bals.push_back(new DataFormat::Xml::Balise("pv", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("speed", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getSpeed()));
	  bals.push_back(new DataFormat::Xml::Balise("speed", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("realSpeed", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getRealSpeed()));
	  bals.push_back(new DataFormat::Xml::Balise("realSpeed", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("power", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getPower()));
	  bals.push_back(new DataFormat::Xml::Balise("power", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("bombmax", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getNbBombMax()));	  bals.push_back(new DataFormat::Xml::Balise("bombmax", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("bombset", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getNbBombSet()));
	  bals.push_back(new DataFormat::Xml::Balise("bombset", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("nbCaisseDestroyed", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getNbCaisseDestroyed()));
	  bals.push_back(new DataFormat::Xml::Balise("nbCaisseDestroyed", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("nbPlayerKilled", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getNbPlayerKilled()));
	  bals.push_back(new DataFormat::Xml::Balise("nbPlayerKilled", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("nbBuffTaked", DataFormat::OPENING));
	  bals.back()->setContent(intToString((*itPl)->getNbBuffTaked()));
	  bals.push_back(new DataFormat::Xml::Balise("nbBuffTaked", DataFormat::CLOSING));
	  bals.push_back(new DataFormat::Xml::Balise("player", DataFormat::CLOSING));
	}
      bals.push_back(new DataFormat::Xml::Balise("players", DataFormat::CLOSING));

      bals.push_back(new DataFormat::Xml::Balise("field", DataFormat::OPENING));
      bals.back()->addAttribute(std::make_pair("width", intToString(this->_manager->getWidth())));
      bals.back()->addAttribute(std::make_pair("height", intToString(this->_manager->getHeight())));
      for (unsigned int y = 0; y != this->_manager->getHeight(); y++)
	for (unsigned int x = 0; x != this->_manager->getWidth(); x++)
	  {
	    bals.push_back(new DataFormat::Xml::Balise("case", DataFormat::OPENING));
	    bals.back()->addAttribute(std::make_pair("x", intToString(x)));
	    bals.back()->addAttribute(std::make_pair("y", intToString(y)));
	    for (std::list<Field::IGameComponent *>::iterator it = this->_manager->get(x, y).begin(); it != this->_manager->get(x, y).end(); ++it)
	      {
		if (dynamic_cast<Field::Wall *>(*it) == *it)
		  {
		    bals.push_back(new DataFormat::Xml::Balise("wall", DataFormat::OPENING));
		    bals.back()->addAttribute(std::make_pair("x", intToString(dynamic_cast<Field::Wall *>(*it)->isBreakable())));
		    if (dynamic_cast<Field::Wall *>(*it)->isBreakable() == true)
		      if (dynamic_cast<Field::Wall *>(*it)->getContent() != 0)
			{

			}
		    bals.push_back(new DataFormat::Xml::Balise("wall", DataFormat::CLOSING));
		  }
	      }
	    bals.push_back(new DataFormat::Xml::Balise("case", DataFormat::CLOSING));
	  }
      bals.push_back(new DataFormat::Xml::Balise("field", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("backup", DataFormat::CLOSING));

      xml.addBalises(bals);
      xml.generate("test" + extend);
    }
  }
}
