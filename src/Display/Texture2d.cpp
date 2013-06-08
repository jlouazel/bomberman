#include <iostream>
#include <Image.hpp>
#include <math.h>
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "MyGame.hpp"
#include "Texture2d.hpp"

namespace BomberMan
{
    namespace Display
    {
        void	Texture2d::initialize()
        {
	  this->len_.setX((this->len_.getX() * WIDTH / 100));
	  this->len_.setY((this->len_.getY() * HEIGHT / 100));
	  this->len_.setZ(this->len_.getZ());

	  float posX = this->position_.getX() * WIDTH / 100;
	  float posY = (HEIGHT - (this->position_.getY() * HEIGHT / 100) - this->len_.getY());
	  Vector3f newVector(posX, posY, 0);

	  this->position_.setX(newVector.getX());
	  this->position_.setY(newVector.getY());
	  this->position_.setZ(newVector.getZ());
	  this->_texture = gdl::Image::load(this->stringTexture_);
        }

      void	Texture2d::setPosition(Vector3f& position)
      {
	  float posX = position.getX() * WIDTH / 100;
	  float posY = (HEIGHT - (position.getY() * HEIGHT / 100) - this->len_.getY());
	  Vector3f newVector(posX, posY, 0);

	  this->position_.setX(newVector.getX());
	  this->position_.setY(newVector.getY());
	  this->position_.setZ(newVector.getZ());
      }

      void	Texture2d::update(gdl::GameClock const &)
      {
      }

      void	Texture2d::draw(void)
      {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	this->_texture.bind();
	glMatrixMode (GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
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
	glPopMatrix();
	glFlush();
      }
    }
}
