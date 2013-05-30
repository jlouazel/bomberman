#include <iostream>
#include "CoreError.hh"
#include "FieldError.hh"
#include "InputError.hh"
#include "ControllerError.hh"
#include "EventError.hh"
#include "FormatError.hh"
#include "DisplayError.hh"
#include "MyGame.hpp"

int		main()
{
  try
    {
      BomberMan::Display::MyGame game;

      game.run();
    }
  catch (BomberMan::Engine::CoreError& e)
    {
      std::cerr << "An error occured concerning the core : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::Field::FieldError& e)
    {
      std::cerr << "An error occured concerning the field : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::Input::InputError& e)
    {
      std::cerr << "An error occured concerning inputs : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::Input::Controller::ControllerError& e)
    {
      std::cerr << "An error occured concerning controllers : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::Event::EventError& e)
    {
      std::cerr << "An error occured concerning events : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::DataFormat::FormatError& e)
    {
      std::cerr << "An error occured concerning data format : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  catch (BomberMan::Display::DisplayError& e)
    {
      std::cerr << "An error occured concerning the display : " << e.getWhat()
		<< " in " << e.getWhere()
		<< " (" << e.getDetails()
		<< ")" << std::endl;
    }
  return 0;
}
