//
// BomberGame.cpp for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 02:50:41 2013 julien fortin
// Last update Mon Jun  3 11:28:55 2013 Jean-Baptiste Louazel
//

#include	"BomberGame.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberGame::BomberGame()
    {
      Field::Manager::initInstance(50, 50);
      this->_manager = Field::Manager::getInstance();
    }

    BomberGame::~BomberGame()
    {
    }
  }
}
