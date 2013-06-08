//
// Quit.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 11:56:31 2013 julien fortin
//

#include	"EndOfBomberMan.hh"
#include	"Quit.hh"

namespace BomberMan
{
  namespace Display
  {
    Quit::Quit()
    {
    }

    Quit::~Quit()
    {
    }

    void	Quit::update()
    {
      //throw Core::EndOfBomberMan("Quit", "QuitMenu", "");
    }

    void	Quit::draw()
    {
      //throw Core::EndOfBomberMan("Quit", "QuitMenu", "");
    }

    MenuEnum::eMenu	Quit::getType() const
    {
      //throw Core::EndOfBomberMan("Quit", "QuitMenu", "");
      return MenuEnum::QUIT;
    }
  }
}
