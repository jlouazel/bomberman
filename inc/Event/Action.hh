//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Fri Jun  7 08:50:16 2013 julien fortin
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
      Action();

      virtual ~Action();
      virtual void			interaction() const;
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
