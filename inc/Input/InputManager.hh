//
// Manager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/input
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Wed May 15 16:55:15 2013 julien fortin
// Last update Thu May 23 10:50:02 2013 julien fortin
//

#ifndef	__INPUTMANAGER_HH__
#define	__INPUTMANAGER_HH__

#include	<string>
#include	<list>
#include	<dirent.h>
#include	<sys/select.h>
#include	<unistd.h>
#include	"UnixThread.hh"
#include	"IController.hh"
#include	"InputError.hh"

namespace BomberMan
{
  namespace Input
  {
    class InputManager
    {
    private:
      ~InputManager();
      InputManager();
      InputManager(InputManager const&);
      InputManager	&operator=(InputManager const&);

    private:
      static InputManager*			_inputManager;

      std::list<const Controller::IController*>	_controller;
      fd_set					_rfd;

      Unix::IThread*	_detectionThread;
      Unix::IThread*	_inputThread;

      int		_initInputSelect();
      bool       	_getInputFromController(const Controller::IController*);

      void	_getInputSelect(int, struct timeval*);
      void	_getInputEvent();

      void	_deleteScanDir(struct dirent**, int) const;

      void	_newController(const std::string*);
      void	_checkForNewController(struct dirent**, int);

      void	_checkForUnplugController(struct dirent**, int);
      void	_unplugController(const Controller::IController*);

      static int	_filterJS(const struct dirent*);

    protected:
    public:
      void	detection();
      void	getInput();

      static void			init();

      static InputManager*	getInputManager();
      static void			deleteInputManager();
      static void			deleteController(const Controller::IController*);
      static void			deleteAndRemoveController(const Controller::IController*);
    };
  }
}

extern "C"
{
  void* _startDetection(void*);
  void*	_startInputGetter(void*);
}

#endif
