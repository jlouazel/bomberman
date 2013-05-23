//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Thu May 23 10:36:51 2013 julien fortin
//

#include	"Move.hh"

namespace BomberMan
{
  namespace Event
  {
    Move::Move(int x, int y, EventDirection::eEventDirection dir, float angle)
      : AEvent(x, y, EventType::MOVE, dir)
    {
      this->_angle = angle;
    }

    Move::~Move()
    {
    }

    int	Move::getAngle() const
    {
      return this->_angle;
    }

    void	Move::interaction() const
    {
    }
  }
}
