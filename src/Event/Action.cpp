//
// EventDropBomb.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Sun Jun  9 14:15:14 2013 julien fortin
//

#include	"Action.hh"

namespace BomberMan
{
  namespace Event
  {
    Action::Action(int playerId)
      : AEvent(EventCategory::ACTION,
	       EventContext::GAME,
	       EventType::ACTION,
	       EventDirection::NO, 0, 0, playerId)
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
