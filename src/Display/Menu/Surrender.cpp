//
// QuickGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 15:18:27 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"Surrender.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    Surrender::Surrender(Core::BomberMan* const core) : _core(core)
    {
    }

    Surrender::~Surrender()
    {
    }

    void	Surrender::update()
    {
      if (this->_core)
	this->_core->surrender();
    }

    void	Surrender::draw()
    {
    }

    MenuEnum::eMenu	Surrender::getType() const
    {
      return MenuEnum::SURRENDER;
    }
  }
}
