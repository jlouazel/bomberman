//
// Core.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman/bomberman/src/Core
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Thu May 23 12:10:00 2013 julien fortin
// Last update Mon May 27 17:25:38 2013 Jean-Baptiste Louazel
//

#include	"BomberMan.hh"
#include	"Core.hh"

namespace BomberMan
{
  namespace Core
  {
    Core::Core()
    {
      Input::InputManager::getInputManager();
      Input::InputManager::init();

      /* Thread video intro */
      /* Initialisation ressources GDL */
      /* Initialise Display */
    }

    Core::~Core()
    {
      Input::InputManager::deleteInputManager();
    }
  }
}
