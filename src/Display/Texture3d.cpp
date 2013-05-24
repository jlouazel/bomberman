#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Model.hpp>
#include "AObject.hpp"
#include "Texture3d.hpp"

BomberMan::Display::Texture3d::Texture3d(std::string &model, BomberMan::Display::Vector3f &position, BomberMan::Display::Vector3f &rotation, BomberMan::Display::Vector3f &len, BomberMan::Display::Camera *camera)
  : AObject(model, position, rotation, len, camera)
{
}

BomberMan::Display::Texture3d::~Texture3d()
{
  // delete this->model_;
}

void	BomberMan::Display::Texture3d::initialize()
{
  this->model_ = gdl::Model::load(this->stringTexture_);
  std::cout << "LALALA" << std::endl;
}

void	BomberMan::Display::Texture3d::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  this->model_.update(gameClock);
}

void	BomberMan::Display::Texture3d::draw()
{
  glLoadIdentity();
  glPushMatrix();
  gdl::Model::Begin();
  glTranslatef(this->position_.getX(), this->position_.getY(), this->position_.getZ());
  glRotatef(this->rotation_.getX(), 1, 0, 0);
  glRotatef(this->rotation_.getY(), 0, 1, 0);
  glRotatef(this->rotation_.getZ(), 0, 0, 1);
  this->model_.draw();
  gdl::Model::End();
  glPopMatrix();
}
