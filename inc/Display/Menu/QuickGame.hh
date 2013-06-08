//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  8 01:25:35 2013 julien fortin
//

#ifndef	__QUICKGAME_HH__
#define	__QUICKGAME_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class QuickGame : public IMenu
    {
    private:
      QuickGame(QuickGame const&);
      QuickGame	&operator=(QuickGame const&);

      Core::BomberMan* const	_core;

    protected:
    public:
      virtual ~QuickGame();
      QuickGame(Core::BomberMan* const);

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
    class QuickGame;
  }
}
#endif
