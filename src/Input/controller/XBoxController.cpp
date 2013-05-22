//
// XBoxController.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 19 00:17:06 2013 julien fortin
// Last update Wed May 22 01:56:48 2013 julien fortin
//

#include	<string>
#include	<fcntl.h>
#include	<string.h>
#include	<unistd.h>
#include	<errno.h>
#include	"XBoxController.hh"
#include	"EventManager.hh"
#include	"Fd.hh"

#include	<iostream>
#include	<exception>
#include	<stdlib.h>

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
	  std::cout << "RES=" << res << "\n";
	  throw std::exception();
	  //throw de la classe d'exception; strerror(errno)
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
      //Event::EventManager::addEvent(new const Event::EventButtonA(42, 42));
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
      std::cout << "Value=" << this->_data.value << "--";
      if (this->_data.value > 0)
	{
	  if (this->_currentX == XBoxAxis::LEFT)
	    std::cout << "DOWN_LEFT\n";
	  else if (this->_currentX == XBoxAxis::RIGHT)
	    std::cout << "DOWN_RIGHT\n";
	  else
	    std::cout << "DOWN_\n";
	  this->_currentY = XBoxAxis::DOWN;
	}
      else if (this->_data.value < 0)
	{
	  if (this->_currentX == XBoxAxis::LEFT)
	    std::cout << "UP_LEFT\n";
	  else if (this->_currentX == XBoxAxis::RIGHT)
	    std::cout << "UP_RIGHT\n";
	  else
	    std::cout << "UP_\n";
	  this->_currentY = XBoxAxis::UP;
	}
      else
	{
	  if (this->_currentX == XBoxAxis::LEFT)
	    std::cout << "LEFTGO LEFT\n";
	  else if (this->_currentX == XBoxAxis::RIGHT)
	    std::cout << "LEFTGO RIGHT\n";
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
	  std::cout << "#LEFT\n";
	  this->_currentX = XBoxAxis::LEFT;
	}
      else if (this->_data.value > 0)
	{
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
	    std::cout << "#DOWN_LEFT\n";
	  else if (this->_currentX == XBoxAxis::RIGHT)
	    std::cout << "#DOWN_RIGHT\n";
	  else
	    std::cout << "#DOWN_\n";
	  this->_currentY = XBoxAxis::DOWN;
	}
      else if (this->_data.value < 0)
	{
	  if (this->_currentX == XBoxAxis::LEFT)
	    std::cout << "#UP_LEFT\n";
	  else if (this->_currentX == XBoxAxis::RIGHT)
	    std::cout << "#UP_RIGHT\n";
	  else
	    std::cout << "#UP\n";
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
  }
}

// std::cout << "time:" << this->_data.time << "\n";
      // std::cout << "value:" << this->_data.value << "\n";
      // std::cout << "type:" << this->_data.type << "\n";
      // std::cout << "number:" << this->_data.number << "\n";

      //void	(XBoxController::*foo)() = this->_actions[(XBoxAction::eXBoxAction)this->_data.type];
      //(this->*foo)();
      //(XBoxAction::eXBoxAction)
