#include <sys/types.h>
#include <cstdlib>
#include <ctime>
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
    Manager::Manager()
    {
    }
    // Manager::Manager(unsigned int width, unsigned int height)
    //   : _width(width), _height(height), _map(width * height, std::list<IGameComponent *>())
    // {
    //   this->generate();
    //   std::vector<std::list<IGameComponent *> >::iterator	it;
    //   unsigned int i = 0;

    //   for (it = this->_map.begin(); it != this->_map.end(); it++)
    // 	{
    // 	  Display::Vector3f      vectorPosition((i / width) * 218, 0.0, (i % width) * 218);
    // 	  Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
    // 	  Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
    // 	  (*it).push_front(new Empty(i / width, i % width, 0, 0, 0));
    // 	  if (i / width == 0)
    // 	    {
    // 	      // mur du fond
    // 	    }
    // 	  else if (i / width == height)
    // 	    {
    // 	      // mur du fond
    // 	    }
    // 	  if (i % width == 0)
    // 	    {
    // 	      // mur de cote
    // 	    }
    // 	  else if (i % width == width - 1)
    // 	    {
    // 	      // mur de cote
    // 	    }
    // 	  vectorPosition.setX((i / width) * 50);
    // 	  vectorPosition.setZ((i % width) * 50);
    // 	  // Display::AObject *newTexture = new Display::Texture3d("libgdl/assets/marvin.fbx", vectorPosition, vectorRot, vectorLen);
    // 	  // (*it).push_front(new Empty(i / width, i % width, newTexture, 0, 0));
    // 	  // (*it).front()->getAsset()->initialize();
    // 	  i++;
    // 	}
    // }

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

    // void	Manager::generate()
    // {
    //   srand(time(0));
    //   for (; this->_width < 10 || this->_width > 100; this->_width = rand() % 100);
    //   for (; this->_height < 10 || this->_height > 100; this->_height = rand() % 100);
    //   std::cout << "wdth >>" << this->_width << std::endl;
    //   std::cout << "hght >>" << this->_height << std::endl;
    // }
  }
}
