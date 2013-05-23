//
// EventMove.hh for bomber in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:18:25 2013 julien fortin
// Last update Thu May 23 10:37:33 2013 julien fortin
//

#ifndef	__DROPITEM_HH__
#define	__DROPITEM_HH__

#include	"AEvent.hh"

namespace BomberMan
{
  namespace Event
  {
    class DropItem : public AEvent
    {
    private:
    protected:
    public:
      virtual ~DropItem();

      DropItem(int, int, EventDirection::eEventDirection);

      virtual void	interaction() const;
    };
  }
}

#endif
