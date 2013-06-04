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
    Manager*	Manager::_manager = 0;

    Manager::Manager(unsigned int width, unsigned int height)
      :   _width(width), _height(height), _map(width * height, std::list<IGameComponent *>())
    {
      std::vector<std::list<IGameComponent *> >::iterator	it;
      unsigned int i = 0;
      Display::Vector3f      vectorPosition(0.0, 0.0, 0.0);
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);

      for (it = this->_map.begin(); it != this->_map.end(); it++)
	{
        if (i / width == 0)
        {
            // mur du fond
        }
        else if (i / width == height)
        {
            // mur du fond
        }
        if (i % width == 0)
        {
            // mur de cote
        }
        else if (i % width == width - 1)
        {
            // mur de cote
        }
	  vectorPosition.setX((i / width) * 50);
	  vectorPosition.setZ((i % width) * 50);
	  Display::AObject *newTexture = new Display::Texture3d("libgdl/assets/marvin.fbx", vectorPosition, vectorRot, vectorLen);
	  (*it).push_front(new Empty(i / width, i % width, newTexture, 0, 0));
	  (*it).front()->getAsset()->initialize();
	  i++;
	}
      // for (it = this->_map.begin(); it != this->_map.end(); it++)
      // 	for (std::list<IGameComponent *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
      // 	  (*it2)->getAsset()->initialize();
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
