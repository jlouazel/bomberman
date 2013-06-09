//
// EventPause.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Sun Jun  9 12:58:49 2013 julien fortin
//

#ifndef	__PAUSE_HH__
#define	__PAUSE_HH__

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    class Pause : public AEvent
    {
    private:
    protected:
    public:
      Pause();
      virtual ~Pause();
      virtual void	interaction() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Event
  {
    class Pause;
  }
}
#endif
