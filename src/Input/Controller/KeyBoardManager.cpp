//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Thu May 23 10:22:49 2013 julien fortin
//

//#include	<GL/glew.h>
//#include	<GL/glut.h>

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
	//glutKeyboardFunc(&KeyBoardManager::keyPressed);
	//glutSpecialFunc(&KeyBoardManager::specialKeyPressed);
	//glutMouseFunc(&KeyBoardManager::onMouseClic);
      }

      KeyBoardManager::~KeyBoardManager()
      {
      }

      void	KeyBoardManager::keyPressed(unsigned char key, int x, int y)
      {
	(void)key;
	(void)x;
	(void)y;
      }

      void	KeyBoardManager::specialKeyPressed(int key, int x, int y)
      {
	(void)key;
	(void)x;
	(void)y;

	// if (key == GLUT_KEY_LEFT)
	// 	{
	// 	  InputManager::addEvent();
	// 	}
	// ...
      }

      void	KeyBoardManager::onMouseClick(int button, int state, int x, int y)
      {
	(void)button;
	(void)state;
	(void)x;
	(void)y;
      }
    }
  }
}
