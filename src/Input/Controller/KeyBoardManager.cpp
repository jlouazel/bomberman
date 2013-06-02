//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Sun Jun  2 20:26:30 2013 julien fortin
//

#include	"EventManager.hh"
#include	"KeyBoardManager.hh"
#include	"EndOfBomberMan.hh"

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      KeyBoardManager*	KeyBoardManager::_keyboardManager = 0;

      KeyBoardManager*	KeyBoardManager::getKeyBoardManager()
      {
	if (!KeyBoardManager::_keyboardManager)
	  KeyBoardManager::_keyboardManager = new KeyBoardManager();
	if (!KeyBoardManager::_keyboardManager)
	  throw Core::EndOfBomberMan("KeyBoardManager", "getKeyBoardManager", "NULL pointer");
	return KeyBoardManager::_keyboardManager;
      }

      void		KeyBoardManager::deleteKeyBoardManager()
      {
	delete KeyBoardManager::_keyboardManager;
	KeyBoardManager::_keyboardManager = 0;
      }

      KeyBoardManager::KeyBoardManager()
      {
      }

      KeyBoardManager::~KeyBoardManager()
      {
      }
    }
  }
}
