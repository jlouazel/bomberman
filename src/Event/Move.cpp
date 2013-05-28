//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Tue May 28 11:52:57 2013 julien fortin
//

#include	"Move.hh"

namespace BomberMan
{
    namespace Event
    {
        Move::Move(EventContext::eEventContext context,
                   EventDirection::eEventDirection direction,
                   float angle, float x, float y)
        : AEvent(EventCategory::MOVE,
                 context,
                 EventType::MOVE,
                 direction, x, y)
        {
            this->_angle = angle;
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
        
        void	Move::interaction() const
        {
        }
    }
}
