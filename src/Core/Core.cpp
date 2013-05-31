#include "Core.hh"

namespace BomberMan
{
  namespace Engine
  {
    Core*	Core::_core = 0;

    Core*	Core::getCore()
    {
      if (!Core::_core)
	Core::_core = new Core;
      return Core::_core;
    }

    void	Core::deleteCore()
    {
      delete Core::_core;
      Core::_core = 0;
    }

    Core::Core()
    {
      Input::InputManager::getInputManager();
      Input::InputManager::init();
      Event::EventManager::getEventManager();

      /* Thread video intro */
      /* Initialisation ressources GDL */
      /* Initialise Display */
    }
    Core::~Core()
    {
      Input::InputManager::deleteInputManager();
    }

    void Core::update()
    {
      //std::cout << "core update" << std::endl;
    }
  }
}
