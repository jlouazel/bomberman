//
//  Empty.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Vector.hpp"
#include "Empty.hh"
#include "FManager.hh"
#include "Texture3d.hpp"

namespace BomberMan
{
  namespace Field
    {
      Empty::Empty(float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
      {
	Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
	Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
	Display::Vector3f      vectorPosition(x * 220, 0.0, y * 220);

	this->_x = x;
	this->_y = y;
	if (asset == 0)
	  this->_asset = new Display::Texture3d("models/Floor.fbx", vectorPosition, vectorRot, vectorLen);
	else
	  this->_asset = asset;
	this->_asset->initialize();
	this->_sound = sound;
	this->_animation = anim;
	this->_explosion = false;
	this->_end = false;
      }

      Empty::~Empty()
      {
      }

      void        Empty::update(gdl::GameClock const & gameClock, Manager *manager)
      {
	this->_asset->update(gameClock);
      }

      void        Empty::draw(gdl::GameClock const & gameClock)
      {
	// std::cout << "Start draw Empty" << std::endl;
	this->_asset->draw();
	// std::cout << "End draw Empty" << std::endl;
      }

      void    Empty::explode(int damages)
      {
      }

      bool	Empty::operator==(IGameComponent *other)
      {
	if (dynamic_cast<Empty *>(other) == other)
	  if (other->getX() == this->_x && other->getY() == this->_y)
	    return (true);
	return (false);
      }
  }
}
