//
// Event.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 14 17:55:11 2013 julien fortin
// Last update Thu May 30 18:38:11 2013 Jean-Baptiste Louazel
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
            float								_x;
            float								_y;
            EventType::eEventType				_type;
            EventContext::eEventContext			_context;
            EventDirection::eEventDirection		_direction;
            EventCategory::eEventCategory		_category;
            
        public:
            virtual ~AEvent();
            
            AEvent(EventCategory::eEventCategory,
                   EventContext::eEventContext,
                   EventType::eEventType,
                   EventDirection::eEventDirection,
                   float, float);
            
            virtual void							interaction() const = 0;
            virtual float							getX() const;
            virtual float							getY() const;
            virtual EventType::eEventType			getType() const;
            virtual EventDirection::eEventDirection	getDirection() const;
            virtual EventContext::eEventContext		getContext() const;
            virtual EventCategory::eEventCategory	getCategory() const;
        };
    }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class AEvent;
  }
}

#endif
