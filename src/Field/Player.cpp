//
//  Player.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include        "SoundManager.hh"
#include	"Action.hh"
#include "AObject.hpp"
#include "Texture3d.hpp"
#include "Player.hh"
#include "Vector.hpp"
#include "Wall.hh"
#include "Empty.hh"

namespace BomberMan
{
  namespace Field
  {
    Player::Player(int id, int pv, float speed, int max, int set, float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
      :   _id(id), _pv(pv), _speed(speed), _nb_bomb_max(max), _nb_bomb_set(set)
    {
      Display::Vector3f	position(0, 0, 0);
      Display::Vector3f	rotation(0, 0, 0);
      Display::Vector3f	len(0, 0, 0);

      this->_x = x;
      this->_y = y;
      this->_animation = anim;
      this->_sound = sound;
      this->_asset = asset;
      this->_walking = new Display::Texture3d("models/WWwalking.fbx", position, rotation, len);
      this->_run = new Display::Texture3d("models/WWrunning.fbx", position, rotation, len);
      this->_mark = new Display::Texture3d("models/PlayerMark.fbx", position, rotation, len);
      this->_power = 3;
      this->_bomb = new Object(0.0, 0.0, new Display::Texture3d("models/ExplodingBomb.fbx", position, rotation, len), 0, 0, BOMB, NONE, this->_power, 3, this->_id);
      this->_camera = 0; // initialise after
      this->_isMoving = false;
      this->_dead = new Display::Texture3d("models/WWdead.fbx", position, rotation, len);;
      this->_dying = new Display::Texture3d("models/WWdying.fbx", position, rotation, len);;
      this->_end = false;
      this->_nbCaisseDestroyed = 0;
      this->_nbPlayerKilled = 0;
      this->_nbBuffTaked = 0;
      this->_realSpeed = speed;
      this->_nb_bomb_set = 0;
    }

    Player::Player(Player * cpy)
    {
      this->_pv = cpy->getPv();
      this->_speed = cpy->getSpeed();
      this->_nb_bomb_max = cpy->getNbBombMax();
      this->_nb_bomb_set = cpy->getNbBombSet();
      this->_bomb = cpy->getBomb();
      this->_walking = cpy->getWalking();
      this->_mark = cpy->getMark();
      this->_run = cpy->getRun();
      this->_asset = cpy->getAsset();
      this->_camera = cpy->getCamera();
      this->_isMoving = cpy->getIsMoving();
      this->_isRunning = cpy->getIsRunning();
    }

    Player::~Player()
    {
      delete this->_bomb;
    }

    BomberMan::Display::AObject * Player::getAsset() const
    {
      return (this->_asset);
    }

    int		Player::getNbCaisseDestroyed() const
    {
      return (this->_nbCaisseDestroyed);
    }

    int		Player::getNbPlayerKilled() const
    {
      return (this->_nbPlayerKilled);
    }

    int		Player::getNbBuffTaked() const
    {
      return (this->_nbBuffTaked);
    }

    void	Player::setNbCaisseDestroyed(int newInt)
    {
      this->_nbCaisseDestroyed = newInt;
    }

    void	Player::setNbPlayerKilled(int newInt)
    {
      this->_nbPlayerKilled = newInt;
    }

    void	Player::setNbBuffTaked(int newInt)
    {
      this->_nbBuffTaked = newInt;
    }

    void        Player::move(float x, float z, float angle, Manager *manager)
    {
      this->_x = this->_asset->getPosition().getX() + x;
      this->_y = this->_asset->getPosition().getZ() + z;
      Display::Vector3f	newVectorPosition(this->_asset->getPosition().getX() + x, this->_asset->getPosition().getY(), this->_asset->getPosition().getZ() + z);
      Display::Vector3f newVectorRotation(this->_asset->getRotation().getX(), static_cast<int>(angle * 180.0 / 3.14159 + 270) % 360, this->_asset->getRotation().getZ());
      this->_asset->setPosition(newVectorPosition);
      this->_asset->setRotation(newVectorRotation);
      this->_walking->setPosition(newVectorPosition);
      this->_walking->setRotation(newVectorRotation);
      this->_run->setPosition(newVectorPosition);
      this->_run->setRotation(newVectorRotation);

      this->_dying->setPosition(newVectorPosition);
      this->_dying->setRotation(newVectorRotation);

      this->_dead->setPosition(newVectorPosition);
      this->_dead->setRotation(newVectorRotation);

      this->_mark->setPosition(newVectorPosition);
      this->_camera->setLook(newVectorPosition);
      newVectorPosition.setX(newVectorPosition.getX() + this->_camera->getDistanceX());
      newVectorPosition.setY(newVectorPosition.getY() + this->_camera->getDistanceY());
      this->_camera->setPosition(newVectorPosition);
    }

    void	Player::newBomb()
    {
      Display::Vector3f position(0, 0, 0);
      Display::Vector3f rotation(0, 0, 0);
      Display::Vector3f len(0, 0, 0);

      this->_bomb =  new Object(0.0, 0.0, new Display::Texture3d("models/ExplodingBomb.fbx", position, rotation, len),0, 0, BOMB, NONE, this->_power, 3, this->_id);
      this->_bomb->initialize();
    }

    void        Player::setBomb(Manager *manager)
    {
      int	X = (this->_x + 110) / 220;
      int	Y = (this->_y + 110) / 220;
      IGameComponent *toadd(this->_bomb);

      std::cout << "Je pose une bombe haha" << std::endl;
      this->newBomb();
      toadd->setX(X);
      toadd->setY(Y);
      if (manager->addComponent(Y, X, toadd) == true)
	this->_nb_bomb_set++;
      this->_clock.push_back(new gdl::Clock());
      this->_clock.back()->play();
    }

    void	Player::initialize()
    {
      this->_asset->initialize();
      this->_walking->initialize();
      this->_mark->initialize();
      this->_run->initialize();
      this->_mark->setColor(0, 0, 255);
      this->_camera->initialize();
      this->_bomb->initialize();
      this->_dead->initialize();
      this->_dying->initialize();
    }

    bool        Player::checkMyMove(float x, float z, Manager *manager)
    {
      if ((x + 110 - 20) / 220 < 0 || (x + 110 + 20) / 220 > (manager->getWidth()) ||
	  (z + 110 - 20) / 220 < 0 || (z + 110 + 20) / 220 > (manager->getHeight()))
	return (false);
      for (int y = 0; y < manager->getHeight(); y++)
	for (int X = 0; X < manager->getWidth(); X++)
	  {
	    std::list<IGameComponent *> obj = manager->get(X, y);

	    for (std::list<IGameComponent *>::iterator it = obj.begin(); it != obj.end(); ++it)
	      {
		if (dynamic_cast<Wall *>(*it) == *it)
		  if (static_cast<int>((z + 110) / 220) == (*it)->getX() && static_cast<int>((x + 110) / 220) == (*it)->getY())
		    return (false);
	      }
	  }
      return (true);
    }

    void	Player::checkBuff(Manager *manager)
    {
      std::list<IGameComponent *> obj = manager->get(static_cast<int>((this->_y + 110) / 220), static_cast<int>((this->_x + 110) / 220));

      for (std::list<IGameComponent *>::iterator it = obj.begin(); it != obj.end(); ++it)
	{
	  if (dynamic_cast<Empty *>(*it) == *it)
	    {
	      Empty *tmp = static_cast<Empty *>(*it);

	      if (tmp->getPlayerTakeDomage() > 0)
		this->explode(tmp->getPlayerTakeDomage(), manager, tmp->getIdBomb());
	    }
	  else if (dynamic_cast<Object *>(*it) == *it)
	    {
	      Object *tmp = static_cast<Object *>(*it);

	      if (tmp->getObjectType() == BUFF)
		{
		  switch (tmp->getBuffType())
		    {
		    case LIFE :
		      {
			this->_pv += 20;
			if (this->_pv > 100)
			  this->_pv = 100;
			break;
		      }
		    case SPEED :
		      {
			if (this->_realSpeed == 10)
			  this->_realSpeed += 10;
			else
			  this->_realSpeed += 5;
			if (this->_realSpeed > 50)
			  this->_realSpeed = 50;
			break;
		      }
		    case RANGE :
		      {
			this->_power += 1;
			this->_bomb->setPower(this->_power);
			break;
		      }
		    case MORE :
		      {
			this->_nb_bomb_max++;
			break;
		      }
		    }
		  manager->setBuffToFalse(static_cast<int>((this->_y + 110) / 220), static_cast<int>((this->_x + 110) / 220));
		}
	    }
	}
    }

    void        Player::imDyingDraw()
    {
      static int i = 0;

      if (i < 25)
        {
          this->_dying->draw();
	  i++;
        }
      else
	this->_dead->draw();
    }

    void	Player::update(gdl::GameClock const & gameClock, Manager *manager)
    {
      bool	moveOk = false;
      int i = 0;

      if (this->_pv <= 0)
      	{
	  this->_dying->update(gameClock);
	  this->_dead->update(gameClock);
      	  return;
      	}
      for (std::list<gdl::Clock *>::iterator it = this->_clock.begin(); it != this->_clock.end(); ++it)
	{
	  (*it)->update();
	  if ((*it)->getTotalElapsedTime() >= 3)
	    {
	      this->_nb_bomb_set--;
	      it = this->_clock.erase(it);
	    }
	}
      this->checkBuff(manager);
      const Event::IEvent* event;
      while ((event = Event::EventManager::getEvent()) != NULL)
	{
	  if (dynamic_cast<const Event::Move *>(event) == event && !moveOk)
	    {
	      const Event::Move *move = (const Event::Move *)event;
	      this->_isRunning = move->isRunning();
	      this->_isMoving = true;
	      i++;

	      float       angle =  move->getAngle() * 3.14159 / 180.0;
	      float       x = -(cosf(angle) * this->_speed);
	      float       z = sinf(angle) * this->_speed;

	      if (this->checkMyMove(this->_asset->getPosition().getZ() + z, this->_asset->getPosition().getX() + x, manager) == true)
		this->move(x, z, angle, manager);
	      else
		{
		  if (this->checkMyMove(this->_asset->getPosition().getZ(), this->_asset->getPosition().getX() + x, manager) == true)
		      this->move(x, 0, angle, manager);
		  else if (this->checkMyMove(this->_asset->getPosition().getZ() + z, this->_asset->getPosition().getX(), manager) == true)
		    this->move(0, z, angle, manager);
		}
	      moveOk = true;
	    }
	  else if (dynamic_cast<const Event::Action *>(event) == event && this->_nb_bomb_set < this->_nb_bomb_max)
	    this->setBomb(manager);
	  delete event;
	}
      if (i == 0)
	{
	  this->_isMoving = false;
	  this->_isRunning = false;
	}
      this->run(gameClock);
    }

    void	Player::draw(gdl::GameClock const & gameClock)
    {
      if (this->_pv <= 0)
	this->imDyingDraw();
      else
	{
	  if (this->_isRunning == true)
	    this->_run->draw();
	  else if (this->_isMoving == true)
	    this->_walking->draw();
	  else
	    this->_asset->draw();
	  this->_mark->draw();
	}
      this->_camera->update(gameClock);
    }

    void        Player::run(gdl::GameClock const &gameClock)
    {
      if (this->_isRunning == true)
        {
          this->_run->play("Take 001", 1);
          this->_walking->stop("Take 001");
          this->_speed = this->_realSpeed + 10;
        }
      else if (this->_isMoving == true)
        {
          this->_walking->play("Take 001", 1);
          this->_run->stop("Take 001");
          this->_speed = 10;
        }
      else
        {
          this->_asset->play("Take 001", 1);
          this->_walking->stop("Take 001");
          this->_run->stop("Take 001");
        }
      this->_run->update(gameClock);
      this->_mark->play("Take 001", 1);
      this->_asset->update(gameClock);
      this->_walking->update(gameClock);
      this->_mark->update(gameClock);
      this->_asset->update(gameClock);
    }

    int         Player::getNbBombMax() const
    {
      return this->_nb_bomb_max;
    }

    void        Player::setNbBombMax(int nb)
    {
      this->_nb_bomb_max = nb;
    }

    int         Player::getNbBombSet() const
    {
      return this->_nb_bomb_set;
    }

    int		Player::getId() const
    {
      return (this->_id);
    }

    bool	  Player::getIsMoving() const
    {
      return this->_isMoving;
    }

    bool        Player::getIsRunning() const
    {
      return this->_isMoving;
    }

    Display::AObject *  Player::getRun() const
    {
      return this->_run;
    }

    Display::AObject *  Player::getMark() const
    {
      return this->_mark;
    }

    Display::Camera *	  Player::getCamera() const
    {
      return this->_camera;
    }

    Display::AObject *  Player::getWalking() const
    {
      return this->_walking;
    }

    float       Player::getSpeed() const
    {
      return this->_speed;
    }

    void        Player::setSpeed(float speed)
    {
      this->_speed = speed;
    }

    Object *    Player::getBomb() const
    {
      return this->_bomb;
    }

    int         Player::getPv() const
    {
      return this->_pv;
    }

    void        Player::setPv(int pv)
    {
      this->_pv = pv;
    }

    void        Player::explode(int damages, Manager *, int idBomb)
    {
      this->setPv(this->_pv - damages);
      // annimation je prend des degats.
      if (this->_pv <= 0)
	{
	  Sound::SoundManager *manager = Sound::SoundManager::getInstance();
	  manager->playSound("./resources/sounds/Dying.mp3", false);
	}
    }

    void	Player::setCamera(Display::Camera *camera)
    {
      this->_camera = camera;
    }

    bool	Player::operator==(IGameComponent *otherToCompare)
    {
      if (dynamic_cast<Player *>(otherToCompare) == otherToCompare)
	{
	  Player *other = dynamic_cast<Player *>(otherToCompare);

	  if (other->getPv() == this->_pv && other->getSpeed() == this->_speed && other->getNbBombMax() == this->_nb_bomb_max && other->getNbBombSet() == this->_nb_bomb_set)
	    return (true);
	}
      return (false);
    }

    void	Player::operator=(Player & cpy)
    {
      if (this != &cpy)
	{
	  this->_pv = cpy.getPv();
	  this->_speed = cpy.getSpeed();
	  this->_nb_bomb_max = cpy.getNbBombMax();
	  this->_nb_bomb_set = cpy.getNbBombSet();
	  this->_bomb = cpy.getBomb();
	  this->_walking = cpy.getWalking();
	  this->_mark = cpy.getMark();
	  this->_run = cpy.getRun();
	  this->_camera = cpy.getCamera();
	  this->_isMoving = cpy.getIsMoving();
	  this->_isRunning = cpy.getIsRunning();
	}
    }
  }
}
