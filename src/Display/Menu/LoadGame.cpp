//
// LoadGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 23:21:12 2013 julien fortin
//

#include	"BomberOptions.hh"
#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"LoadGame.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    LoadGame::LoadGame(Core::BomberMan* const core) : _core(core)
    {
      this->_menu = new Menu("resources/images/bg.jpg");
      this->_menu->initialize();
    }

    LoadGame::~LoadGame()
    {
    }

    void	LoadGame::update()
    {
      this->_core->continueGame();
    }

    void	LoadGame::draw()
    {
      this->_menu->affAllOnglet();
    }

    MenuEnum::eMenu	LoadGame::getType() const
    {
      return MenuEnum::LOAD;
    }
  }
}
