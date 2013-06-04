//
//  Manager.cpp
//  BomberMan
//
//  Created by manour_m on 23/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include <sys/types.h>
#include <list>

#include "IGameComponent.hh"
#include "FManager.hh"
#include "Empty.hh"
#include "Resources.hh"
#include "Vector.hpp"
#include "AObject.hpp"
#include "Texture3d.hpp"

namespace BomberMan
{
  namespace Field
  {
    Manager::Manager(unsigned int width, unsigned int height)
      : _width(width), _height(height), _map(width * height, std::list<IGameComponent *>())
    {
      std::vector<std::list<IGameComponent *> >::iterator	it;
      unsigned int i = 0;

      for (it = this->_map.begin(); it != this->_map.end(); it++)
	{
	  // if (i % width == 0)
	  //   {
	  //     Display::Vector3f      vectorPosition((i / width) * 218, 0.0, (i % width) * 218);
	  //     Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
	  //     Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
	  //     (*it).push_front(new Empty(i / width, i % width, new Display::Texture3d("models/Wall1.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	  //   }
	  (*it).push_front(new Empty(i / width, i % width, 0, 0, 0));
	  i++;
	}
    }

    Manager::~Manager()
    {
    }

    std::list<IGameComponent *> &   Manager::get(unsigned int x, unsigned int y)
    {
      unsigned int    pos;

      pos = y * this->_width + x;
      return this->_map[pos];
    }

    unsigned int                    Manager::getWidth() const
    {
      return this->_width;
    }

    unsigned int                    Manager::getHeight() const
    {
      return this->_height;
    }
  }
}
