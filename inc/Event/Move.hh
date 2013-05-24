//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Thu May 23 13:14:48 2013 julien fortin
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
      float	_angle;

    protected:
    public:
      virtual ~Move();

      Move(int, int, EventDirection::eEventDirection, float);

      virtual void	interaction() const;
      int			getAngle() const;
    };
  }
}

#endif