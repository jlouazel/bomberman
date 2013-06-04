#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <map>

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
    static void addEmptyObject(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      std::vector<std::string> textures;
      textures.push_back("models/Wall1.fbx");
      textures.push_back("models/Wall2.fbx");
      textures.push_back("models/Wall3.fbx");
      textures.push_back("models/Wall3bis1.fbx");
      textures.push_back("models/Wall3bis2.fbx");
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      components.push_front(new Empty(elemCnt / width, elemCnt % width, 0, 0, 0));
      if (elemCnt / width == height - 1)
	{
	  vectorRot.setY(270.0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(textures[rand() % 5], vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == 0)
	{
	  vectorRot.setY(0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(textures[rand() % 5], vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == width - 1)
	{
	  vectorRot.setY(180);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(textures[rand() % 5], vectorPosition, vectorRot, vectorLen), 0, 0));
	}
    }

    Manager::Manager()
      : _width(0),
	_height(0)
    {
      srand(time(0));
      for (; this->_width < 15 || this->_width > 100; this->_width = rand() % 100);
      for (; this->_height < 15 || this->_height > 100; this->_height = rand() % 100);
      //
      this->_width = 5;
      this->_height = 5;
      //
      this->_map = std::vector<std::list<IGameComponent *> >(this->_width * this->_height, std::list<IGameComponent *>());
      unsigned int elemCnt = 0;
      for (std::vector<std::list<IGameComponent *> >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
	addEmptyObject(*it, this->_width, this->_height, elemCnt++);
      std::cout << this->_width << "-" << this->_height << std::endl;
    }

//       std::vector<std::list<IGameComponent *> >::iterator	it;
//       unsigned int i = 0;


//       for (it = this->_map.begin(); it != this->_map.end(); it++)
// 	{
// 	  Display::Vector3f      vectorPosition((i / width) * 218, 0.0, (i % width) * 218);
// 	  Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
// 	  Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
// 	  (*it).push_front(new Empty(i / width, i % width, 0, 0, 0));
// 	  if (i / width == 0)
// 	    {
// 	      // mur du fond
// 	    }
// 	  else if (i / width == height - 1)
// 	    {
// 	      (*it).push_front(new Empty(i / width, i % width, new Display::Texture3d("models/Wall1.fbx", vectorPosition, vectorLen, vectorRot), 0, 0));
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
// 	  Display::AObject *newTexture = new Display::Texture3d("models/Wall3bis2.fbx", vectorPosition, vectorRot, vectorLen);
// 	  (*it).push_front(new Empty(i / width, i % width, newTexture, 0, 0));
// 	  (*it).front()->getAsset()->initialize();
// 	  i++;
// 	}
// >>>>>>> acffd3899b9a535c8e134ccb3850352c539683ef
//     }
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

    // void Manager::renderMap() const
    // {
    //   Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
    //   Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
    //   Display::Vector3f      vectorPosition((i / width) * 218, 0.0, (i % width) * 218);
    // }
  }
}
