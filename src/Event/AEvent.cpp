//
// AEvent.cpp for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:15:08 2013 julien fortin
// Last update Thu May 23 10:35:03 2013 julien fortin
//

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    AEvent::AEvent(int x, int y, EventType::eEventType type, EventDirection::eEventDirection dir)
    {
      this->_x = x;
      this->_y = y;
      this->_type = type;
      this->_direction = dir;
    }

    AEvent::~AEvent()
    {
    }

    int	AEvent::getX() const
    {
      return this->_x;
    }

    int	AEvent::getY() const
    {
      return this->_y;
    }

    EventType::eEventType	AEvent::getType() const
    {
      return this->_type;
    }

    EventDirection::eEventDirection	AEvent::getDirection() const
    {
      return this->_direction;
    }
  }
}
