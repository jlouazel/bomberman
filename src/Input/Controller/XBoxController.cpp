//
// XBoxController.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 19 00:17:06 2013 julien fortin
// Last update Tue Jun  4 19:58:35 2013 Jean-Baptiste Louazel
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
#include	<cmath>
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
	this->_calcProperties();
      }

      void	XBoxController::_axisJS_LS_Y()
      {
	this->_valueY = this->_data.value;
	this->_calcProperties();
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

      void	XBoxController::_calcProperties() const
      {
	static int last = 0;
	float intensity = sqrt(pow(this->_valueX, 2) + pow(this->_valueY, 2));
	float angle = atanf(this->_valueY / (this->_valueX + 1.0)) * 180 / 3.14159;

	if (this->_valueX > 0.0)
	  {
	    if (angle > 0.0)
	      angle = 360 - angle;
	    else
	      angle = -angle;
	  }
	else
	  {
	      angle = 180 - angle;
	  }

	//	std::cout << "INTENSITY:" << intensity << "\tANGLE:" << angle << "\n";
	if (intensity >= 10000.0)
	  {
	    if (!(last % 3))
	      Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::NO,
								(static_cast<int>(angle) + 90) % 360, 42, 42);

	  }
	last++;
      }

      void	XBoxController::getPushingEvent()
      {
	this->_calcProperties();
      }

      int	XBoxController::_getMaxCountDir() const
      {
	int	max = 0;
	int	id = 0;

	for (std::map<int, int>::const_iterator it = this->_countDir.begin();
	     it != this->_countDir.end(); ++it)
	  {
	    if (it->second > max)
	      {
		id = it->first;
		max = it->second;
	      }
	  }
	return id;
      }

      void	XBoxController::_makeEventMove(Event::EventDirection::eEventDirection dir, float angle)
      {
	// std::cout << "\tDIR:" << dir << "\n\n";
	// int	maxDir;

	// this->_countDir[dir] += 1;
	// maxDir = this->_getMaxCountDir();
	// if (dir != maxDir)
	//   {
	//   }

	// if (dir == Event::EventDirection::UP)
	//   std::cout << "UP " << angle << "\n";
	// else if (dir == Event::EventDirection::DOWN)
	//   std::cout << "DOWN " << angle << "\n";
	// else if (dir == Event::EventDirection::LEFT)
	//   std::cout << "LEFT " << angle << "\n";
	// else if (dir == Event::EventDirection::RIGHT)
	//   std::cout << "RIGHT " << angle << "\n";
	// else if (dir == Event::EventDirection::UP_LEFT)
	//   std::cout << "UP_LEFT " << angle << "\n";
	// else if (dir == Event::EventDirection::UP_RIGHT)
	//   std::cout << "UP_RIGHT " << angle << "\n";
	// else if (dir == Event::EventDirection::DOWN_LEFT)
	//   std::cout << "DOWN_LEFT " << angle << "\n";
	// else if (dir == Event::EventDirection::DOWN_RIGHT)
	//   std::cout << "DOWN_RIGHT " << angle << "\n";


      }
    }
  }
}
