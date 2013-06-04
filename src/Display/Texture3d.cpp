#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Model.hpp>
#include <math.h>
#include "AObject.hpp"
#include "Texture3d.hpp"

#include	"EventManager.hh"
#include	"Move.hh"

namespace BomberMan
{
    namespace Display
    {
      Texture3d::Texture3d(const std::string &model, Vector3f &position, Vector3f &rotation, Vector3f &len)
        : AObject(model, position, rotation, len)
      {
      }

      Texture3d::~Texture3d()
      {
	// delete this->model_;
      }

      void	Texture3d::initialize()
      {
	std::cout << "I initialize Model : " << this->stringTexture_ << std::endl;
	this->model_ = gdl::Model::load(this->stringTexture_);
	std::cout << "End of init" << std::endl;
      }

      void	Texture3d::update(gdl::GameClock const & gameClock)
      {
	this->model_.update(gameClock);
        this->play("Take 001", 1);
	if (this->stringTexture_ == "models/WWwalking.fbx")
	  {
	    // this->rotation_.setY((int)(this->rotation_.getY() + 1) % 360);
	    this->position_.setZ(this->position_.getZ() + 20);
	  }
	// Input::Controller::KeyBoardManager::treatInput(input);


	// const Event::IEvent* event = Event::EventManager::getEvent();
	// if (event != NULL)
	//   {
	//     const Event::Move *move = (const Event::Move *)event;
	//     // std::cout << "Angle:" << move->getAngle() << std::endl;
	//     float	angle =  (move->getAngle() + 270) % 360;
	//     float	x = cosf(angle * 3.14159265359 / 180) * 10;
	//     float	z = sinf(angle * 3.14159265359 / 180) * 10;

	//     //std::cout << "angle : " << angle << std::endl;

	//     this->position_.setX(this->position_.getX() + x);
	//     this->position_.setZ(this->position_.getZ() + z);
	//     this->rotation_.setY((float)-((int)(angle + 270) % 360));
	//     //this->info();
	//     this->play("Take 001", 1);
	//     delete move;
	//   }
      }

      void    Texture3d::play(std::string const & name, char state)
      {
	this->model_.play(name, state);
      }

      void    Texture3d::stop(std::string const & name)
      {
	this->model_.stop_animation(name);
      }

      double  Texture3d::get_anim_speed(std::string const &name)
      {
	return (this->model_.get_anim_speed(name));
      }

      void    Texture3d::set_anim_speed(std::string const &name, double speed)
      {
	this->model_.set_anim_speed(name, speed);
      }

      void	Texture3d::draw()
      {
	glLoadIdentity();
	glEnable(GL_BLEND);
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

      void    Texture3d::info()
      {
	this->model_.infos();
      }
    }
}
