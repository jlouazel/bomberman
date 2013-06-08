//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Sat Jun  8 18:24:48 2013 julien fortin
//

#include	"EventManager.hh"
#include	"KeyBoardManager.hh"
#include	"EndOfBomberMan.hh"


#include <iostream>
#include <unistd.h>

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      KeyBoardManager*	KeyBoardManager::_keyboardManager = 0;

      KeyBoardManager*	KeyBoardManager::getKeyBoardManager()
      {
	if (!KeyBoardManager::_keyboardManager)
	  KeyBoardManager::_keyboardManager = new KeyBoardManager();
	if (!KeyBoardManager::_keyboardManager)
	  throw Core::EndOfBomberMan("KeyBoardManager", "getKeyBoardManager", "NULL pointer");
	return KeyBoardManager::_keyboardManager;
      }

      void		KeyBoardManager::deleteKeyBoardManager()
      {
	delete KeyBoardManager::_keyboardManager;
	KeyBoardManager::_keyboardManager = 0;
      }

      KeyBoardManager::KeyBoardManager()
      {
	// BomberMan::getBomberMan()->getPlayer(0);
	// BomberMan::getBomberMan()->getPlayer(1);
	this->_input = 0;

	this->initMapping(true);


	this->_keys[gdl::Keys::S] = &KeyBoardManager::_down;
	this->_keys[gdl::Keys::D] = &KeyBoardManager::_right;
	this->_keys[gdl::Keys::Space] = &KeyBoardManager::_action;

	this->_keys[gdl::Keys::Up] = &KeyBoardManager::_up;
	this->_keys[gdl::Keys::Left] = &KeyBoardManager::_left;
	this->_keys[gdl::Keys::Right] = &KeyBoardManager::_right;
	this->_keys[gdl::Keys::Down] = &KeyBoardManager::_down;
	this->_keys[gdl::Keys::Return] = &KeyBoardManager::_action;

	this->_run[0] = gdl::Keys::LShift;
	//this->_run[0] = gdl::Keys::;
      }

      KeyBoardManager::~KeyBoardManager()
      {
      }

      void	KeyBoardManager::initMapping(bool qwerty)
      {
	this->_qwerty = qwerty;

	this->_mappingP1.clear();
	this->_mappingP2.clear();

	this->_mappingP2.push_back(gdl::Keys::Up);
	this->_mappingP2.push_back(gdl::Keys::Down);
	this->_mappingP2.push_back(gdl::Keys::Left);
	this->_mappingP2.push_back(gdl::Keys::Right);
	this->_mappingP2.push_back(gdl::Keys::Return);

	this->_mappingP1.push_back(gdl::Keys::S);
	if (qwerty)
	  {
	    this->_keys[gdl::Keys::W] = &KeyBoardManager::_up;
	    this->_keys[gdl::Keys::A] = &KeyBoardManager::_left;
	    this->_mappingP1.push_back(gdl::Keys::W);
	    this->_mappingP1.push_back(gdl::Keys::A);
	  }
	else
	  {
	    this->_keys[gdl::Keys::Z] = &KeyBoardManager::_up;
	    this->_keys[gdl::Keys::Q] = &KeyBoardManager::_left;
	    this->_mappingP1.push_back(gdl::Keys::Z);
	    this->_mappingP1.push_back(gdl::Keys::Q);
	  }
	this->_mappingP1.push_back(gdl::Keys::D);
	this->_mappingP1.push_back(gdl::Keys::Space);
      }

      void	KeyBoardManager::_treatInputForPlayer(gdl::Input& input,
						      const std::list<gdl::Keys::Key>& playerMapping)
      {
	this->_multiples = false;
	for (std::list<gdl::Keys::Key>::const_iterator it = playerMapping.begin();
	     it != playerMapping.end() ; ++it)
	  {
	    if (input.isKeyDown((*it)))
	      {
		if (this->_keys.count(*it) > 0)
		  (this->*(this->_keys[*it]))(0);
	      }
	  }
	this->_multiples = false;
      }

      void	KeyBoardManager::treatInput(gdl::Input& input)
      {
	this->_input = &input;
	this->_treatInputForPlayer(input, this->_mappingP1);
	this->_treatInputForPlayer(input, this->_mappingP2);
      }

      bool	KeyBoardManager::_activeSpeed(const Field::Player* const player)
      {
	if (this->_input && this->_run.count(player) > 0)
	  return this->_input->isKeyDown(this->_run[player]);
	return false;
      }

      bool	KeyBoardManager::_upLeft(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (this->_input && (this->_input->isKeyDown(gdl::Keys::Left) ||
				 (((this->_qwerty && (this->_input->isKeyDown(gdl::Keys::A)))
				   || (!this->_qwerty && this->_input->isKeyDown(gdl::Keys::Q))))))
	      {
		this->_multiples = true;
		Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP_LEFT, 225.0,
								  this->_activeSpeed(player));
		return true;
	      }
	  }
	return false;
      }

      bool	KeyBoardManager::_upRight(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (this->_input && (this->_input->isKeyDown(gdl::Keys::D) || this->_input->isKeyDown(gdl::Keys::Right)))
	      {
		this->_multiples = true;
		Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP_RIGHT, 135.0,
								  this->_activeSpeed(player));
		return true;
	      }
	  }
	return false;
      }

      void	KeyBoardManager::_up(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (!this->_upRight(player) && !this->_upLeft(player))
	      Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP, 180.0,
								this->_activeSpeed(player));
	  }
      }

      void	KeyBoardManager::_left(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::LEFT, 270.0,
							      this->_activeSpeed(player));
	  }
      }

      void	KeyBoardManager::_right(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    this->_multiples = true;
	    Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::RIGHT, 90.0,
							      this->_activeSpeed(player));
	  }
      }

      bool	KeyBoardManager::_downLeft(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (this->_input && (this->_input->isKeyDown(gdl::Keys::Left) ||
                                 (((this->_qwerty && (this->_input->isKeyDown(gdl::Keys::A)))
                                   || (!this->_qwerty && this->_input->isKeyDown(gdl::Keys::Q))))))
	      {
		this->_multiples = true;
		Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN_LEFT, 315.0,
								  this->_activeSpeed(player));
		return true;
	      }
	  }
	return false;
      }

      bool	KeyBoardManager::_downRight(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (this->_input && (this->_input->isKeyDown(gdl::Keys::D) || this->_input->isKeyDown(gdl::Keys::Right)))
	      {
		this->_multiples = true;
		Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN_RIGHT, 45.0,
								  this->_activeSpeed(player));
		return true;
	      }
	  }
	return false;
      }

      void	KeyBoardManager::_down(const Field::Player* const player)
      {
	if (!this->_multiples)
	  {
	    if (!this->_downRight(player) && !this->_downLeft(player))
	      Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN, 0.0,
								this->_activeSpeed(player));
	  }
      }

      void	KeyBoardManager::_action(const Field::Player* const)
      {
	Event::EventManager::getEventManager()->actionEvent();
      }
    }
  }
}
