#include <math.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include "MyGame.hpp"
#include "AObject.hpp"
#include "Vector.hpp"

BomberMan::Display::AObject::AObject(std::string &texture, BomberMan::Display::Vector3f &position, BomberMan::Display::Vector3f &rotation, BomberMan::Display::Vector3f &len, Camera *camera)
  : position_(position), rotation_(rotation), len_(len), camera_(camera)
{
  this->stringTexture_ = texture;
}

void    BomberMan::Display::AObject::setRotation(BomberMan::Display::Vector3f &rotation)
{
  this->rotation_ = rotation;
}

void    BomberMan::Display::AObject::setPosition(BomberMan::Display::Vector3f &position)
{
  this->position_ = position;
}

void    BomberMan::Display::AObject::setLen(BomberMan::Display::Vector3f &len)
{
  this->len_ = len;
}
