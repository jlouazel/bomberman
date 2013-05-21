#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Game.hpp>
#include <GameClock.hpp>
#include <Image.hpp>
#include <Input.hpp>
#include <Model.hpp>
#include <string>
#include <iostream>
#include "Game.hpp"
#include "AObject.hpp"
#include "Texture2d.hpp"
#include "Vector.hpp"
#include "Menu.hpp"

void	BomberMan::Display::MyGame::initialize()
{
  window_.setWidth(WIDTH);
  window_.setHeight(HEIGHT);
  window_.create();
  camera_.initialize();
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void	BomberMan::Display::MyGame::addObject(std::string &texture, Vector3f &position, Vector3f &len)
{
  AObject *newObject = new Texture2d(texture, position, len, &this->camera_);

  this->objects_.push_back(newObject);
}

void	BomberMan::Display::MyGame::setMenu(const Menu &menu)
{
  this->menu_ = menu;
}

BomberMan::Display::Menu	BomberMan::Display::MyGame::getMenu() const
{
  return (this->menu_);
}

BomberMan::Display::Camera  *BomberMan::Display::MyGame::getCamera()
{
  return (&this->camera_);
}

void	BomberMan::Display::MyGame::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  camera_.update(gameClock_, input_);
}

void	BomberMan::Display::MyGame::draw(void)
{
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  // glClearDepth(1.0f);
  // std::list<AObject*>::iterator itb = this->objects_.begin();
  // for (; itb != this->objects_.end(); ++itb)
  //   (*itb)->draw();
  this->menu_.affAllOnglet();
}

void	BomberMan::Display::MyGame::unload(void)
{
}
