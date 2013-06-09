//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 01:54:29 2013 julien fortin
//

#ifndef	__LAUNCHGAME_HH__
#define	__LAUNCHGAME_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class LaunchGame : public IMenu
    {
    private:
      LaunchGame(LaunchGame const&);
      LaunchGame	&operator=(LaunchGame const&);

      Core::BomberMan* const	_core;

    protected:
    public:
      virtual ~LaunchGame();
      LaunchGame(Core::BomberMan* const);

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
    class LaunchGame;
  }
}
#endif
