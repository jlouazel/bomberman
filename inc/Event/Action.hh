//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Sun Jun  9 21:06:31 2013 julien fortin
//

#ifndef	__ACTION_HH__
#define	__ACTION_HH__

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    class Action : public AEvent
    {
    private:
    protected:
    public:
      Action(int);

      virtual ~Action();
      virtual void			interaction(bool = false) const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class Action;
  }
}

#endif
