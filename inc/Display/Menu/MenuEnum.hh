//
// MenuEnum.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:01:45 2013 julien fortin
// Last update Sat Jun  8 15:02:45 2013 julien fortin
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
	  NEWGAME,
	  LOAD,
	  OPTIONS,
	  CREDITS,
	  QUIT,
	  QUICKGAME,
	  CUSTOMIZE,
	  MAPOPTIONS,
	  COOK,
	  PAUSE
	};
    };
  }
}

#endif