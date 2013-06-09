#include	<iostream>
#include	<sstream>
#include	"BomberOptions.hh"
#include	<ctime>
#include	<unistd.h>
#include	<fmod.h>
#include	<fstream>
#include	<Input.hpp>
#include	<Clock.hpp>
#include	<GameClock.hpp>
#include	"EndOfBomberMan.hh"
#include	"SoundManager.hh"
#include	"Texture3d.hpp"
#include	"Texture2d.hpp"
#include	"BomberGame.hh"
#include	"Player.hh"
#include	"Enums.hh"
#include	"Gif.hpp"
#include	"Xml.hh"
#include	"Wall.hh"
#include	"Gif.hpp"
#include	"Xml.hh"
#include	"MyGame.hpp"
#include	"EventManager.hh"
#include	"EventEnum.hh"
#include	"Action.hh"
#include	"Pause.hh"
#include	"Text.hpp"
#include	<iostream>
#include	<sstream>
#include	<unistd.h>

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
      //this->load(".data/.saves/1370799642.xml");
      int LightPos[4] = {0,0,3,1};
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glLightiv(GL_LIGHT0,GL_POSITION,LightPos);

      Display::Vector3f      vectorPosition(0, 0.0, 0);
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);

      // this->_players.push_front(new Field::Player(0, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));

      //      this->_manager->randomize(this->_players);

      // std::list<Field::Player *>::iterator it = this->_players.begin();
      // for (; it != this->_players.end(); ++it)
      BomberOptions::getOptions()->getNbPlayer();
      BomberOptions::getOptions()->getNbIA();
      std::cout << "Nb player : " << BomberOptions::getOptions()->getNbPlayer() << std::endl;
      std::cout << "Nb IA : " << BomberOptions::getOptions()->getNbIA() << std::endl;
      this->_players.push_back(new Field::Player(0, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, 0, 0, 255));
      this->_players.back()->setCamera(new Display::Camera(BomberOptions::getOptions()->getNbPlayer()));
      if (BomberOptions::getOptions()->getNbPlayer() == 2)
	{
	  this->_players.push_back(new Field::Player(1, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, 255, 0, 0));
	  this->_players.back()->setCamera(new Display::Camera(BomberOptions::getOptions()->getNbPlayer()));
	}
      for (unsigned int i = 1; i < BomberOptions::getOptions()->getNbIA(); i++)
	{
	  this->_players.push_back(new Field::Player(i + 1, 100, 10, 1, 0, 0, 0, new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, rand() % 255, rand() % 255, rand() % 255));
	  this->_players.back()->startIA(this->_manager->getWidth(), this->_manager->getHeight(), this->_manager->getMap(), this->_players);
	}
      this->_manager->randomize(this->_players);

      std::list<Field::Player *>::iterator it = this->_players.begin();
      for (; it != this->_players.end(); ++it)
	(*it)->initialize();

      Display::Vector3f      vectorPosition_(0, 0, 0);
      Display::Vector3f      vectorLen_(1.5, 2, 0.0);
      Display::Vector3f      vectorRot_(0.0, 0.0, 0.0);
      Display::Vector3f      vectorPosition2_(0, 70, 0);
      Display::Vector3f      vectorLen2_(20, 40, 0.0);
      Display::Vector3f      vectorPosition3_(20, 75, 0);
      Display::Vector3f      vectorLen3_(5, 10, 0.0);
      Display::Vector3f      vectorPosition4_(20, 85, 0);
      Display::Vector3f      vectorLen4_(5, 5, 0.0);

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
      this->_infos["clean"] = new Display::Texture2d("images/BlackFond.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["clean"]->initialize();
      vectorPosition3_.setX(25);
      vectorPosition3_.setY(0);
      vectorLen3_.setX(50);
      vectorLen3_.setY(100);
      this->_infos["lose1"] = new Display::Texture2d("images/YouAreDead.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["lose1"]->initialize();
      this->_infos["win1"] = new Display::Texture2d("images/YouWin.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["win1"]->initialize();
      this->_infos["lose2"] = new Display::Texture2d("images/YouAreDead.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["lose2"]->initialize();
      this->_infos["win2"] = new Display::Texture2d("images/YouWin.png", vectorPosition3_, vectorRot_, vectorLen3_);
      this->_infos["win2"]->initialize();
      this->_infos["bomb"] = new Display::Texture2d("images/Bomb.png", vectorPosition4_, vectorRot_, vectorLen4_);
      this->_infos["bomb"]->initialize();
      this->_loading = false;

      this->_clock = new gdl::Clock();
      this->_clock->play();
      this->_fps = 30;
      this->_constElapsedTime = 1.0 / static_cast<float>(this->_fps);
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
      this->_clock->update();
      static int i = 0;
      if (i++ == 0)
	{
	  //this->save();
	}
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
      for (std::list<Field::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	updateObjs(*it, gameClock, this->_manager);
      this->eventPlayer();
    }

    void	BomberGame::eventPlayer()
    {
      int	id;
      const Event::IEvent* event;
      int	i = 0;

      while ((event = Event::EventManager::getEvent()) != NULL)
        {
	  id = event->getPlayerId();
	  Field::Player *actualPlayer = 0;
	  for (std::list<Field::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	    if ((*it)->getId() == id)
	      actualPlayer = (*it);
	  if (dynamic_cast<const Event::Pause *>(event) == event)
	    event->interaction(this->checkIfEnd());
          else if (actualPlayer && dynamic_cast<const Event::Move *>(event) == event && actualPlayer->getMoveOk() == false && actualPlayer->getPv() > 0)
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
              actualPlayer->setMoveOk(true);
            }
          else if (actualPlayer && dynamic_cast<const Event::Action *>(event) == event && actualPlayer->getNbBombSet() < actualPlayer->getNbBombMax() && actualPlayer->getPv() > 0)
            actualPlayer->setBomb(this->_manager);
	  // if (actualPlayer && actualPlayer->getPv() <= 0)
	  //   {

	  //   }
          delete event;
        }
      for (std::list<Field::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
	  if ((*it)->getMoveOk() == false)
	    {
	      (*it)->setIsMoving(false);
	      (*it)->setIsRunning(false);
	    }
	}
    }

    static void affObjs(Field::IGameComponent * comp, gdl::GameClock const & gameClock)
    {
      comp->draw(gameClock);
    }

    bool	BomberGame::checkIfEnd() const
    {
      int	i = 0;

      for (std::list<Field::Player *>::const_iterator it = this->_players.begin(); it != this->_players.end(); ++it)
        if ((*it)->getPv() > 0)
	  i++;
      return i > 1 ? false : true;
    }

    bool	BomberGame::checkIfIWin(int id_player) const
    {
      for (std::list<Field::Player *>::const_iterator it = this->_players.begin(); it != this->_players.end(); ++it)
        if ((*it)->getId() != id_player && (*it)->getPv() > 0)
	  return (false);
      return (true);
    }

    void	BomberGame::drawForPlayer2D(gdl::GameClock const &, int id_player) const
    {
      this->_infos.at("background")->draw();

      float	startx = 88;
      float	starty = 85;

      Field::Player * player = 0;

      for (std::list<Field::Player *>::const_iterator it = this->_players.begin(); it != this->_players.end(); ++it)
        if ((*it)->getId() == id_player)
          player = (*it);
      if (player == 0)
        return;
      if (this->checkIfIWin(id_player) == true)
      	{
	  this->_infos.at("clean")->draw();
          if (id_player == 0)
            this->_infos.at("win1")->draw();
          else if (id_player == 1)
            this->_infos.at("win2")->draw();
      	}
      if (player->getRealDead() == true)
	{
	  this->_infos.at("clean")->draw();
	  if (id_player == 0)
	    this->_infos.at("lose1")->draw();
	  else if (id_player == 1)
	    this->_infos.at("lose2")->draw();
	}
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
      if (BomberOptions::getOptions()->getSkinForPlayer(player->getId()) == BomberOptions::WW)
      	this->_infos.at("walter")->draw();
      else
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
      for (int i = player->getNbBombMax() - player->getNbBombSet() - 1; i >= 0; i--)
	{
	  Display::Vector3f      newPosition5(20 + (i * 3), 90, 0);
	  this->_infos.at("bomb")->setPosition(newPosition5);
	  this->_infos.at("bomb")->draw();
	}
      // gdl::Text text;
      // text.setText("LOOOL");
      // if (id_player == 0)
      // 	text.setPosition(100, 1000);
      // else if (id_player == 1)
      // 	text.setPosition(950, 1000);
      // text.setSize(50);
      // text.draw();
    }

    void	BomberGame::drawForPlayer3D(gdl::GameClock const & gameClock, int id_player) const
    {
      Field::Player *actualPlayer = 0;
      for (std::list<Field::Player *>::const_iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	if ((*it)->getId() == id_player)
	  actualPlayer = (*it);
      if (actualPlayer == 0)
	return;
      actualPlayer->updateCamera(gameClock);
      affObjs(actualPlayer, gameClock);
      for (unsigned int y = 0; y != this->getManager()->Field::Manager::getHeight(); y++)
	for (unsigned int x = 0; x != this->getManager()->Field::Manager::getWidth(); x++)
	  for (std::list<Field::IGameComponent *>::iterator it = this->getManager()->Field::Manager::get(x, y).begin(); it != this->getManager()->Field::Manager::get(x, y).end(); ++it)
	    {
	      if (BomberOptions::getOptions()->getNbPlayer() == 1)
		{
		  if (y > ((actualPlayer->getX() - 110) / 220) - 2 && y < ((actualPlayer->getX() + 110) / 220) + 3 && x > ((actualPlayer->getY() - 110) / 220) - 2 && x < ((actualPlayer
->getY() + 110) / 220) + 2)
		    affObjs(*it, gameClock);
		}
	      else
		if (y > ((actualPlayer->getX() - 110) / 220) - 1 && y < ((actualPlayer->getX() + 110) / 220) + 3 && x > ((actualPlayer->getY() - 110) / 220) - 2 && x < ((actualPlayer->getY() + 110) / 220) + 2)
		  affObjs(*it, gameClock);
	    }
      for (std::list<Field::Player *>::const_iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
	  if ((*it) != actualPlayer)
	    {
	      if (BomberOptions::getOptions()->getNbPlayer() == 1)
		{
		  if ((((*it)->getY() - 110) / 220) > ((actualPlayer->getX() - 110) / 220) - 2 && (((*it)->getY() - 110) / 220) < ((actualPlayer->getX() + 110) / 220) + 3 && (((*it)->getX() - 110) / 220) > ((actualPlayer->getY() - 110) / 220) - 2 && (((*it)->getX() - 110) / 220) < ((actualPlayer->getY() + 110) / 220) + 2)
		    affObjs(*it, gameClock);
		}
	      else
		if ((((*it)->getY() - 110) / 220) > ((actualPlayer->getX() - 110) / 220) - 1 && (((*it)->getY() - 110) / 220) < ((actualPlayer->getX() + 110) / 220) + 3 && (((*it)->getX() - 110) / 220) > ((actualPlayer->getY() - 110) / 220) - 2 && (((*it)->getX() - 110) / 220) < ((actualPlayer->getY() + 110) / 220) + 2)
		  affObjs(*it, gameClock);
	    }
	}
    }

    void	BomberGame::draw(gdl::GameClock const & gameClock) const
    {
      float     elapsedTime = this->_clock->getElapsedTime();
      this->_clock->getUpdateElapsedTime();
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
      if (elapsedTime < this->_constElapsedTime)
        {
	  std::cout << "elapsedTime = " << elapsedTime << " const : " << this->_constElapsedTime << " " << (this->_constElapsedTime - elapsedTime) * 1000000 << std::endl;
          usleep((this->_constElapsedTime - elapsedTime) * 1000000);
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

    static unsigned int stringToInt(std::string const & str)
    {
      int ret;
      std::stringstream s;
      s << str.c_str();
      s >> ret;
      return ret;
    }
    void	BomberGame::load(std::string const & filename)
    {
      DataFormat::Xml xml(filename);
      unsigned int width = stringToInt(xml.getBalisesWthName("field")->getAttrValue("width"));
      unsigned int height = stringToInt(xml.getBalisesWthName("field")->getAttrValue("height"));
      std::list<Field::IGameComponent *> objs;
      Field::Manager * manager = new Field::Manager(width, height);
      for (std::list<DataFormat::Xml::Balise *>::const_iterator it = xml.getBalises().begin(); it != xml.getBalises().end(); ++it)
	{
	  if ((*it)->getName().empty() != true && (*it)->getName() == "wall" && (*it)->getState() == DataFormat::OPENING)
	    {
	      unsigned int x = stringToInt((*it)->getAttrValue("x"));
	      unsigned int y = stringToInt((*it)->getAttrValue("y"));
	      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
	      Display::Vector3f	vectorRot(0.0, manager->randAngle(5), 0.0);
	      Display::Vector3f	vectorPosition(y * 220, 0.0, x * 220);
	      manager->addComponent(x, y, new Field::Wall(true, 1, y, x, new Display::Texture3d("models/Barrel.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else if ((*it)->getName().empty() != true && (*it)->getName() == "object" && (*it)->getState() == DataFormat::OPENING)
	    {
	      unsigned int x = stringToInt((*it)->getAttrValue("x"));
	      unsigned int y = stringToInt((*it)->getAttrValue("y"));
	      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
	      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
	      Display::Vector3f	vectorPosition(y * 220, 0.0, x * 220);
	      switch (stringToInt((*it)->getAttrValue("buffType")))
	      	{
	      	case 0:
		  if (dynamic_cast<Field::Wall *>(manager->get(x, y).front()) == manager->get(x, y).front())
		    dynamic_cast<Field::Wall *>(manager->get(x, y).front())->setContent(new Field::Object(y, x, new Display::Texture3d("models/PorteeBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::RANGE, 0, 0, -1));
		  else
		    manager->addComponent(x, y, new Field::Object(y, x, new Display::Texture3d("models/PorteeBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::RANGE, 0, 0, -1));
	      	  break;
	      	case 1:
		  if (dynamic_cast<Field::Wall *>(manager->get(x, y).front()) == manager->get(x, y).front())
		    dynamic_cast<Field::Wall *>(manager->get(x, y).front())->setContent(new Field::Object(y, x, new Display::Texture3d("models/SpeedBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::SPEED, 0, 0, -1));
		  else
		    manager->addComponent(x, y, new Field::Object(y, x, new Display::Texture3d("models/SpeedBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::SPEED, 0, 0, -1));
	      	  break;
	      	case 2:
		  if (dynamic_cast<Field::Wall *>(manager->get(x, y).front()) == manager->get(x, y).front())
		    dynamic_cast<Field::Wall *>(manager->get(x, y).front())->setContent(new Field::Object(y, x, new Display::Texture3d("models/LifeBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::LIFE, 0, 0, -1));
		  else
		    manager->addComponent(x, y, new Field::Object(y, x, new Display::Texture3d("models/LifeBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::LIFE, 0, 0, -1));
	      	  break;
	      	case 3:
		  if (dynamic_cast<Field::Wall *>(manager->get(x, y).front()) == manager->get(x, y).front())
		    dynamic_cast<Field::Wall *>(manager->get(x, y).front())->setContent(new Field::Object(y, x, new Display::Texture3d("models/MoreBombBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::MORE, 0, 0, -1));
		  else
		    manager->addComponent(x, y, new Field::Object(y, x, new Display::Texture3d("models/MoreBombBonus.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, Field::BUFF, Field::MORE, 0, 0, -1));
	      	  break;
	      	default:
	      	  break;
	      	}
	    }
	  for (std::list<DataFormat::Xml::Balise *>::const_iterator it = xml.getBalises().begin(); it != xml.getBalises().end(); ++it)
	    {
	      if ((*it)->getName().empty() != true && (*it)->getName() == "player" && (*it)->getState() == DataFormat::OPENING)
		{
		  Display::Vector3f      vectorPosition(stringToInt((*it)->getAttrValue("y")) * 220, 0, stringToInt((*it)->getAttrValue("x")) * 220);
		  Display::Vector3f      vectorLen(0, 0, 0.0);
		  Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
		  if (stringToInt((*it)->getAttrValue("id")) == 0)
		    this->_players.push_back(new Field::Player(stringToInt((*it)->getAttrValue("id")), stringToInt((*it)->getAttrValue("pv")), stringToInt((*it)->getAttrValue("speed")), stringToInt((*it)->getAttrValue("bombmax")), stringToInt((*it)->getAttrValue("bombset")), stringToInt((*it)->getAttrValue("x")), stringToInt((*it)->getAttrValue("y")), new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, 0, 0, 255));
		  else if (stringToInt((*it)->getAttrValue("id")) == 1)
		    this->_players.push_back(new Field::Player(stringToInt((*it)->getAttrValue("id")), stringToInt((*it)->getAttrValue("pv")), stringToInt((*it)->getAttrValue("speed")), stringToInt((*it)->getAttrValue("bombmax")), stringToInt((*it)->getAttrValue("bombset")), stringToInt((*it)->getAttrValue("x")), stringToInt((*it)->getAttrValue("y")), new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, 255, 0, 0));
		  else
		    this->_players.push_back(new Field::Player(stringToInt((*it)->getAttrValue("id")), stringToInt((*it)->getAttrValue("pv")), stringToInt((*it)->getAttrValue("speed")), stringToInt((*it)->getAttrValue("bombmax")), stringToInt((*it)->getAttrValue("bombset")), stringToInt((*it)->getAttrValue("x")), stringToInt((*it)->getAttrValue("y")), new Display::Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRot, vectorLen), 0, 0, rand() % 255, rand() % 255, rand() % 255));
		}
	    }
	}
      this->_manager = manager;
    }

    void	BomberGame::save()
    {
      if (access(".data/", F_OK) == -1 || access(".data/.saves/", F_OK) == -1)
	throw(EndOfBomberMan("unable to access saves directory", "save method", "./data/.saves/"));
      time_t t = time(0);
      struct tm * now = localtime(&t);
      static std::string extend = ".xml";
      static std::string path = ".data/.saves/";
      std::string name = intToString(time(0));
      DataFormat::Xml xml;
      std::list<DataFormat::Xml::Balise *> bals;

      bals.push_back(new DataFormat::Xml::Balise("backup", DataFormat::OPENING));
      bals.back()->addAttribute(std::make_pair("id", name));

      bals.push_back(new DataFormat::Xml::Balise("infos", DataFormat::OPENING));
      bals.back()->addAttribute(std::make_pair("second", intToString(now->tm_sec)));
      bals.back()->addAttribute(std::make_pair("minute", intToString(now->tm_min)));
      bals.back()->addAttribute(std::make_pair("hour", intToString(now->tm_hour)));
      bals.back()->addAttribute(std::make_pair("day", intToString(now->tm_mday)));
      bals.back()->addAttribute(std::make_pair("month", intToString(now->tm_mon)));
      bals.back()->addAttribute(std::make_pair("year", intToString(now->tm_year)));
      bals.push_back(new DataFormat::Xml::Balise("infos", DataFormat::CLOSING));

      bals.push_back(new DataFormat::Xml::Balise("players", DataFormat::OPENING));
      for (std::list<Field::Player *>::iterator itPl = this->_players.begin(); itPl != this->_players.end(); ++itPl)
	{
	  bals.push_back(new DataFormat::Xml::Balise("player", DataFormat::OPENING));
	  bals.back()->addAttribute(std::make_pair("id", intToString((*itPl)->getId())));
	  bals.back()->addAttribute(std::make_pair("x", intToString((*itPl)->getX())));
	  bals.back()->addAttribute(std::make_pair("y", intToString((*itPl)->getY())));
	  bals.back()->addAttribute(std::make_pair("pv", intToString((*itPl)->getPv())));
	  bals.back()->addAttribute(std::make_pair("speed", intToString((*itPl)->getSpeed())));
	  bals.back()->addAttribute(std::make_pair("readSpeed", intToString((*itPl)->getRealSpeed())));
	  bals.back()->addAttribute(std::make_pair("power", intToString((*itPl)->getPower())));
	  bals.back()->addAttribute(std::make_pair("bombmax", intToString((*itPl)->getNbBombMax())));
	  bals.back()->addAttribute(std::make_pair("bombset", intToString((*itPl)->getNbBombSet())));
	  bals.back()->addAttribute(std::make_pair("nbCaisseDestroyed", intToString((*itPl)->getNbCaisseDestroyed())));
	  bals.back()->addAttribute(std::make_pair("nbPlayerKilled", intToString((*itPl)->getNbPlayerKilled())));
	  bals.back()->addAttribute(std::make_pair("buffTaked", intToString((*itPl)->getNbBuffTaked())));
	  bals.push_back(new DataFormat::Xml::Balise("player", DataFormat::CLOSING));
	}
      bals.push_back(new DataFormat::Xml::Balise("players", DataFormat::CLOSING));

      bals.push_back(new DataFormat::Xml::Balise("field", DataFormat::OPENING));
      bals.back()->addAttribute(std::make_pair("width", intToString(this->_manager->getWidth())));
      bals.back()->addAttribute(std::make_pair("height", intToString(this->_manager->getHeight())));
      for (unsigned int y = 0; y != this->_manager->getHeight(); y++)
	for (unsigned int x = 0; x != this->_manager->getWidth(); x++)
	  {
	    std::list<Field::IGameComponent *>::iterator it;
	    for (it = this->_manager->get(x, y).begin(); it != this->_manager->get(x, y).end(); ++it)
	      if (dynamic_cast<Field::Wall *>(*it) == *it && dynamic_cast<Field::Wall *>(*it)->isBreakable() == true)
		{
		  bals.push_back(new DataFormat::Xml::Balise("wall", DataFormat::OPENING));
		  bals.back()->addAttribute(std::make_pair("x", intToString(x)));
		  bals.back()->addAttribute(std::make_pair("y", intToString(y)));
		  bals.push_back(new DataFormat::Xml::Balise("wall", DataFormat::CLOSING));
		  if (dynamic_cast<Field::Wall *>(*it)->getContent() != 0)
		    {
		      bals.push_back(new DataFormat::Xml::Balise("object", DataFormat::OPENING));
		      bals.back()->addAttribute(std::make_pair("x", intToString(x)));
		      bals.back()->addAttribute(std::make_pair("y", intToString(y)));
		      bals.back()->addAttribute(std::make_pair("objectType", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getObjectType())));
		      bals.back()->addAttribute(std::make_pair("buffType", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getBuffType())));
		      bals.back()->addAttribute(std::make_pair("power", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getPower())));
		      bals.back()->addAttribute(std::make_pair("timer", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getTimer())));
		      bals.push_back(new DataFormat::Xml::Balise("object", DataFormat::CLOSING));
		    }
		}
	      else if (dynamic_cast<Field::Object *>(*it) == *it)
		{
		  bals.push_back(new DataFormat::Xml::Balise("object", DataFormat::OPENING));
		  bals.back()->addAttribute(std::make_pair("x", intToString(x)));
		  bals.back()->addAttribute(std::make_pair("y", intToString(y)));

		  bals.back()->addAttribute(std::make_pair("objectType", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getObjectType())));
		  bals.back()->addAttribute(std::make_pair("buffType", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getBuffType())));
		  bals.back()->addAttribute(std::make_pair("power", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getPower())));
		  bals.back()->addAttribute(std::make_pair("timer", intToString(dynamic_cast<Field::Wall *>(*it)->getContent()->getTimer())));
		  bals.push_back(new DataFormat::Xml::Balise("object", DataFormat::CLOSING));
		}
	  }
      bals.push_back(new DataFormat::Xml::Balise("field", DataFormat::CLOSING));
      bals.push_back(new DataFormat::Xml::Balise("backup", DataFormat::CLOSING));
      xml.addBalises(bals);
      xml.generate(path + name + extend);
    }
  }
}
