#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include "Wall.hh"
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
    static std::string const	randomiseDecor()
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

    static int	randAngle(unsigned int plage)
    {
      unsigned int angle = rand() % 360;
      if (angle > 90 && angle < 180)
	{
	  if (rand() % 100 < 50)
	    angle = 90 + rand() % plage;
	  else
	    angle = 90 - rand() % plage;
	}
      else
	{
	  if (rand() % 100 < 10)
	    angle = 0 + rand() % plage;
	  else
	    angle = 0 - rand() % plage;
	}
      return angle;
    }

    static void	addWalls(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      if (elemCnt % width != 0 || elemCnt / width != height - 1)
	{
	  if ((elemCnt % width) % 2 != 0 && (elemCnt / width) % 2 != 0)
	    {
	      vectorRot.setY(rand() % 360);
	      components.push_front(new Wall(false, 100, elemCnt / width, elemCnt % width, new Display::Texture3d("models/Cuve.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else
	    {
	      if (rand() % 100 <= 10)
		{
		  vectorRot.setY(randAngle(5));
		  components.push_front(new Wall(true, 100, elemCnt / width, elemCnt % width, new Display::Texture3d("models/Barrel.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		}
	    }
	}
    }

    static void addEmptyObject(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      std::cout << "elem no " << elemCnt << std::endl;
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      components.push_front(new Empty(elemCnt / width, elemCnt % width, 0, 0, 0));
      if (elemCnt / width == height - 1)
	{
	  vectorRot.setY(270.0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == 0)
	{
	  if (elemCnt / width == height - 1)
	    {
	      vectorRot.setY(270.0);
	      components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/Stairs.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  vectorRot.setY(0);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == width - 1)
	{
	  vectorRot.setY(180);
	  components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      std::cout << elemCnt / width << std::endl;
      if (elemCnt / width == 0)
	{
	  vectorRot.setY(270);
	  if (elemCnt % width == 0)
	    {
	      std::cout << "LEFT" << std::endl;
	      components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineLeft.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else if (elemCnt % width == width - 1)
	    {
	      std::cout << "RIGHT" << std::endl;
	      components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineRight.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else
	    {
	      std::cout << "LINE" << std::endl;
	      if (elemCnt % 2 == 0)
		components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLine.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	      else
		{
		  static int stat = 100;
		  if (rand() % 100 <= stat)
		    {
		      components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineBody.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		      stat /= 2;
		}
		  else
		    components.push_front(new Empty(elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLine2.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		}
	    }
	}
      addWalls(components, width, height, elemCnt);
    }

    Manager::Manager()
      : _width(0),
	_height(0)
    {
      srand(time(0));
      // for (; this->_width < 15 || this->_width > 100; this->_width = rand() % 100);
      // for (; this->_height < 15 || this->_height > 100; this->_height = rand() % 100);

      this->_width = 3;
      this->_height = 3;

      this->_map = std::vector<std::list<IGameComponent *> >(this->_width * this->_height, std::list<IGameComponent *>());
      unsigned int elemCnt = 0;
      for (std::vector<std::list<IGameComponent *> >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
	addEmptyObject(*it, this->_width, this->_height, elemCnt++);
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
