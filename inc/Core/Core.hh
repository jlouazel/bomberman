#ifndef BomberMan_Core_h
#define BomberMan_Core_h

#include <list>

#include "InputManager.hh"
#include "EventManager.hh"
#include "CoreError.hh"
#include "FManager.hh"

namespace BomberMan
{
  namespace Engine
  {
    class Core
    {
    private:
      //Field::Manager * _manager;


    public:
      Core();
      ~Core();

      void	update();
    };
  }
}

#else
namespace BomberMan
{
  namespace Engine
  {
    class Core;
  }
}

#endif
