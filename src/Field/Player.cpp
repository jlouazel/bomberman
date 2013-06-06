//
//  Player.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "AObject.hpp"
#include "Texture3d.hpp"
#include "Player.hh"
#include "Vector.hpp"
#include "Wall.hh"

namespace BomberMan
{
  namespace Field
  {
    Player::Player(int pv, float speed, int max, int set, float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
      :   _pv(pv), _speed(speed), _nb_bomb_max(max), _nb_bomb_set(set)
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
      this->_bomb = new Object(0.0, 0.0, 0, 0, 0, BOMB, NONE, 3, 3);
      this->_camera = 0; // initialise after.
      this->_isMoving = false;
    }

    Player::~Player()
    {
      delete this->_bomb;
    }

    void        Player::move(float x, float z, float angle)
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
      this->_mark->setPosition(newVectorPosition);
      this->_camera->setLook(newVectorPosition);
      newVectorPosition.setX(newVectorPosition.getX() + this->_camera->getDistanceX());
      newVectorPosition.setY(newVectorPosition.getY() + this->_camera->getDistanceY());
      this->_camera->setPosition(newVectorPosition);
    }

    void        Player::setBomb()
    {
    }

    void        Player::acquireObject()
    {
    }

    void	Player::initialize()
    {
      this->_asset->initialize();
      this->_walking->initialize();
      this->_mark->initialize();
      this->_run->initialize();
      this->_mark->setColor(0, 0, 255);
      this->_camera->initialize();
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
		  {
		    std::cout << "Wall here : X = " << (*it)->getX() << " Y = " << (*it)->getY() << " Player here : X = "<< static_cast<int>((x + 110) / 220) << " Y = " << static_cast<int>((z + 110) / 220) << std::endl;
		    if (static_cast<int>((x + 110) / 220) == (*it)->getX() && static_cast<int>((z + 110) / 220) == (*it)->getY())
		      return (false);
		  }
		  // std::cout << "x = " << (*it)->getX() << " X = " << (this->_x + 110) / 220 << std::endl;;
	      }
	    // std::cout << "End of the case" << std::endl;
	  }
      return (true);
    }

    void	Player::update(gdl::GameClock const & gameClock, Manager *manager)
    {
      // Input::Controller::KeyBoardManager::treatInput(input);

      const Event::IEvent* event = Event::EventManager::getEvent();
      if (event != NULL)
	{
	  const Event::Move *move = (const Event::Move *)event;
	  this->_isRunning = move->isRunning();
	  this->_isMoving = true;
	  float       angle =  move->getAngle() * 3.14159 / 180.0;
	  float       x = -(cosf(angle) * this->_speed);
	  float       z = sinf(angle) * this->_speed;

	  if (this->checkMyMove(this->_asset->getPosition().getZ() + z, this->_asset->getPosition().getX() + x, manager) == true)
	    this->move(x, z, angle);
	  else
	    {
	      if (this->checkMyMove(this->_asset->getPosition().getZ(), this->_asset->getPosition().getX() + x, manager) == true)
		this->move(x, 0, angle);
	      else if (this->checkMyMove(this->_asset->getPosition().getZ() + z, this->_asset->getPosition().getX(), manager) == true)
		this->move(0, z, angle);
	    }
	  delete move;
	}
      else
	{
	  this->_isMoving = false;
	  this->_isRunning = false;
	}
      if (this->_isRunning == true)
	{
	  this->_run->play("Take 001", 1);
	  this->_walking->stop("Take 001");
	  this->_speed = 30;
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
      //std::cout << "End update Player" << std::endl;
    }

    void	Player::draw(gdl::GameClock const & gameClock)
    {
      //std::cout << "Start Draw player" << std::endl;
      if (this->_isRunning == true)
	this->_run->draw();
      else if (this->_isMoving == true)
	this->_walking->draw();
      else
	this->_asset->draw();
      this->_mark->draw();
      this->_camera->update(gameClock);
      //std::cout << "End Draw player" << std::endl;
    }

    void        Player::run()
    {
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

    void        Player::explode(int damages, eDirection direction)
    {
      static_cast<void>(direction);
      this->setPv(this->_pv - damages);
      // animation dmg
      if (this->_pv <= 0)
	std::cout << "J'suis mort" << std::endl;
    }

    void	Player::setCamera(Display::Camera *camera)
    {
      this->_camera = camera;
    }
  }
}
