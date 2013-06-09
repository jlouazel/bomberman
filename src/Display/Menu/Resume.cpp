//
// QuickGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 15:08:03 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"Resume.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    Resume::Resume(Core::BomberMan* const core) : _core(core)
    {
    }

    Resume::~Resume()
    {
    }

    void	Resume::update()
    {
      if (this->_core)
	this->_core->resumeGame();
    }

    void	Resume::draw()
    {
    }

    MenuEnum::eMenu	Resume::getType() const
    {
      return MenuEnum::RESUME;
    }
  }
}
