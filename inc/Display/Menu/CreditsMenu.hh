//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 06:26:35 2013 julien fortin
//

#ifndef	__CREDITSMENU_HH__
#define	__CREDITSMENU_HH__

#include	"Video.hpp"
#include	"IMenu.hh"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class CreditsMenu : public IMenu
    {
    private:
      CreditsMenu(CreditsMenu const&);
      CreditsMenu	&operator=(CreditsMenu const&);

      Video*	_video;

      gdl::Clock*		_creditTimer;
      int			FPS;
      float			constElapsedTime;

    protected:
    public:
      virtual ~CreditsMenu();
      CreditsMenu();

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
    class CreditsMenu;
  }
}
#endif
