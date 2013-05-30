//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Thu May 30 18:39:09 2013 Jean-Baptiste Louazel
//

#ifndef	__MOVE_HH__
#define	__MOVE_HH__

#include	"AEvent.hh"

namespace BomberMan
{
    namespace Event
    {
        class Move : public AEvent
        {
        private:
            EventDirection::eEventDirection	_direction;
            float							_angle;
            
        protected:
        public:
            Move(EventContext::eEventContext, EventDirection::eEventDirection, float, float, float);
            virtual ~Move();
            
            
            virtual void					interaction() const;
            int								getAngle() const;
            EventDirection::eEventDirection	getDirection() const;
        };
    }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class Move;
  }
}

#endif
