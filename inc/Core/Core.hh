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
      Core();
      ~Core();

    private:
      static Core*	_core;

      Field::Manager*	_manager;


    public:
      static Core*	getCore();
      static void	deleteCore();

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
