//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Wed Jun  5 01:03:50 2013 julien fortin
//

#include	"Move.hh"

namespace BomberMan
{
  namespace Event
  {
    Move::Move(EventContext::eEventContext context,
	       EventDirection::eEventDirection direction,
	       float angle, bool run)
      : AEvent(EventCategory::MOVE,
	       context,
	       EventType::MOVE,
	       direction, 0, 0)
    {
      this->_angle = angle;
      this->_run = run;
      this->_direction = direction;
    }

    Move::~Move()
    {
    }

    EventDirection::eEventDirection	Move::getDirection() const
    {
      return this->_direction;
    }

    int	Move::getAngle() const
    {
      return this->_angle;
    }

    bool	Move::isRunning() const
    {
      return this->_run;
    }

    void	Move::interaction() const
    {
    }
  }
}
