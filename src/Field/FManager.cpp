#include <algorithm>
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
#include "Player.hh"

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

    static unsigned int	addWalls(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      std::cout << "width" << width << std::endl;
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      unsigned int nbCuves = 0;
      if (elemCnt % width != 0 || elemCnt / width != height - 1)
	{
	  if ((elemCnt % width) % 2 != 0 && (elemCnt / width) % 2 != 0 && elemCnt % width != width - 1 && elemCnt / width != height - 1)
	    {
	      vectorRot.setY(rand() % 360);
	      components.push_front(new Wall(false, 100, elemCnt / width, elemCnt % width, new Display::Texture3d("models/Cuve.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	      nbCuves++;
	    }
	}
      return nbCuves;
    }

    static unsigned int addEmptyObject(std::list<IGameComponent *> & components, unsigned int width, unsigned int height, unsigned int elemCnt)
    {
      Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f	vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f	vectorPosition((elemCnt / width) * 220, 0.0, (elemCnt % width) * 220);
      components.push_front(new Empty(true, elemCnt / width, elemCnt % width, 0, 0, 0));
      if (elemCnt / width == height - 1)
	{
	  vectorRot.setY(270.0);
	  components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == 0)
	{
	  if (elemCnt / width == height - 1)
	    {
	      vectorRot.setY(270.0);
	      components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/Stairs.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  vectorRot.setY(0);
	  components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      if (elemCnt % width == width - 1)
	{
	  vectorRot.setY(180);
	  components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d(randomiseDecor(), vectorPosition, vectorRot, vectorLen), 0, 0));
	}
      std::cout << elemCnt / width << std::endl;
      if (elemCnt / width == 0)
	{
	  vectorRot.setY(270);
	  if (elemCnt % width == 0)
	    {
	      components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineLeft.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else if (elemCnt % width == width - 1)
	    {
	      components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineRight.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	    }
	  else
	    {
	      if (elemCnt % 2 == 0)
		components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLine.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
	      else
		{
		  static int stat = 100;
		  if (rand() % 100 <= stat)
		    {
		      components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLineBody.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		      stat /= 2;
		    }
		  else
		    components.push_front(new Empty(false, elemCnt / width, elemCnt % width, new Display::Texture3d("models/ExplodedLine2.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		}
	    }
	}
      return addWalls(components, width, height, elemCnt);
    }

    Manager::Manager()
      : _width(0),
	_height(0)
    {
      this->_nbCuves = 0;
      srand(time(0));
      // for (; this->_width < 15 || this->_width > 100; this->_width = rand() % 100);
      // for (; this->_height < 15 || this->_height > 100; this->_height = rand() % 100);

      this->_width = 10;
      this->_height = 10;

      this->_map = std::vector<std::list<IGameComponent *> >(this->_width * this->_height, std::list<IGameComponent *>());
      unsigned int elemCnt = 0;
      for (std::vector<std::list<IGameComponent *> >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
	this->_nbCuves += addEmptyObject(*it, this->_width, this->_height, elemCnt++);
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

    void	Manager::addComponent(unsigned int x, unsigned int y, IGameComponent *newComponent)
    {
      if (dynamic_cast<Object *>(newComponent) == newComponent)
	{
	  Object *tmp = static_cast<Object *>(newComponent);
	  for (std::list<IGameComponent *>::iterator it = this->_map[y * this->_width + x].begin(); it != this->_map[y * this->_width + x].end(); ++it)
	    if (dynamic_cast<Object *>(*it) == *it)
	      return;
	}
      this->_map[y * this->_width + x].push_front(newComponent);
    }

    void	Manager::delComponent(unsigned int x, unsigned int y, IGameComponent *toDel)
    {
      std::list<IGameComponent *> list = this->_map[y * this->_width + x];
      for (std::list<IGameComponent *>::iterator it = this->_map[y * this->_width + x].begin(); it != this->_map[y * this->_width + x].end(); ++it)
      	{
      	  if (toDel == *it)
      	    {
      	      this->_map[y * this->_width + x].erase(it);
      	      return;
      	    }
      	}
    }

    void	Manager::setExplosion(unsigned int x, unsigned int y, int power)
    {
      for (std::list<IGameComponent *>::iterator it = this->_map[y * this->_width + x].begin(); it != this->_map[y * this->_width + x].end(); ++it)
	{
	  if (dynamic_cast<Wall *>(*it) == *it)
	    {
	      Wall *tmp = static_cast<Wall *>(*it);
	      if (tmp->isBreakable() == false)
		return;
	    }
	}
      for (std::list<IGameComponent *>::iterator it = this->_map[y * this->_width + x].begin(); it != this->_map[y * this->_width + x].end(); ++it)
	(*it)->explode(power);
    }

    static unsigned int		getPercent(unsigned int width, unsigned int height, unsigned int nbPlayers, unsigned int percent)
    {
      return 50;
    }

    static bool			isAPlayerHere(std::list<Player *> const & players, unsigned int x, unsigned int y)
    {
      for (std::list<Player *>::const_iterator it = players.begin(); it != players.end(); ++it)
	if ((*it)->getX() == x && (*it)->getY() == y)
	  return true;
      return false;
    }

    static bool			isThereAWallHere(std::list<IGameComponent *> const & place)
    {
      for (std::list<IGameComponent *>::const_iterator it = place.begin(); it != place.end(); ++it)
	if (dynamic_cast<Wall *>(*it) == *it)
	  return true;
      return false;
    }

    static bool		eraseWall(std::list<IGameComponent *> & place)
    {
      for (std::list<IGameComponent *>::iterator it = place.begin(); it != place.end(); ++it)
	if (dynamic_cast<Wall *>(*it) == *it)
	  if (dynamic_cast<Wall *>(*it)->isBreakable() == true)
	    {
	      it = place.erase(it);
	      return true;
	    }
      return false;
    }

    static unsigned int	createPlaceForPlayer(std::vector<std::list<IGameComponent *> >	& map, std::list<Player *> const & players, unsigned int width, unsigned int height)
    {
      unsigned int n;
      for (std::list<Player *>::const_iterator itPl = players.begin(); itPl != players.end(); ++itPl)
      	{
      	  if (static_cast<unsigned int>((*itPl)->getX()) == 0)
	    if (eraseWall(map[1]) == true)
	      n++;
	  else if (static_cast<unsigned int>((*itPl)->getX()) % 2 == 0)
	    if (eraseWall(map[width]) == true)
	      n++;
	  if (static_cast<unsigned int>((*itPl)->getY()) == 0)
	    if (eraseWall(map[width]) == true)
	      n++;
	  n++;
      	}
      return n;
    }

    void			Manager::randomize(std::list<Player *> const & players)
    {
      unsigned int x, y;
      for (y = 0; y != this->_height; y++)
	{
	  for (x = 0; x != this->_width; x++)
	    {
	      unsigned int elemCnt = (x + (y * (this->_width)));
	      if (!(x == 0 && y == this->_height - 1) && isThereAWallHere(this->_map[elemCnt]) == false && isAPlayerHere(players, x, y) == false)
		{
		  Display::Vector3f	vectorLen(0.0, 0.0, 0.0);
		  Display::Vector3f	vectorRot(0.0, randAngle(5), 0.0);
		  Display::Vector3f	vectorPosition((elemCnt / this->_width) * 220, 0.0, (elemCnt % this->_width) * 220);
		  this->_map[elemCnt].push_front(new Wall(true, 1, elemCnt / this->_width, elemCnt % this->_width, new Display::Texture3d("models/Barrel.fbx", vectorPosition, vectorRot, vectorLen), 0, 0));
		}
	    }
	}
      unsigned int nbCases = (this->_width * this->_height) - this->_nbCuves - 1 - createPlaceForPlayer(this->_map, players, this->_width, this->_height);
      unsigned int freeCases = nbCases * (40.0 / 100.0);
      while (nbCases != freeCases)
	if (eraseWall(this->_map[rand() % (this->_width * this->_height)]) == true)
	  nbCases--;
    }
  }
}

