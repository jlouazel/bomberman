//
// InputManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 22:20:00 2013 julien fortin
// Last update Sun Jun  9 04:13:04 2013 julien fortin
//

#include	<string>
#include	<algorithm>
#include	<functional>
#include	<unistd.h>
#include	<sys/select.h>
#include	"InputManager.hh"
#include	"ControllerError.hh"
#include	"IController.hh"
#include	"XBoxController.hh"
#include	"KeyBoardManager.hh"
#include	"EndOfBomberMan.hh"

#include	<iostream>

namespace BomberMan
{
  namespace Input
  {
    InputManager*	InputManager::_inputManager = 0;

    InputManager*	InputManager::getInputManager()
    {
      if (!InputManager::_inputManager)
	InputManager::_inputManager = new InputManager();
      if (!InputManager::_inputManager)
        throw Core::EndOfBomberMan("InputManager", "getInputManager", "NULL pointer");
      return InputManager::_inputManager;
    }

    void		InputManager::deleteInputManager()
    {
      if (InputManager::_inputManager)
	delete InputManager::_inputManager;
      InputManager::_inputManager = 0;
    }

    InputManager::InputManager()
    {
      this->_leaveMe = 0;
    }

    InputManager::~InputManager()
    {
      this->_leaveMe = 1;
      while (this->_leaveMe != 42)
	usleep(100);
      Controller::KeyBoardManager::deleteKeyBoardManager();
      std::for_each(this->_controller.begin(), this->_controller.end(), &InputManager::deleteController);
    }

    void	InputManager::init()
    {
      Controller::KeyBoardManager::getKeyBoardManager();
      InputManager::getInputManager()->_detectionThread =
	new BomberMan::Unix::UnixThread(0, &_startDetection, 0, 0);
    }

    extern "C"
    {
      void*	_startDetection(void*)
      {
	InputManager::getInputManager()->detection();
	return 0;
      }
    }

    void  InputManager::deleteController(const Controller::IController* c)
    {
      if (c)
	delete c;
      c = 0;
    }

    void	InputManager::deleteAndRemoveController(const Controller::IController* c)
    {
      InputManager::getInputManager()->_controller.remove(c);
      if (c)
	delete c;
      c = 0;
    }

    void	InputManager::treatInput(gdl::Input& input)
    {
      Controller::KeyBoardManager::getKeyBoardManager()->treatInput(input);
    }

    void	InputManager::_shouldILeave()
    {
      if (this->_leaveMe)
	{
	  this->_leaveMe = 42;
	  delete this->_detectionThread;
	}
    }

    int		InputManager::_initInputSelect()
    {
      int	mfd = -1;

      FD_ZERO(&this->_rfd);
      for (std::list<const Controller::IController*>::const_iterator it = this->_controller.begin();
	   it != this->_controller.end(); ++it)
	{
	  if (*it)
	    {
	      if ((*it)->getFd() > mfd)
		mfd = (*it)->getFd();
	      FD_SET((*it)->getFd(), &this->_rfd);
	    }
	}
      return mfd;
    }

    void	InputManager::_getInputSelect(int mfd, struct timeval* timeout)
    {
      Controller::IController*	controller = 0;
      static int		failSelect = 0;
      int			res = -1;

      this->_shouldILeave();
      if ((res = select(mfd + 1, &this->_rfd, 0, 0, timeout)) < 0)
	{
	  if (failSelect > 15)
	    return ; //Event fail
	  failSelect++;
	  std::cout << "Fail select";
	}
      else if (res > 0 && this->_controller.size() > 0)
	{
	  this->_shouldILeave();
	  this->_getInputEvent();
	}
      else if (!res)
	{
	  for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
	       it != this->_controller.end(); ++it)
	    {
	      if (*it)
		{
		  controller = const_cast<Controller::IController*>(*it);
		  if (controller)
		    controller->getPushingEvent();
		}
	    }
	}
    }

    void	InputManager::_getInputEvent()
    {
      std::list<const Controller::IController*>	failController;

      for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
	   it != this->_controller.end(); ++it)
	{
	  if (!this->_getInputFromController(*it))
	    failController.push_back(*it);
	}
      for (std::list<const Controller::IController*>::iterator it = failController.begin();
	   it != failController.end(); it++)
	{
	  if (*it)
	    {
	      std::cout << "DETACHLOL\n";
	      //REVENT REMOVE CONTROLLER
	      this->_controller.remove(*it);
	      delete *it;
	    }
	}
    }

    bool	InputManager::_getInputFromController(const Controller::IController* controller)
    {
      if (controller)
	{
	  Controller::IController*	js = const_cast<Controller::IController*>(controller);

	  if (FD_ISSET(js->getFd(), &this->_rfd))
	    {
	      try
		{
		  js->getEvent();
		}
	      catch (Controller::ControllerError const &e)
		{
		  std::cerr << e.what() << std::endl;
		  std::cerr << e.getDetails() << std::endl;
		  return false;
		  //EVENT Deconnexion de manette + message d'erreur dans &e;
		}
	    }
	  return true;
	}
      return false;
    }

    int	InputManager::_filterJS(const struct dirent *dir)
    {
      static std::string	filename = "";

      if (dir)
	{
	  filename = dir->d_name;
	  if (filename.size() > 2 && !filename.compare(0, 2, "js"))
	    return filename.compare(0, 3, "js0");
	}
      return 0;
    }

    void	InputManager::_deleteScanDir(struct dirent **dirp, int scan) const
    {
      int	i = 0;

      for (i = 0; i < scan && dirp && dirp[i]; i++)
	free(dirp[i]);
      free(dirp);
    }

    void	InputManager::_unplugController(const Controller::IController* unplugController)
    {
      if (unplugController)
	{
	  std::cout << "!!!!!!UNPLUG!!!!\n";
	  //EVENT UNPLUG REUSSI
	  this->_controller.remove(unplugController);
	  delete unplugController;
	}
    }

    void	InputManager::_checkForUnplugController(struct dirent **dirp, int scan)
    {
      std::list<const Controller::IController*>	unplug;
      std::string	filename;
      bool	find;
      int		i;

      for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
	   it != this->_controller.end(); ++it)
	{
	  if (!*it)
	    continue;
	  find = false;
	  for (i = 0; i < scan && dirp && dirp[i]; i++)
	    {
	      filename = Controller::INPUT_CONTROLLER_PATH + dirp[i]->d_name;
	      if (filename == (*it)->getPath())
		{
		  find = true;
		  break;
		}
	    }
	  if (!find)
	    unplug.push_back(*it);
	}
      if (unplug.size() > 0)
	std::for_each(unplug.begin(),
		      unplug.end(),
		      std::bind1st(std::mem_fun(&InputManager::_unplugController), this));
    }

    void	InputManager::_newController(const std::string* path)
    {
      if (path)
	{
	  Controller::IController* controller = new Controller::XBoxController(*path);

	  if (controller && controller->getFd() > 0)
	    {
	      std::cout << "###############PLUG######\n";
	      //if ajoute == success -> creer un evenment NEW MANETTE PLUG!
	      this->_controller.push_back(controller);
	    }
	  else
	    {
	      delete controller;
	    }
	  delete path;
	}
    }

    void	InputManager::_checkForNewController(struct dirent **dirp, int scan)
    {
      std::list<const std::string*>	plug;
      std::string	filename;
      bool	find;

      for (int i = 0; i < scan && dirp && dirp[i]; i++)
	{
	  find = false;
	  filename = Controller::INPUT_CONTROLLER_PATH + dirp[i]->d_name;
	  for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
	       it != this->_controller.end(); ++it)
	    {
	      if (*it && filename == (*it)->getPath())
		{
		  find = true;
		  break;
		}
	    }
	  if (!find)
	    plug.push_back(new std::string(filename));
	}
      if (plug.size() > 0)
	std::for_each(plug.begin(),
		      plug.end(),
		      std::bind1st(std::mem_fun(&InputManager::_newController), this));
    }

    void	InputManager::detection()
    {
      struct dirent	**dirp = NULL;
      struct timeval	timeout;
      int			mfd  = -2, selectCount = 0;
      int			scan = 0, failScan = 0;

      timeout.tv_sec = 1;
      timeout.tv_usec = 1000;
      while (true)
	{
	  this->_shouldILeave();
	  if ((scan = scandir(Controller::INPUT_CONTROLLER_PATH.c_str(),
			      &dirp, &InputManager::_filterJS, alphasort)) < 0)
	    {
	      if (failScan > 5)
		{
		  //EVENT FAIL_INPUT;
		  //Generer une Execpetion et ou un event qui preveint l'user qu'on a perdu le controle
		  //des manettes.
		}
	      failScan++;
	    }
	  this->_shouldILeave();
	  this->_checkForUnplugController(dirp, scan);
	  this->_shouldILeave();
	  this->_checkForNewController(dirp, scan);
	  this->_shouldILeave();
	  this->_deleteScanDir(dirp, scan);
	  selectCount = 0;
	  while (selectCount++ < 10)
	    {
	      this->_shouldILeave();
	      mfd = this->_initInputSelect();
	      if (mfd != -1)
		this->_getInputSelect(mfd, &timeout);
	      usleep(10000);
	    }
	}
    }
  }
}


// std::cout << "Current list:";
// for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
//      it != this->_controller.end(); ++it)
//   {
//     std::cout << (*it)->getPath() << " : ";
//   }
// std::cout << "\n";


// std::cout << "WESH list:";
// for (std::list<const Controller::IController*>::iterator it = this->_controller.begin();
//      it != this->_controller.end(); ++it)
//   {
//     std::cout << (*it)->getPath() << " : ";
//   }
// std::cout << "\n";
// std::cout << "COUCOU:" << *path << "\n";


// std::for_each(this->_controller.begin(),
// 	      this->_controller.end(),
// 	      std::bind1st(std::mem_fun(&InputManager::_getInputFromController), this));


// std::for_each(failController.begin(),
// 		  failController.end(),
// 		  &InputManager::deleteAndRemoveController);
