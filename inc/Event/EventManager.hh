//
// EventManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 14 15:29:51 2013 julien fortin
// Last update Thu May 23 10:52:25 2013 julien fortin
//

#ifndef	__EVENTMANAGER_HH__
#define	__EVENTMANAGER_HH__

#include	<queue>
#include	"EventError.hh"
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
      bool			_menuMode;
      BomberMan::Unix::IMutex*	_eventListMutex;

    protected:
    public:
      ~EventManager();
      EventManager();

      static void			setMenuMode(bool);

      static const IEvent*	getEvent();
      static EventManager*	getEventManager();
      static void			deleteEventManager();

      static void			addEvent(const IEvent*);
    };
  }
}

#endif
