//
// MainMenu.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  1 21:32:22 2013 julien fortin
//

#ifndef	__MAINMENU_HH__
#define	__MAINMENU_HH__

#include	"IMenu.hh"

namespace BomberMan
{
  namespace Display
  {
    class MainMenu : public IMenu
    {
    private:
      MainMenu(MainMenu const&);
      MainMenu	&operator=(MainMenu const&);

    protected:
    public:
      virtual ~MainMenu();
      MainMenu();

      virtual void	update();
      virtual void	draw() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class MainMenu;
  }
}
#endif
