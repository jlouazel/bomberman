//
// IEvent.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat May 18 18:23:52 2013 julien fortin
// Last update Sun Jun  9 13:14:07 2013 julien fortin
//

#ifndef	__IEVENT_HH__
#define	__IEVENT_HH__

#include	"EventEnum.hh"

namespace BomberMan
{
  namespace Event
  {
    class IEvent
    {
    private:
      protected:
      public:
      virtual ~IEvent() {}

      virtual void				interaction() const = 0;
      virtual int				getPlayerId() const = 0;
      virtual float				getX() const = 0;
      virtual float				getY() const = 0;
      virtual EventType::eEventType		getType() const = 0;
      virtual EventContext::eEventContext	getContext() const = 0;
      virtual EventCategory::eEventCategory	getCategory() const = 0;
      virtual EventDirection::eEventDirection	getDirection() const = 0;
    };
  }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class IEvent;
  }
}

#endif
