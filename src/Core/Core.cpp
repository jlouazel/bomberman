#include "Core.hh"

namespace BomberMan
{
  namespace Engine
  {
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

    void Core::update() {
      //std::cout << "core update" << std::endl;
    }
  }
}
