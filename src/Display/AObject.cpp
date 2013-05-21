#include <math.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include "MyGame.hpp"
#include "AObject.hpp"
#include "Vector.hpp"

BomberMan::Display::AObject::AObject(std::string &texture, BomberMan::Display::Vector3f &position, BomberMan::Display::Vector3f &len, Camera *camera)
  : rotation_(0.0f, 0.0f, 0.0f), len_(len), camera_(camera)
{
  this->len_.setX((len.getX() * WIDTH / 100));
  this->len_.setY((len.getY() * HEIGHT / 100));
  this->len_.setZ(len.getZ());

  float posX = position.getX() * WIDTH / 100;
  float	posY = (HEIGHT - (position.getY() * HEIGHT / 100) - len_.getY());
  Vector3f newVector(posX, posY, 0);

  this->position_.setX(newVector.getX());
  this->position_.setY(newVector.getY());
  this->position_.setZ(newVector.getZ());
  this->texture_ = gdl::Image::load(texture);
}
