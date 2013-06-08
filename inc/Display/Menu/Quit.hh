//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  8 11:52:55 2013 julien fortin
//

#ifndef	__QUIT_HH__
#define	__QUIT_HH__

#include	"IMenu.hh"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class Quit : public IMenu
    {
    private:
      Quit(Quit const&);
      Quit	&operator=(Quit const&);

    protected:
    public:
      virtual ~Quit();
      Quit();

      virtual void		update();
      virtual void		draw();
      virtual MenuEnum::eMenu	getType() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Quit;
  }
}
#endif
