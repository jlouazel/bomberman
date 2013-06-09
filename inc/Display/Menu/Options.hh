//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 23:02:47 2013 julien fortin
//

#ifndef	__OPTIONSMENU_HH__
#define	__OPTIONSMENU_HH__

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
    class Options : public IMenu
    {
    private:
      Options(Options const&);
      Options	&operator=(Options const&);

      Menu*			_menu;
      unsigned int		_cursor;
      unsigned int		_cursorNbPlayer;
      Core::BomberMan* const	_core;

      std::map<unsigned int, IOnglet*>	_kb;
      std::map<unsigned int, IOnglet*>	_hover;

      void	_cursorMove();
      void	_cursorRight();
      void	_cursorLeft();

      static const unsigned int	_nbOnglet = 1;

    public:


    protected:
    public:
      virtual ~Options();
      Options(Core::BomberMan* const);

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
    class Options;
  }
}
#endif
