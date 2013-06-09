//
// LoadGame.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 21:58:23 2013 julien fortin
//

#include	"BomberOptions.hh"
#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"LoadGame.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    LoadGame::LoadGame(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;
      this->_menu = new Menu("resources/images/bg.jpg");
      this->_menu->initialize();

      Vector3f		vectorPosition(25, 18, 0);
      Vector3f		vectorLen(50.0, 8.0, 0.0);
      Vector3f		vectorRotation(0.0, 0.0, 0.0);


      this->_arrow[0] = new OngletMenu(MenuEnum::NO, "<",
                                       new Texture2d("resources/images/ChevronGauche.png",
                                                     vectorPosition, vectorRotation, vectorLen));
      this->_arrow[1] = new OngletMenu(MenuEnum::NO, ">",
                                       new Texture2d("resources/images/ChevronDroite.png",
                                                     vectorPosition, vectorRotation, vectorLen));
      this->_arrow[0]->initialize();
      this->_arrow[1]->initialize();

      //
    }

    LoadGame::~LoadGame()
    {
    }

    void	LoadGame::update()
    {
      const Event::IEvent       *event;
      const Event::Action       *action;
      const Event::Move         *move;

      event = Event::EventManager::getEventManager()->getEvent();
      if ((action = dynamic_cast<const Event::Action*>(event)))
        {
	  usleep(150000);
	  //this->_core->startGame(this->_cursor);
	}
      else if ((move = dynamic_cast<const Event::Move*>(event)))
        {
	  if (move->getDirection() == Event::EventDirection::RIGHT)
	    this->_cursorRight();
	  else if (move->getDirection() == Event::EventDirection::LEFT)
	    this->_cursorLeft();
        }
      if (event)
        delete event;
    }

    void	LoadGame::draw()
    {
      this->_menu->affAllOnglet();
      if (this->_cursor > 0)
	this->_arrow[0]->affOnglet();
      //if () this->_cursor pas trop grand
      this->_arrow[1]->affOnglet();
    }

    MenuEnum::eMenu	LoadGame::getType() const
    {
      return MenuEnum::LOAD;
    }

    void	LoadGame::_cursorRight()
    {
      /* if this->_cursor pas trop grand*/
      this->_cursor++;
      usleep(150000);
    }

    void	LoadGame::_cursorLeft()
    {
      if (this->_cursor > 0)
	this->_cursor--;
      if (this->_cursor <= 0)
	this->_cursor = 0;
      usleep(150000);
    }
  }
}
