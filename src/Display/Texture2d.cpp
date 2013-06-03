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
	  // std::cout << "lalala : " << this->stringTexture_ << std::endl;
	  std::cout << "lalal la taille : " << this->len_.getX() << std::endl;
	  this->len_.setX((this->len_.getX() * WIDTH / 100));
	  this->len_.setY((this->len_.getY() * HEIGHT / 100));
	  this->len_.setZ(this->len_.getZ());

	  float posX = this->position_.getX() * WIDTH / 100;
	  float posY = (HEIGHT - (this->position_.getY() * HEIGHT / 100) - this->len_.getY());
	  Vector3f newVector(posX, posY, 0);

	  this->position_.setX(newVector.getX());
	  this->position_.setY(newVector.getY());
	  this->position_.setZ(newVector.getZ());
	  this->texture_ = gdl::Image::load(this->stringTexture_);
        }

      void	Texture2d::update(gdl::GameClock const &gameClock)
      {
	(void)gameClock;
      }

      void	Texture2d::draw(void)
      {
	// std::cout << this->stringTexture_ << std::endl;
	std::cout << "Len X = " << this->len_.getX() << std::endl;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	this->texture_.bind();
	glMatrixMode (GL_PROJECTION);
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
	glFlush();
      }
    }
}
