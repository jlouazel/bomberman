//
// XBoxController.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/input
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Fri May 17 12:53:01 2013 julien fortin
// Last update Tue May 28 11:51:25 2013 julien fortin
//

#ifndef	__XBoxController__HH__
#define	__XBoxController__HH__

#include	<string>
#include	<map>
#include	"EventManager.hh"
#include	"IController.hh"
#include	"Fd.hh"

#define JS_MIN  -32767
#define JS_MAX  32767

#define JS_PRESSED      1
#define JS_RELEASED     0

#define JS_A            0
#define JS_B            1
#define JS_X            2
#define JS_Y            3
#define JS_LB           4
#define JS_RB           5
#define JS_SELECT       6
#define JS_START        7

#define JS_LS_X         0
#define JS_LS_Y         1
#define JS_RS_X         3
#define JS_RS_Y         4
#define JS_CROSS_X      6
#define JS_CROSS_Y      7
#define JS_LT           2
#define JS_RT           5

#define JS_BUTTON 0x01
#define JS_AXIS 0x02
#define JS_INIT 0x80

namespace BomberMan
{
    namespace Input
    {
        namespace Controller
        {
            class XBoxController : public IController
            {
            private:
                Unix::Fd	_fd;
                std::string	_path;
                
            private:
                struct XBoxAxis
                {
                    enum eXBoxAxis { NO, UP, DOWN, LEFT, RIGHT };
                };
                struct XBoxButtonStatus
                {
                    enum eXBoxButtonStatus { PRESSED, RELEASED };
                };
                
                XBoxAxis::eXBoxAxis	_currentX;
                XBoxAxis::eXBoxAxis	_currentY;
                
            private:
                struct t_data
                {
                    unsigned int		time; /* event timestamp in milliseconds */
                    short			value; /* value */
                    unsigned char		type; /* event type */
                    unsigned char		number;
                };
                t_data		_data;
                
            private:
                std::map<int, XBoxButtonStatus::eXBoxButtonStatus>	_status;
                std::map<int, void (XBoxController::*)()>			_button;
                std::map<int, void (XBoxController::*)()>			_axis;
                
            private:
                XBoxController();
                XBoxController(XBoxController const&);
                
                XBoxController	&operator=(XBoxController const&);
                
                void	_handleButton();
                void	_handleAxis();
                
                void	_execAction(std::map<int, void (XBoxController::*)()>&, int);
                
                void	_buttonA();
                void	_buttonB();
                void	_buttonY();
                void	_buttonX();
                void	_buttonLB();
                void	_buttonRB();
                void	_buttonSELECT();
                void	_buttonSTART();
                
                void	_axisJS_LS_X();
                void	_axisJS_LS_Y();
                void	_axisJS_RS_X();
                void	_axisJS_RS_Y();
                void	_axisJS_CROSS_X();
                void	_axisJS_CROSS_Y();
                void	_axisJS_LT();
                void	_axisJS_RT();
                
                void	_makeEventMove(Event::EventDirection::eEventDirection, float);
                
            protected:
            public:
                ~XBoxController();
                XBoxController(std::string const&);
                
                virtual const std::string&	getPath() const;
                virtual eControllerType		getType() const;
                virtual int			getFd() const;
                virtual void			getEvent();
            };
        }
    }
}

#endif
