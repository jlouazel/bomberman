//
//  Wall.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Wall.hh"

namespace BomberMan
{
  namespace Field
  {
    Wall::Wall(bool breakable, int pv, float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
      :   _breakable(breakable), _pv(pv)
    {
      this->_x = x;
      this->_y = y;
      this->_asset = asset;
      this->_asset->initialize();
      this->_sound = sound;
      this->_animation = anim;
    }

    Wall::~Wall()
    {
    }

    void        Wall::update(gdl::GameClock const & gameClock, Manager *manager)
    {
      //this->_asset->update(gameClock);
    }

    void        Wall::draw(gdl::GameClock const & gameClock)
    {
      this->_asset->draw();
    }

    int     Wall::getPv() const
    {
      return this->_pv;
    }

    void    Wall::setPv(int pv)
    {
      this->_pv = pv;
    }

    void    Wall::explode(int damages, eDirection direction, Manager *manager)
    {
      static_cast<void>(direction);
      if (this->_breakable == true)
	{
	  this->_pv -= damages;
	  // changement d'asset (breches?)
	  if (this->_pv < 0)
	    {
	      delete this;
	    }
	}
    }

    bool	Wall::operator==(IGameComponent *otherToCompare)
    {
      if (dynamic_cast<Wall *>(otherToCompare) == otherToCompare)
	{
	  Wall *other = static_cast<Wall *>(otherToCompare);
	  if (other->getX() == this->_x && other->getY() == this->_y && this->_pv == other->getPv())
	    return (true);
	}
      return (false);
    }
  }
}
