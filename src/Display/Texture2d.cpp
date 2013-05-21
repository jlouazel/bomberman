#include <iostream>
#include <Image.hpp>
#include <math.h>
#include <unistd.h>
#include "Game.hpp"
#include "Texture2d.hpp"

void	BomberMan::Display::Texture2d::initialize()
{
}

void	BomberMan::Display::Texture2d::update(gdl::GameClock const &gameClock, gdl::Input &input)
{
}

void	BomberMan::Display::Texture2d::draw(void)
{
  this->texture_.bind();
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, WIDTH, 0, HEIGHT);
  // std::cout << this->position_.getX() << std::endl;
  // std::cout << this->position_.getY() << std::endl;
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->position_.getX(), this->position_.getY() + this->len_.getY(), 0.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->position_.getX(), this->position_.getY(), 0.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->position_.getX() + this->len_.getX(), this->position_.getY(), 0.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->position_.getX() + this->len_.getX(), this->position_.getY() + this->len_.getY(), 0.0f);
  glEnd();
  glFlush();
}
