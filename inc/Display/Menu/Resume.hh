//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 14:57:40 2013 julien fortin
//

#ifndef	__RESUME_HH__
#define	__RESUME_HH__

#include	<map>
#include	"IMenu.hh"
#include	"Menu.hpp"
#include	"BomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    class Resume : public IMenu
    {
    private:
      Resume(Resume const&);
      Resume	&operator=(Resume const&);

      Core::BomberMan* const	_core;

    protected:
    public:
      virtual ~Resume();
      Resume(Core::BomberMan* const);

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
    class Resume;
  }
}
#endif
