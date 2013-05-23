//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Thu May 23 10:36:34 2013 julien fortin
//

#include	"GetItem.hh"

namespace BomberMan
{
  namespace Event
  {
    GetItem::GetItem(int x, int y, EventDirection::eEventDirection dir)
      : AEvent(x, y, EventType::GET_ITEM, dir)
    {
    }

    GetItem::~GetItem()
    {
    }

    void	GetItem::interaction() const
    {
    }
  }
}
