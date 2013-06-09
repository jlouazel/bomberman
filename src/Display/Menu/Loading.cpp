//
// Loading.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 02:23:29 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"EndOfBomberMan.hh"
#include	"Loading.hh"

namespace BomberMan
{
  namespace Display
  {
    Loading::Loading()
    {
    }

    Loading::~Loading()
    {
    }

    void	Loading::update()
    {
      MenuManager::getMenuManager()->menu(MenuEnum::LAUNCHGAME);
    }

    void	Loading::draw()
    {
    }

    MenuEnum::eMenu	Loading::getType() const
    {
      return MenuEnum::QUIT;
    }
  }
}
