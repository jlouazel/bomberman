//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Sun Jun  9 13:54:34 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Pause.hh"

namespace BomberMan
{
  namespace Event
  {
    Pause::Pause()
      : AEvent(EventCategory::GAME,
	       EventContext::GAME,
	       EventType::PAUSE,
	       EventDirection::NO, 0, 0, -1)
    {
    }

    Pause::~Pause()
    {
    }

    void	Pause::interaction() const
    {
      Display::MenuManager::getMenuManager()->menu(Display::MenuEnum::PAUSE);
    }
  }
}
