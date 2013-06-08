#ifndef __IONGLET_HPP__
#define __IONGLET_HPP__

#include	"IMenu.hh"

namespace BomberMan
{
  namespace Display
  {
    class	IOnglet
    {
    public:
      virtual ~IOnglet() {};

      virtual AObject*	getImage() const = 0;
      virtual void	affOnglet() const = 0;
      virtual void	initialize() const = 0;
      virtual MenuEnum::eMenu	getMenu() const = 0;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class IOnglet;
  }
}
#endif
