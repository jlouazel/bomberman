//
// EventManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 22:23:19 2013 julien fortin
// Last update Sun Jun  9 14:16:55 2013 julien fortin
//

#include	<algorithm>
#include	"IEvent.hh"
#include	"UnixMutex.hh"
#include	"EventManager.hh"
#include	"Pause.hh"
#include	"Move.hh"
#include	"Action.hh"
#include	"EndOfBomberMan.hh"

namespace BomberMan
{
  namespace Event
  {
    EventManager*	EventManager::_eventManager = 0;

    EventManager*	EventManager::getEventManager()
    {
      if (!EventManager::_eventManager)
	_eventManager = new EventManager();
      if (!EventManager::_eventManager)
	throw Core::EndOfBomberMan("EventManager", "getEventManager", "NULL pointer");
      return EventManager::_eventManager;
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

    const IEvent*	EventManager::getEvent()
    {
      const IEvent*	event = 0;

      if (!EventManager::getEventManager()->_eventListMutex->trylock())
	{
	  if (EventManager::getEventManager()->_event.size() > 0)
	    {
	      event = EventManager::getEventManager()->_event.front();
	      EventManager::getEventManager()->_event.pop();
	    }
	  EventManager::getEventManager()->_eventListMutex->unlock();
	}
      return event;
    }

    void		EventManager::addEvent(const IEvent* event)
    {
      if (!EventManager::getEventManager()->_eventListMutex->trylock())
	{
	  EventManager::getEventManager()->_event.push(event);
	  EventManager::getEventManager()->_eventListMutex->unlock();
	}
    }

    void		EventManager::moveEvent(EventDirection::eEventDirection direction,
						float angle, bool run, int playerId)
    {
      EventManager::addEvent(new Move(EventContext::NO, direction, angle, run, playerId));
    }

    void		EventManager::actionEvent(int playerId)
    {
      EventManager::addEvent(new Action(playerId));
    }

    void		EventManager::pauseEvent()
    {
      EventManager::addEvent(new Pause());
    }

    void		EventManager::cleanEvent()
    {
      int nb = this->_event.size() - 1;

      for (int i = 0; i < nb; i++)
	this->_event.pop();
    }
  }
}
