//
//  BomberMan.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include	"BomberMan.hh"
#include	"MyGame.hpp"

int		main()
{
  try
    {
      // BomberMan::Display::MyGame game;

      // game.initialize();
      // game.run();

      BomberMan::Event::EventManager::getEventManager();
      BomberMan::Input::InputManager::getInputManager();
      BomberMan::Input::InputManager::init();

      const BomberMan::Event::IEvent*	event;
      while (42)
	{
	  usleep(100);
	  event = BomberMan::Event::EventManager::getEvent();
	}

    }
  catch (BomberMan::Core::CoreError& e)
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
