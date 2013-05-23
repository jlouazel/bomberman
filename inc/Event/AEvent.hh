//
// Event.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 14 17:55:11 2013 julien fortin
// Last update Thu May 23 10:37:15 2013 julien fortin
//

#ifndef	__AEVENT_HH__
#define	__AEVENT_HH__

#include	"IEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    class AEvent : public IEvent
    {
    private:
      int					_x;
      int					_y;
      EventType::eEventType		_type;
      EventDirection::eEventDirection	_direction;

    protected:
    public:
      virtual ~AEvent();
      AEvent(int, int, EventType::eEventType, EventDirection::eEventDirection);

      virtual void				interaction() const = 0;
      virtual int					getX() const;
      virtual int					getY() const;
      virtual EventType::eEventType		getType() const;
      virtual EventDirection::eEventDirection	getDirection() const;
    };
  }
}

#endif
