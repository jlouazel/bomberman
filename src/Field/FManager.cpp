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
    static bool between(unsigned int low, unsigned int high, unsigned int nb)
    {
      if (nb >= low && nb <= high)
	return true;
      return false;
    }

    static std::string const	randomiseWall()
    {
      unsigned int r = rand() % 100;
      if (r >= 0 && r <= 2)
	return "models/Wall3bis1.fbx";
      else
	if (r >= 3 && r <= 15)
	  return "models/Wall3bis2.fbx";
	else
	  if (r >= 16 && r <= 44)
	    return "models/Wall1.fbx";
	  else
	    if (r >= 45 && r <= 73)
	      return "models/Wall2.fbx";
      return "models/Wall3.fbx";
    }

    static void addEmptyObject(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      // std::vector<std::string> textures;
      // textures.push_back("models/Wall1.fbx");
      // textures.push_back("models/Wall2.fbx");
      // textures.push_back("models/Wall3.fbx");
      // textures.push_back("models/Wall3bis1.fbx");
      // textures.push_back("models/Wall3bis2.fbx");
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      components.push_front(new Empty(elemCnt / width, elemCnt % width, 0, 0, 0));
      if (elemCnt / width == height - 1)
	{
	  vectorRot.setY(270.0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseWall(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == 0)
	{
	  vectorRot.setY(0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseWall(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == width - 1)
	{
	  vectorRot.setY(180);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseWall(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
    }

    Manager::Manager()
      : _width(0),
	_height(0)
    {
      srand(time(0));
      for (; this->_width < 15 || this->_width > 100; this->_width = rand() % 100);
      for (; this->_height < 15 || this->_height > 100; this->_height = rand() % 100);

      this->_width = 100;
      this->_height = 100;

      this->_map = std::vector<std::list<IGameComponent *> >(this->_width * this->_height, std::list<IGameComponent *>());
      unsigned int elemCnt = 0;
      for (std::vector<std::list<IGameComponent *> >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
	addEmptyObject(*it, this->_width, this->_height, elemCnt++);
      std::cout << this->_width << "-" << this->_height << std::endl;
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
