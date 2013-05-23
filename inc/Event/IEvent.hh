//
// IEvent.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat May 18 18:23:52 2013 julien fortin
// Last update Thu May 23 10:38:52 2013 julien fortin
//

#ifndef	__IEVENT_HH__
#define	__IEVENT_HH__

namespace BomberMan
{
  namespace Event
  {
    struct EventType
    {
      enum eEventType
	{
	  MOVE,
	  DROP_ITEM,
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

    class IEvent
    {
    private:
    protected:
    public:
      virtual ~IEvent() {}

      virtual void				interaction() const = 0;
      virtual int					getX() const = 0;
      virtual int					getY() const = 0;
      virtual EventType::eEventType		getType() const = 0;
      virtual EventDirection::eEventDirection     getDirection() const = 0;
    };
  }
}

#endif
