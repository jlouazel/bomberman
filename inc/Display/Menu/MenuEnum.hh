//
// MenuEnum.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:01:45 2013 julien fortin
// Last update Sun Jun  9 14:38:28 2013 julien fortin
//

#ifndef	__MENUENUM_HH__
#define	__MENUENUM_HH__

namespace BomberMan
{
  namespace Display
  {
    struct MenuEnum
    {
      enum eMenu
	{
	  NO,
	  MAIN,
	  LOAD,
	  NEWGAME,
	  LOADING,
	  OPTIONS,
	  CREDITS,
	  QUIT,
	  QUICKGAME,
	  CUSTOMIZE,
	  MAPOPTIONS,
	  COOK,
	  LAUNCHGAME,
	  PAUSE,
	  RESUME,
	  SAVE,
	  SURRENDER,
	};
    };
  }
}

#endif
