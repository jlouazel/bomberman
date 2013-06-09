//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 23:18:48 2013 julien fortin
//

#ifndef	__LOADGAME_HH__
#define	__LOADGAME_HH__

#include	<utility>
#include	<map>
#include	<vector>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class LoadGame : public IMenu
    {
    private:
      LoadGame(LoadGame const&);
      LoadGame	&operator=(LoadGame const&);

      Menu*			_menu;
      unsigned int		_cursor;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_arrow;

    protected:
    public:
      virtual ~LoadGame();
      LoadGame(Core::BomberMan* const);

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
    class LoadGame;
  }
}
#endif
