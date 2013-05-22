//
// KeyBoardManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:23:08 2013 julien fortin
// Last update Tue May 21 20:55:39 2013 julien fortin
//

#ifndef	__KEYBOARDMANAGER_HH__
#define	__KEYBOARDMANAGER_HH__

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
      static KeyBoardManager*	_keyboardManager;

    public:
      ~KeyBoardManager();
      KeyBoardManager();

      static KeyBoardManager*	getKeyBoardManager();
      static void		deleteKeyBoardManager();

      static void		keyPressed(unsigned char, int, int);
      static void		specialKeyPressed(int, int, int);
      static void		onMouseClick(int, int, int, int);
    };
  }
}

#endif
