//
// NewGame.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 20:56:39 2013 julien fortin
// Last update Sun Jun  9 03:00:34 2013 julien fortin
//

#ifndef	__LOADING_HH__
#define	__LOADING_HH__

#include	"IMenu.hh"
#include	"BomberMan.hh"
#include	"Gif.hpp"

namespace BomberMan
{
  namespace Display
  {
    class Loading : public IMenu
    {
    private:
      Loading(Loading const&);
      Loading	&operator=(Loading const&);

      Gif*	_gif;

    protected:
    public:
      virtual ~Loading();
      Loading();

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
    class Loading;
  }
}
#endif
