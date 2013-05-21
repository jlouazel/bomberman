#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Game.hpp"
#include "Camera.hpp"

BomberMan::Display::Camera::Camera(void)
  : position_(100.0f, 300.0f, 300.0f), rotation_(0.0f, 0.0f, 0.0f), look_(0.0f, 0.0f, 0.0f)
{
  this->angle_ = 3.14159265359 * 70.0 / 180.0;
  this->heightScreen_ = (int)(((tanf(this->angle_ / 2.0) * 300.0) * 2.0));
  this->widthScreen_ = (int)(((tanf(this->angle_ / 2.0) * 300.0) * 2.0));
}

void		BomberMan::Display::Camera::initialize(void)
{
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

void		BomberMan::Display::Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
}

BomberMan::Display::Vector3f	BomberMan::Display::Camera::getPosition() const
{
  return (this->position_);
}

BomberMan::Display::Vector3f	BomberMan::Display::Camera::getRotation() const
{
  return (this->rotation_);
}

BomberMan::Display::Vector3f	BomberMan::Display::Camera::getLook() const
{
  return (this->look_);
}

float		BomberMan::Display::Camera::getAngle() const
{
  return (this->angle_);
}

int		BomberMan::Display::Camera::getHeightScreen() const
{
  return (this->heightScreen_);
}

int		BomberMan::Display::Camera::getWidthScreen() const
{
  return (this->widthScreen_);
}

void		BomberMan::Display::Camera::setPosition(BomberMan::Display::Vector3f &position)
{
  this->position_ = position;
  this->heightScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
  this->widthScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
}

void		BomberMan::Display::Camera::setRotation(BomberMan::Display::Vector3f &rotation)
{
  this->rotation_ = rotation;
}

void		BomberMan::Display::Camera::setLook(BomberMan::Display::Vector3f &look)
{
  this->look_ = look;
}

void		BomberMan::Display::Camera::setAngle(float angle)
{
  this->angle_ = 3.14159265359 * angle / 180;
  this->heightScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
  this->widthScreen_ = (int)((tanf(this->angle_ / 2) * this->position_.getZ()) * 2);
}
