//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Tue Jun  4 18:03:33 2013 julien fortin
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

	this->initMapping(true);

	this->_keys[gdl::Keys::W] = &KeyBoardManager::_up;
	this->_keys[gdl::Keys::A] = &KeyBoardManager::_left;
	this->_keys[gdl::Keys::D] = &KeyBoardManager::_right;
	this->_keys[gdl::Keys::S] = &KeyBoardManager::_down;
	this->_keys[gdl::Keys::Space] = &KeyBoardManager::_action;

	this->_keys[gdl::Keys::Z] = &KeyBoardManager::_up;
	this->_keys[gdl::Keys::Q] = &KeyBoardManager::_left;


	this->_keys[gdl::Keys::Up] = &KeyBoardManager::_up;
	this->_keys[gdl::Keys::Left] = &KeyBoardManager::_left;
	this->_keys[gdl::Keys::Right] = &KeyBoardManager::_right;
	this->_keys[gdl::Keys::Down] = &KeyBoardManager::_down;
	this->_keys[gdl::Keys::Return] = &KeyBoardManager::_action;
      }

      KeyBoardManager::~KeyBoardManager()
      {
      }

      void	KeyBoardManager::initMapping(bool qwerty)
      {
	this->_mappingP2.push_back(gdl::Keys::Up);
	this->_mappingP2.push_back(gdl::Keys::Left);
	this->_mappingP2.push_back(gdl::Keys::Right);
	this->_mappingP2.push_back(gdl::Keys::Down);
	this->_mappingP2.push_back(gdl::Keys::Return);

	this->_mappingP1.push_back(gdl::Keys::D);
	this->_mappingP1.push_back(gdl::Keys::S);
	this->_mappingP1.push_back(gdl::Keys::Space);
	if (qwerty)
	  {
	    this->_mappingP1.push_back(gdl::Keys::W);
	    this->_mappingP1.push_back(gdl::Keys::A);
	  }
	else
	  {
	    this->_mappingP1.push_back(gdl::Keys::Z);
	    this->_mappingP1.push_back(gdl::Keys::Q);
	  }
      }

      void	KeyBoardManager::_treatInputForPlayer(gdl::Input& input,
						      const std::list<gdl::Keys::Key>& playerMapping)
      {
	for (std::list<gdl::Keys::Key>::const_iterator it = playerMapping.begin();
	     it != playerMapping.end() ; ++it)
	  {
	    if (input.isKeyDown(*it))
	      {
		if (this->_keys.count(*it) > 0)
		  (this->*(this->_keys[*it]))(0);
	      }
	  }
      }

      void	KeyBoardManager::treatInput(gdl::Input& input)
      {
	this->_treatInputForPlayer(input, this->_mappingP1);
	this->_treatInputForPlayer(input, this->_mappingP2);
      }

      void	KeyBoardManager::_up(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP, 180.0, 0, 0);
      }

      void	KeyBoardManager::_left(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::LEFT, 270.0, 0, 0);
      }

      void	KeyBoardManager::_right(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::RIGHT, 90.0, 0, 0);
      }

      void	KeyBoardManager::_down(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN, 0.0, 0, 0);
      }

      void	KeyBoardManager::_action(const Field::Player* const) const
      {
      }
    }
  }
}
