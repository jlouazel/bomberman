//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Sun Jun  9 21:14:31 2013 julien fortin
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

    void	Pause::interaction(bool finish) const
    {
      if (finish)
	Core::BomberMan::getCore()->startMenu(Display::MenuEnum::MAIN);
      else
	Core::BomberMan::getCore()->startMenu(Display::MenuEnum::PAUSE);
    }
  }
}
