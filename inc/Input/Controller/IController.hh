//
// IController.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Wed May  8 17:54:29 2013 julien fortin
// Last update Thu May 23 10:50:27 2013 julien fortin
//

#ifndef	__ICONTROLLER_HH__
#define	__ICONTROLLER_HH__

#include	"ControllerError.hh"
#include	<string>

namespace BomberMan
{
    namespace Input
    {
        namespace Controller
        {
            static std::string	INPUT_CONTROLLER_PATH = "/dev/input/";
            
            enum eControllerType { XBOX };
            
            class IController
            {
            private:
            protected:
            public:
                virtual ~IController() {}
                
                virtual const std::string&	getPath() const = 0;
                virtual eControllerType		getType() const = 0;
                virtual int					getFd() const = 0;
                virtual void				getEvent() = 0;
            };
        }
    }
}

#endif
