//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 15:19:07 2013 julien fortin
//

#ifndef	__SURRENDER_HH__
#define	__SURRENDER_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class Surrender : public IMenu
    {
    private:
      Surrender(Surrender const&);
      Surrender	&operator=(Surrender const&);

      Core::BomberMan* const	_core;

    protected:
    public:
      virtual ~Surrender();
      Surrender(Core::BomberMan* const);

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
    class Surrender;
  }
}
#endif
