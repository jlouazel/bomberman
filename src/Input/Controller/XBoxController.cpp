//
// XBoxController.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 19 00:17:06 2013 julien fortin
// Last update Thu May 23 10:24:58 2013 julien fortin
//

#include	<string>
#include	<fcntl.h>
#include	<string.h>
#include	<unistd.h>
#include	<errno.h>
#include	<exception>
#include	"XBoxController.hh"
#include	"ControllerError.hh"
#include	"EventManager.hh"
#include	"Move.hh"
#include	"Fd.hh"

#include	<iostream>
#include	<stdlib.h>

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      XBoxController::XBoxController(std::string const &path) : _fd(path, O_RDONLY)
      {
	this->_path = path;

	this->_currentX = XBoxAxis::NO;
	this->_currentY = XBoxAxis::NO;

	this->_status[JS_A] = XBoxButtonStatus::RELEASED;
	this->_status[JS_B] = XBoxButtonStatus::RELEASED;
	this->_status[JS_X] = XBoxButtonStatus::RELEASED;
	this->_status[JS_Y] = XBoxButtonStatus::RELEASED;
	this->_status[JS_LB] = XBoxButtonStatus::RELEASED;
	this->_status[JS_RB] = XBoxButtonStatus::RELEASED;
	this->_status[JS_SELECT] = XBoxButtonStatus::RELEASED;
	this->_status[JS_START] = XBoxButtonStatus::RELEASED;

	this->_button[JS_A] = &XBoxController::_buttonA;
	this->_button[JS_B] = &XBoxController::_buttonB;
	this->_button[JS_Y] = &XBoxController::_buttonY;
	this->_button[JS_X] = &XBoxController::_buttonX;
	this->_button[JS_LB] = &XBoxController::_buttonLB;
	this->_button[JS_RB] = &XBoxController::_buttonRB;
	this->_button[JS_SELECT] = &XBoxController::_buttonSELECT;
	this->_button[JS_START] = &XBoxController::_buttonSTART;

	this->_axis[JS_LS_X] = &XBoxController::_axisJS_LS_X;
	this->_axis[JS_LS_Y] = &XBoxController::_axisJS_LS_Y;
	this->_axis[JS_RS_X] = &XBoxController::_axisJS_RS_X;
	this->_axis[JS_RS_Y] = &XBoxController::_axisJS_RS_Y;
	this->_axis[JS_CROSS_X] = &XBoxController::_axisJS_CROSS_X;
	this->_axis[JS_CROSS_Y] = &XBoxController::_axisJS_CROSS_Y;
	this->_axis[JS_LT] = &XBoxController::_axisJS_LT;
	this->_axis[JS_RT] = &XBoxController::_axisJS_RT;
      }

      XBoxController::~XBoxController()
      {
	this->_fd.closeFd();
      }

      const std::string&	XBoxController::getPath() const
      {
	return this->_path;
      }

      int			XBoxController::getFd() const
      {
	return this->_fd.getFd();
      }

      eControllerType	XBoxController::getType() const
      {
	return XBOX;
      }

      void		XBoxController::_execAction(std::map<int,
						    void (XBoxController::*)()> &funMap,int action)
      {
	if (funMap.count(action) > 0)
	  (this->*(funMap[action]))();
      }

      void		XBoxController::getEvent()
      {
	int	res = -1;

	bzero(&this->_data, sizeof(this->_data));
	if ((res = read(this->_fd.getFd(), &this->_data, sizeof(this->_data))) <= 0
	    || res != sizeof(this->_data))
	  {
	    if (res < 0)
	      throw ControllerError("Unplug controller",
				    "XBoxController::getEvent()",
				    strerror(errno));
	    else
	      throw ControllerError("Unplug controller",
				    "XBoxController::getEvent()",
				    "Invalid size read.");

	  }
	if (this->_data.type == JS_BUTTON)
	  this->_handleButton();
	else if (this->_data.type == JS_AXIS)
	  this->_handleAxis();
      }

      void	XBoxController::_handleButton()
      {
	if (this->_data.value == JS_PRESSED)
	  {
	    if (this->_status.count(this->_data.number) > 0)
	      this->_status[this->_data.number] = XBoxButtonStatus::PRESSED;
	    this->_execAction(this->_button, this->_data.number);
	  }
	else if (this->_data.value == JS_RELEASED)
	  {
	    if (this->_status.count(this->_data.number) > 0)
	      this->_status[this->_data.number] = XBoxButtonStatus::RELEASED;
	  }
      }

      void	XBoxController::_handleAxis()
      {
	this->_execAction(this->_axis, this->_data.number);
      }

      void	XBoxController::_buttonA()
      {
      }

      void	XBoxController::_buttonB()
      {
      }

      void	XBoxController::_buttonY()
      {
      }

      void	XBoxController::_buttonX()
      {
      }

      void	XBoxController::_buttonLB()
      {
      }

      void	XBoxController::_buttonRB()
      {
      }

      void	XBoxController::_buttonSELECT()
      {
      }

      void	XBoxController::_buttonSTART()
      {
      }

      void	XBoxController::_axisJS_LS_X()
      {
	if (this->_data.value < 0)
	  this->_currentX = XBoxAxis::LEFT;
	else if (this->_data.value > 0)
	  this->_currentX = XBoxAxis::RIGHT;
	else
	  this->_currentX = XBoxAxis::NO;
      }

      void	XBoxController::_axisJS_LS_Y()
      {
	if (this->_data.value > 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      {
		this->_makeEvent(Event::EventDirection::DOWN_LEFT,
				 ((float)(180 + 90.0 * ((JS_MAX - this->_data.value + 0.0) / JS_MAX))));
		std::cout << "DOWN_LEFT=" << ((float)(180 + 90.0 * ((JS_MAX - this->_data.value + 0.0) / JS_MAX)))<< "\n";
	      }
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      {
		this->_makeEvent(Event::EventDirection::DOWN_RIGHT,
				 ((float)(90.0 + 90.0 * ((this->_data.value + 0.0) / JS_MAX))));
		std::cout << "DOWN_RIGHT=" << ((float)(90.0 + 90.0 * ((this->_data.value + 0.0) / JS_MAX))) << "\n";
	      }
	    else
	      {
		this->_makeEvent(Event::EventDirection::DOWN, 180.0);
		std::cout << "DOWN_\n";
	      }
	    this->_currentY = XBoxAxis::DOWN;
	  }
	else if (this->_data.value < 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      {
		this->_makeEvent(Event::EventDirection::UP_LEFT,
				 ((float)(270 + 90.0 * ((-this->_data.value + 0.0) / JS_MAX))));
		std::cout << "UP_LEFT=" << ((float)(270 + 90.0 * ((-this->_data.value + 0.0) / JS_MAX)))<< "\n";
	      }
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      {
		this->_makeEvent(Event::EventDirection::UP_RIGHT,
				 ((float)(90.0 * ((JS_MAX + this->_data.value + 0.0) / JS_MAX))));
		std::cout << "UP_RIGHT=" << ((float)(90.0 * ((JS_MAX + this->_data.value + 0.0) / JS_MAX)))<< "\n";
	      }
	    else
	      {
		this->_makeEvent(Event::EventDirection::UP, 0);
		std::cout << "UP_\n";
	      }
	    this->_currentY = XBoxAxis::UP;
	  }
	else
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      {
		this->_makeEvent(Event::EventDirection::LEFT, 270);
		std::cout << "LEFTGO LEFT\n";
	      }
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      {
		this->_makeEvent(Event::EventDirection::RIGHT, 90);
		std::cout << "LEFTGO RIGHT\n";
	      }
	    this->_currentY = XBoxAxis::NO;
	  }
      }

      void	XBoxController::_axisJS_RS_X()
      {
      }

      void	XBoxController::_axisJS_RS_Y()
      {
      }

      void	XBoxController::_axisJS_CROSS_X()
      {
	if (this->_data.value < 0)
	  {
	    this->_makeEvent(Event::EventDirection::LEFT, 270.0);
	    std::cout << "#LEFT\n";
	    this->_currentX = XBoxAxis::LEFT;
	  }
	else if (this->_data.value > 0)
	  {
	    this->_makeEvent(Event::EventDirection::RIGHT, 90.0);
	    std::cout << "#RIGHT\n";
	    this->_currentX = XBoxAxis::RIGHT;
	  }
	else
	  {
	    std::cout << "#STOP\n";
	    this->_currentX = XBoxAxis::NO;
	  }
      }

      void	XBoxController::_axisJS_CROSS_Y()
      {
	if (this->_data.value > 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      {
		this->_makeEvent(Event::EventDirection::DOWN_LEFT, 225.0);
		std::cout << "#DOWN_LEFT\n";
	      }
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      {
		this->_makeEvent(Event::EventDirection::DOWN_RIGHT, 135.0);
		std::cout << "#DOWN_RIGHT\n";
	      }
	    else
	      {
		this->_makeEvent(Event::EventDirection::DOWN, 180.0);
		std::cout << "#DOWN_\n";
	      }
	    this->_currentY = XBoxAxis::DOWN;
	  }
	else if (this->_data.value < 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      {
		this->_makeEvent(Event::EventDirection::UP_LEFT, 315.0);
		std::cout << "#UP_LEFT\n";
	      }
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      {
		this->_makeEvent(Event::EventDirection::UP_RIGHT, 45.0);
		std::cout << "#UP_RIGHT\n";
	      }
	    else
	      {
		this->_makeEvent(Event::EventDirection::UP, 0);
		std::cout << "#UP\n";
	      }
	    this->_currentY = XBoxAxis::UP;
	  }
	else
	  {
	    this->_currentY = XBoxAxis::NO;
	    std::cout << "#STOP\n";
	  }
      }

      void	XBoxController::_axisJS_LT()
      {
      }

      void	XBoxController::_axisJS_RT()
      {
      }

      void	XBoxController::_makeEvent(Event::EventDirection::eEventDirection dir, float angle) const
      {
	Event::EventManager::addEvent(new const Event::Move(42, 42, dir, angle));
      }
    }
  }
}