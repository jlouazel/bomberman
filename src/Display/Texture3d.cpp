#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Model.hpp>
#include "AObject.hpp"
#include "Texture3d.hpp"

BomberMan::Display::Texture3d::Texture3d(std::string &model, BomberMan::Display::Vector3f &position, BomberMan::Display::Vector3f &rotation, BomberMan::Display::Vector3f &len)
  : AObject(model, position, rotation, len)
{
}

BomberMan::Display::Texture3d::~Texture3d()
{
  // delete this->model_;
}

void	BomberMan::Display::Texture3d::initialize()
{
  this->model_ = gdl::Model::load(this->stringTexture_);
}

void	BomberMan::Display::Texture3d::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  this->model_.update(gameClock);
}

void    BomberMan::Display::Texture3d::play(std::string const & name, char state)
{
  this->model_.play(name, state);
}

void    BomberMan::Display::Texture3d::stop(std::string const & name)
{
  this->model_.stop_animation(name);
}

double  BomberMan::Display::Texture3d::get_anim_speed(std::string const &name)
{
  return (this->model_.get_anim_speed(name));
}

void    BomberMan::Display::Texture3d::set_anim_speed(std::string const &name, double speed)
{
  this->model_.set_anim_speed(name, speed);
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

void    BomberMan::Display::Texture3d::info()
{
  this->model_.infos();
}
