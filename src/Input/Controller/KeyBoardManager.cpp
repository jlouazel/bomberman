//
// KeyBoardManager.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:26:12 2013 julien fortin
// Last update Tue Jun  4 19:24:16 2013 julien fortin
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
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::W | gdl::Keys::A)] = &KeyBoardManager::_upLeft;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::W | gdl::Keys::D)] = &KeyBoardManager::_upRight;

	this->_keys[gdl::Keys::A] = &KeyBoardManager::_left;
	this->_keys[gdl::Keys::D] = &KeyBoardManager::_right;

	this->_keys[gdl::Keys::S] = &KeyBoardManager::_down;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::S | gdl::Keys::A)] = &KeyBoardManager::_downLeft;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::S | gdl::Keys::Q)] = &KeyBoardManager::_downLeft;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::S | gdl::Keys::D)] = &KeyBoardManager::_downRight;

	this->_keys[gdl::Keys::Space] = &KeyBoardManager::_action;

	this->_keys[gdl::Keys::Z] = &KeyBoardManager::_up;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::Z | gdl::Keys::Q)] = &KeyBoardManager::_upLeft;
	this->_keys[static_cast<gdl::Keys::Key>(gdl::Keys::Z | gdl::Keys::D)] = &KeyBoardManager::_upRight;

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
	this->_mappingP1.clear();
	this->_mappingP2.clear();

	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Up, gdl::Keys::Left));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Up, gdl::Keys::Right));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Down, gdl::Keys::Left));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Down, gdl::Keys::Right));

	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Up, gdl::Keys::Up));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Left, gdl::Keys::Left));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Right, gdl::Keys::Right));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Down, gdl::Keys::Down));
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Return, gdl::Keys::Return));

	if (qwerty)
	  {
	    this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::W, gdl::Keys::A));
	    this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::W, gdl::Keys::D));
	    this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::A, gdl::Keys::S));

	    this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::W, gdl::Keys::W));
	    this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::A, gdl::Keys::A));
	  }
	else
	  {
	    this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Z, gdl::Keys::Q));
	    this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Z, gdl::Keys::D));

	    this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Z, gdl::Keys::Z));
	    this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Q, gdl::Keys::Q));
	  }
	this->_mappingP2.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::S, gdl::Keys::D));
	this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::D, gdl::Keys::D));
	this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::S, gdl::Keys::S));
	this->_mappingP1.push_back(std::pair<gdl::Keys::Key, gdl::Keys::Key>(gdl::Keys::Space, gdl::Keys::Space));
      }

      void	KeyBoardManager::_treatInputForPlayer(gdl::Input& input,
						      const std::list<std::pair<gdl::Keys::Key, gdl::Keys::Key> > & playerMapping)
      {
	for (std::list<std::pair<gdl::Keys::Key, gdl::Keys::Key> >::const_iterator it = playerMapping.begin();
	     it != playerMapping.end() ; ++it)
	  {
	    if (input.isKeyDown((*it).first) && input.isKeyDown((*it).second))
	      {
		if (this->_keys.count(static_cast<gdl::Keys::Key>((*it).first | (*it).second)) > 0)
		  (this->*(this->_keys[static_cast<gdl::Keys::Key>((*it).first | (*it).second)]))(0);
	      }
	  }
      }

      void	KeyBoardManager::treatInput(gdl::Input& input)
      {
	this->_treatInputForPlayer(input, this->_mappingP1);
	this->_treatInputForPlayer(input, this->_mappingP2);
      }

      void	KeyBoardManager::_upLeft(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP_LEFT, 225.0, 0, 0);
      }

      void	KeyBoardManager::_upRight(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::UP_RIGHT, 135.0, 0, 0);
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

      void	KeyBoardManager::_downLeft(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN_LEFT, 315.0, 0, 0);
      }

      void	KeyBoardManager::_downRight(const Field::Player* const) const
      {
	Event::EventManager::getEventManager()->moveEvent(Event::EventDirection::DOWN_RIGHT, 45.0, 0, 0);
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
