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

    void        Player::move()
    {
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

    void	Player::update(gdl::GameClock const & gameClock)
    {
      this->_asset->update(gameClock);

      if (this->_isMoving == false)
	{
	  this->_asset->play("Take 001", 1);
	  this->_asset->update(gameClock);
	}
      else
	{
	  this->_walking->play("Take 001", 1);
	  this->_walking->update(gameClock);
	}
      this->_mark->play("Take 001", 1);
      this->_mark->update(gameClock);
      // Input::Controller::KeyBoardManager::treatInput(input);

      const Event::IEvent* event = Event::EventManager::getEvent();
      if (event != NULL)
	{
	  const Event::Move *move = (const Event::Move *)event;
	  this->_isMoving = true;
	  std::cout << move->getAngle() << std::endl;
	  float       angle =  move->getAngle() * 3.14159 / 180.0;
	  float       x = -(cosf(angle) * 14);
	  float       z = sinf(angle) * 14;

	  // std::cout << "YOOOOOOOOOOO : " << angle << std::endl;
	  Display::Vector3f	newVectorPosition(this->_asset->getPosition().getX() + x, this->_asset->getPosition().getY(), this->_asset->getPosition().getZ() + z);
	  Display::Vector3f	newVectorRotation(this->_asset->getRotation().getX(), static_cast<int>(angle * 180.0 / 3.14159 + 270) % 360, this->_asset->getRotation().getZ());
	  this->_asset->setPosition(newVectorPosition);
	  this->_asset->setRotation(newVectorRotation);
	  this->_walking->setPosition(newVectorPosition);
	  this->_walking->setRotation(newVectorRotation);
	  this->_mark->setPosition(newVectorPosition);
	  this->_camera->setLook(newVectorPosition);
	  newVectorPosition.setX(newVectorPosition.getX() + this->_camera->getDistanceX());
	  newVectorPosition.setY(newVectorPosition.getY() + this->_camera->getDistanceY());
	  this->_camera->setPosition(newVectorPosition);
	  delete move;
	}
      else
	{
	  this->_isMoving = false;
	}
      //std::cout << "End update Player" << std::endl;
    }

    void	Player::draw(gdl::GameClock const & gameClock, gdl::Input & input)
    {
      //std::cout << "Start Draw player" << std::endl;
      if (this->_isMoving == false)
	this->_asset->draw();
      else
	this->_walking->draw();
      this->_mark->draw();
      this->_camera->update(gameClock, input);
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
