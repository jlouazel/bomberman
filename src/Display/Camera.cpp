#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "MyGame.hpp"
#include "Camera.hpp"
#include <iostream>

namespace BomberMan
{
  namespace Display
  {
    Camera::Camera(int config)
      : position_(-180.0f, 420.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f), look_(0.0f, 0.0f, 0.0f)
    {
      this->heightScreen_ = (int)(((tanf(this->angle_ / 2.0) * 300.0) * 2.0));
      this->widthScreen_ = (int)(((tanf(this->angle_ / 2.0) * 300.0) * 2.0));
      this->_config = config;
      if (this->_config == 1)
      	{
	  this->position_.setX(-200);
	  this->position_.setY(520);
	  this->angle_ = 3.14159265359 * 80.0 / 180.0;
      	}
      else
      	{
	  this->position_.setX(-180);
	  this->position_.setY(420);
	  this->angle_ = 3.14159265359 * 80.0 / 180.0;
	}
      this->distanceX = position_.getX();
      this->distanceY = position_.getY();
    }

    void		Camera::initialize()
    {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective((this->angle_ * 180) / 3.14159265359, WIDTH/HEIGHT, 1.0f, 10000.0f);
      gluLookAt(position_.getX(), position_.getY(), position_.getZ(),
		this->look_.getX(), this->look_.getY(), this->look_.getZ(),
		0.0f, 1.0f, 0.0f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LEQUAL);
    }

    void		Camera::update(gdl::GameClock const & gameClock)
    {
      static_cast<void>(gameClock);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective((this->angle_ * 180.0) / 3.14159265359, WIDTH/HEIGHT, 1.0f, 10000.0f);
      gluLookAt(position_.getX(), position_.getY(), position_.getZ(),
		this->look_.getX(), this->look_.getY(), this->look_.getZ(),
		0.0f, 1.0f, 0.0f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LEQUAL);
    }

    int		Camera::getDistanceX() const
    {
      return (this->distanceX);
    }

    int		Camera::getDistanceY() const
    {
      return (this->distanceY);
    }

    Vector3f	Camera::getPosition() const
    {
      return (this->position_);
    }

    Vector3f	Camera::getRotation() const
    {
      return (this->rotation_);
    }

    Vector3f	Camera::getLook() const
    {
      return (this->look_);
    }

    float		Camera::getAngle() const
    {
      return (this->angle_);
    }

    int		Camera::getHeightScreen() const
    {
      return (this->heightScreen_);
    }

    int		Camera::getWidthScreen() const
    {
      return (this->widthScreen_);
    }

    void		Camera::setPosition(Vector3f &position)
    {
      this->position_ = position;
      this->heightScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
      this->widthScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
    }

    void		Camera::setRotation(Vector3f &rotation)
    {
      this->rotation_ = rotation;
    }

    void		Camera::setLook(Vector3f &look)
    {
      this->look_ = look;
    }

    void		Camera::setAngle(float angle)
    {
      this->angle_ = 3.14159265359 * angle / 180;
      this->heightScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
      this->widthScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
    }
  }
}
