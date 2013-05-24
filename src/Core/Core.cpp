//
// Core.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman/bomberman/src/Core
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Thu May 23 12:10:00 2013 julien fortin
// Last update Fri May 24 13:19:45 2013 julien fortin
//

#include	"BomberMan.hh"
#include	"Core.hh"

namespace BomberMan
{
  namespace Core
  {
    Core::Core()
    {
    }

    Core::~Core()
    {
    }

    int	Core::_run()
    {
      Input::InputManager::getInputManager();
      Input::InputManager::init();
      Input::InputManager::deleteInputManager();
      return 0;
    }

    int	Core::run()
    {
      try
	{
	  return this->_run();
	}
      catch (Field::FieldError const& e)
	{
	  ::std::cerr << "An error occured concerning the field : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (Input::InputError const& e)
	{
	  ::std::cerr << "An error occured concerning inputs : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (Input::Controller::ControllerError const& e)
	{
	  ::std::cerr << "An error occured concerning controllers : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (Event::EventError const& e)
	{
	  ::std::cerr << "An error occured concerning events : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (DataFormat::FormatError const& e)
	{
	  ::std::cerr << "An error occured concerning data format : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (Display::DisplayError const& e)
	{
	  ::std::cerr << "An error occured concerning the display : " << e.getWhat()
		      << " in " << e.getWhere()
		      << " (" << e.getDetails()
		      << ")" << ::std::endl;
	}
      catch (std::exception const &e)
	{
	  ::std::cerr << "The meth lab is goin to blow up." << ::std::endl;
	}
      return -1;
    }
  }
}
