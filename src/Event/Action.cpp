//
// EventDropBomb.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Fri Jun  7 08:54:03 2013 julien fortin
//

#include	"Action.hh"

namespace BomberMan
{
  namespace Event
  {
    Action::Action()
      : AEvent(EventCategory::ACTION,
	       EventContext::GAME,
	       EventType::ACTION,
	       EventDirection::NO, 0, 0)
    {
    }

    Action::~Action()
    {
    }

    void	Action::interaction() const
    {
    }
  }
}
