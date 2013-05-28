//
// EventManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 14 15:29:41 2013 julien fortin
// Last update Tue May 28 17:47:56 2013 julien fortin
//

#include	<algorithm>
#include	"Events.hh"
#include	"IEvent.hh"
#include	"UnixMutex.hh"
#include	"EventManager.hh"

#include	<iostream>

namespace BomberMan
{
  namespace Event
  {
    EventManager*	EventManager::_eventManager = 0;

    EventManager*	EventManager::getEventManager()
    {
      if (!_eventManager)
	_eventManager = new EventManager();
      return _eventManager;
    }

    void		EventManager::deleteEventManager()
    {
      if (_eventManager)
	delete EventManager::_eventManager;
      EventManager::_eventManager = 0;
    }

    EventManager::EventManager()
    {
      this->_menuMode = false;
      this->_eventListMutex = new BomberMan::Unix::UnixMutex(0);
    }

    EventManager::~EventManager()
    {
      this->_deleteQueue(this->_event);
      this->_deleteQueue(this->_eventMenu);
    }

    void	EventManager::_deleteQueue(std::queue<const IEvent*> &_queue)
    {
      while (!_queue.empty())
	{
	  this->_deleteEvent(_queue.front());
	  _queue.pop();
	}
    }

    void  EventManager::_deleteEvent(IEvent const *e) const
    {
      if (e)
	delete e;
      e = 0;
    }

    void		EventManager::setMenuMode(bool b)
    {
      EventManager::getEventManager()->_menuMode = b;
    }

    const IEvent*	EventManager::getEvent()
    {
      const IEvent*	event = 0;

      if (!EventManager::getEventManager()->_eventListMutex->trylock())
	{
	  if (EventManager::getEventManager()->_menuMode)
	    {
	      event = EventManager::getEventManager()->_eventMenu.front();
	      EventManager::getEventManager()->_eventMenu.pop();
	      EventManager::getEventManager()->_eventListMutex->unlock();
	      return event;
	    }
	  event = EventManager::getEventManager()->_event.front();
	  EventManager::getEventManager()->_event.pop();
	  EventManager::getEventManager()->_eventListMutex->unlock();
	}
      return event;
    }

    void		EventManager::addEvent(const IEvent* event)
    {
      if (!EventManager::getEventManager()->_eventListMutex->trylock())
	{
	  if (EventManager::getEventManager()->_menuMode)
	    EventManager::getEventManager()->_eventMenu.push(event);
	  else
	    EventManager::getEventManager()->_event.push(event);
	  EventManager::getEventManager()->_eventListMutex->unlock();
	}
      std::cout << "#" << EventManager::getEventManager()->_event.size() << "\n";
    }

    void		EventManager::moveEvent(EventDirection::eEventDirection direction,
						float angle, float x, float y)
    {
      EventContext::eEventContext	context;  // Core::getContext();

      EventManager::addEvent(new Move(context, direction, angle, x, y));
    }

    void		EventManager::actionEvent(EventDirection::eEventDirection direction,
						  float x, float y)
    {
      EventContext::eEventContext	context; //Core::getContext();

      if (context == EventContext::MENU)
	{ /* VALIDATION DE MENU */ }
      else if (context == EventContext::GAME)
	{ /* POSAGE DE BOMB */ }
      else
	{ /* PENDANT UN CHARGEMENT */ }
    }

    void		EventManager::gameEvent(EventDirection::eEventDirection direction,
						EventType::eEventType type,
						float x, float y)
    {
    }

    void		EventManager::coreEvent(EventType::eEventType type)
    {
    }
  }
}
