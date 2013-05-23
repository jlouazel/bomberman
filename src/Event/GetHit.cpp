//
// EventMove.cpp for bomber in /home/fortin_j/tek2/projects/bomberman/event
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 16:21:04 2013 julien fortin
// Last update Thu May 23 10:36:17 2013 julien fortin
//

#include	"GetHit.hh"

namespace BomberMan
{
  namespace Event
  {
    GetHit::GetHit(int x, int y, EventDirection::eEventDirection dir)
      : AEvent(x, y, EventType::GET_HIT, dir)
    {
    }

    GetHit::~GetHit()
    {
    }

    void	GetHit::interaction() const
    {
    }
  }
}
