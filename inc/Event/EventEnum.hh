//
// enum.hh for bomber in /home/fortin_j/tek2/projects/bomberman/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat May 25 10:47:04 2013 julien fortin
// Last update Thu Jun  6 19:39:53 2013 julien fortin
//

#ifndef	__EVENT_ENUM_HH__
#define	__EVENT_ENUM_HH__

namespace BomberMan
{
  namespace Event
  {
    struct EventContext
    {
      enum eEventContext
	{
	  LOADING,
	  MENU,
	  GAME
	};
    };

    struct EventCategory
    {
      enum eEventCategory { ACTION, MOVE, GAME, CORE };
    };

    struct EventType
    {
      enum eEventType
	{
	  VALIDATION,
	  MOVE,
	  DROPBOMB,
	  GET_ITEM,
	  GET_HIT,
	  COLLISION,
	  DEATH,
	  PAUSE,
	  QUIT,
	  JOIN_CONTROLLER,
	  DETACH_CONTROLLER,
	  FAIL_INPUT, //fail select et ou scandir
	};
    };

    struct EventDirection
    {
      enum eEventDirection
	{
	  NO,
	  EVRWH,
	  UP,
	  DOWN,
	  LEFT,
	  RIGHT,
	  UP_LEFT,
	  UP_RIGHT,
	  DOWN_LEFT,
	  DOWN_RIGHT
	};
    };
  }
}

#endif
