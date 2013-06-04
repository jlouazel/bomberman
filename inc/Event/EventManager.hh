#ifndef	__EVENTMANAGER_HH__
#define	__EVENTMANAGER_HH__

#include	<queue>

#include	"EventEnum.hh"
#include	"IEvent.hh"
#include	"IMutex.hh"

namespace BomberMan
{
  namespace Event
  {
    class EventManager
    {
    private:
      EventManager(EventManager const&);
      EventManager	&operator=(EventManager const&);

      void	_deleteEvent(IEvent const *) const;
      void	_deleteQueue(std::queue<const IEvent*>&);

    private:
      static EventManager*	_eventManager;

      std::queue<const IEvent*>	_event;
      std::queue<const IEvent*>	_eventMenu;
      BomberMan::Unix::IMutex*	_eventListMutex;
      bool			_menuMode;

    protected:
    public:
      ~EventManager();
      EventManager();

      static void			setMenuMode(bool);

      static const IEvent*		getEvent();
      static EventManager*		getEventManager();
      static void			deleteEventManager();

      static void			addEvent(const IEvent*);

      void			moveEvent(EventDirection::eEventDirection,
						  float, float, float);
      void			actionEvent(EventDirection::eEventDirection,
						    float, float);
      void			gameEvent(EventDirection::eEventDirection,
						  EventType::eEventType,
						  float, float);
      void			coreEvent(EventType::eEventType);
      void			cleanEvent();
    };
  }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class EventManager;
  }
}

#endif
