//
// EventManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 14 15:29:51 2013 julien fortin
// Last update Tue May 28 11:50:53 2013 julien fortin
//

#ifndef	__EVENTMANAGER_HH__
#define	__EVENTMANAGER_HH__

#include	<queue>
#include	"EventEnum.hh"
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
      EventManager &	operator=(EventManager const&);

      void	_deleteEvent(IEvent const *) const;
      void	_deleteQueue(std::queue<const IEvent*>&);

    private:
      static EventManager*	_eventManager;

      std::queue<const IEvent*>	_event;
      std::queue<const IEvent*>	_eventMenu;
      BomberMan::Unix::IMutex*	_eventListMutex;
      bool						_menuMode;

    protected:
    public:
      ~EventManager();
      EventManager();

      static void			setMenuMode(bool);

      static const IEvent*	getEvent();
      static EventManager*	getEventManager();
      static void			deleteEventManager();

      static void			addEvent(const IEvent*);
      static void			moveEvent(EventDirection::eEventDirection, float, float, float);
    };
  }
}

#endif
