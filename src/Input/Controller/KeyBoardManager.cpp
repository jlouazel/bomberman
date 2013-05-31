//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Fri May 31 16:59:44 2013 julien fortin
//

//#include	<GL/glew.h>
#include	<GL/glut.h>

#include	"EventManager.hh"
#include	"KeyBoardManager.hh"

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
	return KeyBoardManager::_keyboardManager;
      }

      void		KeyBoardManager::deleteKeyBoardManager()
      {
	delete KeyBoardManager::_keyboardManager;
	KeyBoardManager::_keyboardManager = 0;
      }

      KeyBoardManager::KeyBoardManager()
      {
	// glutKeyboardFunc(&KeyBoardManager::keyPressed);
	// glutSpecialFunc(&KeyBoardManager::specialKeyPressed);
	// glutMouseFunc(&KeyBoardManager::onMouseClick);
      }

      KeyBoardManager::~KeyBoardManager()
      {
      }
    }
  }
}
