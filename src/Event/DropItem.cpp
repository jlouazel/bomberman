//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Thu May 23 10:35:19 2013 julien fortin
//

#include	"DropItem.hh"

namespace BomberMan
{
  namespace Event
  {
    DropItem::DropItem(int x, int y, EventDirection::eEventDirection dir)
      : AEvent(x, y, EventType::DROP_ITEM, dir)
    {
    }

    DropItem::~DropItem()
    {
    }

    void	DropItem::interaction() const
    {
    }
  }
}
