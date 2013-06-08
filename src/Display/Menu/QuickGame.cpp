//
// QuickGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 01:14:39 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"QuickGame.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    QuickGame::QuickGame(Core::BomberMan* const core) : _core(core)
    {
    }

    QuickGame::~QuickGame()
    {
    }

    void	QuickGame::update()
    {
      if (this->_core)
	this->_core->startGame();
    }

    void	QuickGame::draw()
    {
      if (this->_core)
	this->_core->startGame();
    }

    MenuEnum::eMenu	QuickGame::getType() const
    {
      return MenuEnum::NEWGAME;
    }
  }
}
