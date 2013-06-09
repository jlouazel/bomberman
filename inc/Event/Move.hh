//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Sun Jun  9 13:55:34 2013 julien fortin
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
      float				_angle;
      bool				_run;

    protected:
    public:
      Move(EventContext::eEventContext, EventDirection::eEventDirection, float, bool, int);
      virtual ~Move();


      virtual void			interaction() const;
      int				getAngle() const;
      bool				isRunning() const;
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
