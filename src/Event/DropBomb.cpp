//
// EventDropBomb.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Thu Jun  6 19:36:40 2013 julien fortin
//

#include	"DropBomb.hh"

namespace BomberMan
{
  namespace Event
  {
    DropBomb::DropBomb(EventContext::eEventContext context)
      : AEvent(EventCategory::MOVE,
	       EventContext::GAME,
	       EventType::DROPBOMB,
	       EventDirection::NO, 0, 0)
    {
    }

    DropBomb::~DropBomb()
    {
    }

    void	DropBomb::interaction() const
    {
    }
  }
}
