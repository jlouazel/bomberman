//
// AEvent.cpp for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:15:08 2013 julien fortin
// Last update Sun Jun  9 13:22:41 2013 julien fortin
//

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    AEvent::AEvent(EventCategory::eEventCategory category,
		   EventContext::eEventContext context,
		   EventType::eEventType type,
		   EventDirection::eEventDirection direction,
		   float x, float y, int playerId)
    {
      this->_category = category;
      this->_context = context;
      this->_direction = direction;
      this->_type = type;
      this->_x = x;
      this->_y = y;
      this->_playerId = playerId;
    }

    AEvent::~AEvent()
    {
    }

    int		AEvent::getPlayerId() const
    {
      return this->_playerId;
    }

    float	AEvent::getX() const
    {
      return this->_x;
    }

    float	AEvent::getY() const
    {
      return this->_y;
    }

    EventCategory::eEventCategory	AEvent::getCategory() const
    {
      return this->_category;
    }

    EventContext::eEventContext		AEvent::getContext() const
    {
      return this->_context;
    }

    EventType::eEventType		AEvent::getType() const
    {
      return this->_type;
    }

    EventDirection::eEventDirection	AEvent::getDirection() const
    {
      return this->_direction;
    }
  }
}
