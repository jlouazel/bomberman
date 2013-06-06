//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Thu Jun  6 19:38:13 2013 julien fortin
//

#ifndef	__DROPBOMB_HH__
#define	__DROPBOMB_HH__

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    class DropBomb : public AEvent
    {
    private:
      EventDirection::eEventDirection	_direction;

    protected:
    public:
      DropBomb(EventContext::eEventContext);

      virtual ~DropBomb();
      virtual void			interaction() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class DropBomb;
  }
}

#endif
