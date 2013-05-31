//
// KeyBoardManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:23:08 2013 julien fortin
// Last update Fri May 31 17:34:49 2013 julien fortin
//

#ifndef	__KEYBOARDMANAGER_HH__
#define	__KEYBOARDMANAGER_HH__

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      class KeyBoardManager
      {
      private:
	KeyBoardManager(KeyBoardManager const&);
	KeyBoardManager	&operator=(KeyBoardManager const&);

      private:
	static KeyBoardManager *	_keyboardManager;

      public:
	~KeyBoardManager();
	KeyBoardManager();

	static KeyBoardManager*	getKeyBoardManager();
	static void		deleteKeyBoardManager();
	static void		treatInput(const gl::Input&);
      };
    }
  }
}

#else
namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      class KeyBoardManager;
    }
  }
}

#endif
