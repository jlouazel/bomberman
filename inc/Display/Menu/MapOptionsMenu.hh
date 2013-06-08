//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sat Jun  8 15:14:03 2013 julien fortin
//

#ifndef	__MAPOPTIONSMENU_HH__
#define	__MAPOPTIONSMENU_HH__

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
    class MapOptionsMenu : public IMenu
    {
    private:
      MapOptionsMenu(MapOptionsMenu const&);
      MapOptionsMenu	&operator=(MapOptionsMenu const&);

      Menu*			_menu;
      unsigned int		_cursor;
      unsigned int		_cursorNbPlayer;
      int			_currentsIA;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_nbPlayer;
      std::map<unsigned int, IOnglet*>	_nbIA;
      std::map<unsigned int, IOnglet*>	_hover;
      std::map<unsigned int, IOnglet*>	_arrow;

      void	_cursorMove();
      void	_cursorRight();
      void	_cursorLeft();

      static const unsigned int	_nbOnglet = 0;

    public:


    protected:
    public:
      virtual ~MapOptionsMenu();
      MapOptionsMenu(Core::BomberMan* const);

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
    class MapOptionsMenu;
  }
}
#endif
