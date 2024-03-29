#ifndef	__INPUTMANAGER_HH__
#define	__INPUTMANAGER_HH__

#include	<Input.hpp>
#include	<string>
#include	<list>
#include	<dirent.h>
#include	<sys/select.h>
#include	<unistd.h>
#include	"UnixThread.hh"
#include	"IController.hh"

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
      static InputManager*						_inputManager;

      std::list<const Controller::IController*>	_controller;
      Unix::IThread*							_detectionThread;
      fd_set									_rfd;
      int										_leaveMe;

      void		_shouldILeave();

      int			_initInputSelect();
      bool		_getInputFromController(const Controller::IController*);

      void		_getInputSelect(int, struct timeval*);
      void		_getInputEvent();

      void		_deleteScanDir(struct dirent**, int) const;

      void		_newController(const std::string*);
      void		_checkForNewController(struct dirent**, int);

      void		_checkForUnplugController(struct dirent**, int);
      void		_unplugController(const Controller::IController*);

      static int	_filterJS(const struct dirent*);

    public:
      void	detection();
      void	getInput();
      void	treatInput(gdl::Input&);

      static void	init();

      static InputManager *	getInputManager();
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

#else
namespace BomberMan
{
  namespace Input
  {
    class InputManager;
  }
}

#endif
