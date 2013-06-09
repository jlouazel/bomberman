//
// QuickGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 02:30:20 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"LaunchGame.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    LaunchGame::LaunchGame(Core::BomberMan* const core) : _core(core)
    {
    }

    LaunchGame::~LaunchGame()
    {
    }

    void	LaunchGame::update()
    {
      if (this->_core)
	this->_core->startGame();
    }

    void	LaunchGame::draw()
    {
    }

    MenuEnum::eMenu	LaunchGame::getType() const
    {
      return MenuEnum::NEWGAME;
    }
  }
}
