//
//  Player.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Texture3d.hpp"
#include "Player.hh"

namespace BomberMan
{
  namespace Field
  {
    Player::Player(int pv, float speed, int max, int set, float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
      :   _pv(pv), _speed(speed), _nb_bomb_max(max), _nb_bomb_set(set)
    {
      this->_x = x;
      this->_y = y;
      this->_animation = anim;
      this->_sound = sound;
      this->_asset = asset;
      // this->_asset->initialize();
      this->_bomb = new Object(0.0, 0.0, 0, 0, 0, BOMB, NONE, 3, 3);
      this->_camera = 0; // initialise after.
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
      this->_camera->initialize();
    }

    void	Player::update(gdl::GameClock const & gameClock)
    {
      this->_asset->update(gameClock);

      // Input::Controller::KeyBoardManager::treatInput(input);

      const Event::IEvent* event = Event::EventManager::getEvent();
      if (event != NULL)
	{
	  const Event::Move *move = (const Event::Move *)event;

	  float       angle =  (move->getAngle() + 270) % 360;
	  float       x = cosf(angle * 3.14159265359 / 180) * 10;
	  float       z = sinf(angle * 3.14159265359 / 180) * 10;

	  Display::Vector3f	newVectorPosition(this->_asset->getPosition().getX() + x, this->_asset->getPosition().getY(), this->_asset->getPosition().getZ() + z);
	  Display::Vector3f	newVectorRotation(this->_asset->getRotation().getX(), ((float)-((int)(angle + 270) % 360)), this->_asset->getRotation().getZ());
	  // this->_asset->getPosition().setX(this->_asset->getPosition().getX() + x);
	  // this->_asset->getPosition().setZ(this->_asset->getPosition().getZ() + z);
	  this->_asset->setPosition(newVectorPosition);
	  this->_asset->setRotation(newVectorRotation);
	  // this->_asset->getRotation().setY((float)-((int)(angle + 270) % 360));
	  //this->info();
	  // this->play("Take 001", 1);
	  delete move;
	}
    }

    void	Player::draw(gdl::GameClock const & gameClock, gdl::Input & input)
    {
      this->_asset->draw();
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
