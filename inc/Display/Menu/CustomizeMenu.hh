//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 20:06:34 2013 julien fortin
//

#ifndef	__CUSTOMIZEMENU_HH__
#define	__CUSTOMIZEMENU_HH__

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
    class CustomizeMenu : public IMenu
    {
    private:
      CustomizeMenu(CustomizeMenu const&);
      CustomizeMenu	&operator=(CustomizeMenu const&);

      Menu*			_menu;
      unsigned int		_cursor;
      unsigned int		_cursorNbPlayer;
      unsigned int		_currentsIA;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_nbPlayer;
      std::map<unsigned int, IOnglet*>	_nbIA;
      std::map<unsigned int, IOnglet*>	_hover;
      std::map<unsigned int, IOnglet*>	_arrow;

      void	_cursorMove();
      void	_cursorRight();
      void	_cursorLeft();

      static const unsigned int	_nbOnglet = 4;

    public:


    protected:
    public:
      virtual ~CustomizeMenu();
      CustomizeMenu(Core::BomberMan* const);

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
    class CustomizeMenu;
  }
}
#endif
