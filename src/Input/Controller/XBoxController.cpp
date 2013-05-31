//
// XBoxController.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 19 00:17:06 2013 julien fortin
// Last update Thu May 30 23:52:17 2013 julien fortin
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

#include	<stdlib.h>
#include	<iostream>

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      XBoxController::XBoxController(std::string const &path)
	: _fd(path, O_RDONLY)
      {
	this->_path = path;

	this->_currentX = XBoxAxis::NO;
	this->_currentY = XBoxAxis::NO;
	this->_valueX = 0;
	this->_valueY = 0;

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
	this->_valueX = this->_data.value;
	//std::cout << "X:" << this->_data.value << "\n";
	if (this->_data.value < 0)
	  this->_currentX = XBoxAxis::LEFT;
	else if (this->_data.value > 0)
	  this->_currentX = XBoxAxis::RIGHT;
	else
	  this->_currentX = XBoxAxis::NO;
      }

      void	XBoxController::_axisJS_LS_Y()
      {
	this->_valueY = this->_data.value;
	//std::cout << "Y:" << this->_data.value << "\n";
	if (this->_data.value > 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      this->_makeEventMove(Event::EventDirection::DOWN_LEFT,
				   ((float)(180 + 90.0 * ((JS_MAX - this->_data.value + 0.0) / JS_MAX))));
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      this->_makeEventMove(Event::EventDirection::DOWN_RIGHT,
				   ((float)(90.0 + 90.0 * ((this->_data.value + 0.0) / JS_MAX))));
	    else
	      this->_makeEventMove(Event::EventDirection::DOWN, 180.0);
	    this->_currentY = XBoxAxis::DOWN;
	  }
	else if (this->_data.value < 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      this->_makeEventMove(Event::EventDirection::UP_LEFT,
				   ((float)(270 + 90.0 * ((-this->_data.value + 0.0) / JS_MAX))));
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      this->_makeEventMove(Event::EventDirection::UP_RIGHT,
				   ((float)(90.0 * ((JS_MAX + this->_data.value + 0.0) / JS_MAX))));
	    else
	      this->_makeEventMove(Event::EventDirection::UP, 0);
	    this->_currentY = XBoxAxis::UP;
	  }
	else
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      this->_makeEventMove(Event::EventDirection::LEFT, 270);
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      this->_makeEventMove(Event::EventDirection::RIGHT, 90);
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
	    this->_makeEventMove(Event::EventDirection::LEFT, 270.0);
	    this->_currentX = XBoxAxis::LEFT;
	  }
	else if (this->_data.value > 0)
	  {
	    this->_makeEventMove(Event::EventDirection::RIGHT, 90.0);
	    this->_currentX = XBoxAxis::RIGHT;
	  }
	else
	  {
	    this->_currentX = XBoxAxis::NO;
	  }
      }

      void	XBoxController::_axisJS_CROSS_Y()
      {
	if (this->_data.value > 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      this->_makeEventMove(Event::EventDirection::DOWN_LEFT, 225.0);
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      this->_makeEventMove(Event::EventDirection::DOWN_RIGHT, 135.0);
	    else
	      this->_makeEventMove(Event::EventDirection::DOWN, 180.0);
	    this->_currentY = XBoxAxis::DOWN;
	  }
	else if (this->_data.value < 0)
	  {
	    if (this->_currentX == XBoxAxis::LEFT)
	      this->_makeEventMove(Event::EventDirection::UP_LEFT, 315.0);
	    else if (this->_currentX == XBoxAxis::RIGHT)
	      this->_makeEventMove(Event::EventDirection::UP_RIGHT, 45.0);
	    else
	      this->_makeEventMove(Event::EventDirection::UP, 0);
	    this->_currentY = XBoxAxis::UP;
	  }
	else
	  this->_currentY = XBoxAxis::NO;
      }

      void	XBoxController::_axisJS_LT()
      {
      }

      void	XBoxController::_axisJS_RT()
      {
      }

      void	XBoxController::getPushingEvent()
      {
	this->_data.value = this->_valueY;
	if (this->_currentX == XBoxAxis::RIGHT && this->_valueX > 5000)
	  {
	    this->_axisJS_LS_Y();
	    // if (this->_currentY == XBoxAxis::UP)
	    //   std::cout << "UPRIGHT\n";
	    // else if (this->_currentY == XBoxAxis::DOWN)
	    //   std::cout << "DOWNRIGHT\n";
	  }
	else if (this->_currentX == XBoxAxis::LEFT && this->_valueX < -5000)
	  {
	    this->_axisJS_LS_Y();
	    // if (this->_currentY == XBoxAxis::UP)
	    //   std::cout << "UPLEFT\n";
	    // else if (this->_currentY == XBoxAxis::DOWN)
	    //   std::cout << "DOWNLEFT\n";
	  }
	else if (this->_currentX > -2000 && this->_currentX < 2000)
	  {
	    exit(1);
	    if (this->_currentY < -28000)
	      std::cout << "UP\n";
	    else if (this->_currentY > 28000)
	      std::cout << "DOWN\n";

	  }
	// if (this->_valueY > 5000)
	//   std::cout << "DOWN\n";
	// else if (this->_valueY < -5000)
	//   std::cout << "UP\n";



	// if (this->_valueX > 5000 && this->_valueY < -5000)
	//   std::cout <<
	// else if (this->_valueX > 5000 && this->_valueY < 5000)
	//   std::cout << "PUSH BITCH\n";


      }

      void	XBoxController::_makeEventMove(Event::EventDirection::eEventDirection dir, float angle)
      {
	Event::EventManager::moveEvent(dir, angle, 42, 42);
      }
    }
  }
}
