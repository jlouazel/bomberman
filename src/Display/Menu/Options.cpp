//
// Options.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 23:02:08 2013 julien fortin
//

#include	"KeyBoardManager.hh"
#include	"BomberOptions.hh"
#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"Options.hh"
#include	<unistd.h>

#define	LIMIT_IA	32

namespace BomberMan
{
  namespace Display
  {
    Options::Options(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;

      this->_cursorNbPlayer = 0;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f      vectorPosition(10, 18, 0), vectorPositionNbPlayer(75, 18, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0), vectorLenNbPlayer(11.0, 9.0, 0.0), vectorIA(9.0, 9.0, 0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      IOnglet *newOnglet = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/keyboard.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[0] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
				       new Texture2d("resources/images/keyboardHover.png",
						     vectorPosition, vectorRotation, vectorLen));

      this->_kb[0] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/qwe.png",
							vectorPositionNbPlayer, vectorRotation, vectorLenNbPlayer));
      this->_kb[0]->initialize();
      this->_kb[1] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/aze.png",
							vectorPositionNbPlayer, vectorRotation, vectorLenNbPlayer));
      this->_kb[1]->initialize();


      vectorPosition.setY(80);
      newOnglet = new OngletMenu(MenuEnum::MAIN, "back",
				 new Texture2d("resources/images/back.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[1] = new OngletMenu(MenuEnum::MAIN, "back",
				       new Texture2d("resources/images/backHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[1]->initialize();


      this->_menu->addOnglet(this->_hover[0]);
      this->_menu->initialize();
    }

    Options::~Options()
    {
    }

    void	Options::update()
    {
      const Event::IEvent       *event;
      const Event::Action       *action;
      const Event::Move         *move;

      event = Event::EventManager::getEventManager()->getEvent();
      if ((action = dynamic_cast<const Event::Action*>(event)))
        {
	  if (this->_hover.count(this->_cursor) > 0)
	    {
	      usleep(150000);
	      if (this->_hover[this->_cursor]->getMenu() != MenuEnum::NO)
		MenuManager::getMenuManager()->menu(this->_hover[this->_cursor]->getMenu());
	    }
	}
      else if ((move = dynamic_cast<const Event::Move*>(event)))
        {
	  if (move->getDirection() == Event::EventDirection::UP)
            {
	      if ((this->_cursor - 1) > Options::_nbOnglet)
                this->_cursor = Options::_nbOnglet;
              else
                this->_cursor--;
              this->_cursorMove();
            }
          else if (move->getDirection() == Event::EventDirection::DOWN)
            {
              if ((this->_cursor + 1) > Options::_nbOnglet)
                this->_cursor = 0;
              else
                this->_cursor++;
              this->_cursorMove();
            }
	  else if (move->getDirection() == Event::EventDirection::RIGHT)
	    this->_cursorRight();
	  else if (move->getDirection() == Event::EventDirection::LEFT)
	    this->_cursorLeft();
        }
      if (event)
        delete event;
    }

    void	Options::draw()
    {
      if (this->_menu)
      	this->_menu->affAllOnglet();
      this->_kb.at(this->_cursorNbPlayer)->affOnglet();
    }

    MenuEnum::eMenu	Options::getType() const
    {
      return MenuEnum::OPTIONS;
    }

    void	Options::_cursorMove()
    {
      if (this->_cursor > Options::_nbOnglet)
        this->_cursor = 0;
      this->_menu->popBackOnglet();
      this->_menu->addOnglet(this->_hover[this->_cursor]);
      usleep(150000);
    }

    void	Options::_cursorRight()
    {
      if (this->_cursor == 0)
	{
	  if (this->_cursorNbPlayer == 0)
	    {
	      this->_cursorNbPlayer = 1;
	      Input::Controller::KeyBoardManager::getKeyBoardManager()->initMapping(false);
	    }
	  else
	    {
	      this->_cursorNbPlayer = 0;
	      Input::Controller::KeyBoardManager::getKeyBoardManager()->initMapping(true);
	    }
	  usleep(150000);
	}
    }

    void	Options::_cursorLeft()
    {
      if (this->_cursor == 0)
	{
	  if (this->_cursorNbPlayer == 0)
	    {
	      this->_cursorNbPlayer = 1;
	      Input::Controller::KeyBoardManager::getKeyBoardManager()->initMapping(false);
	    }
	  else
	    {
	      Input::Controller::KeyBoardManager::getKeyBoardManager()->initMapping(true);
	      this->_cursorNbPlayer = 0;
	    }
	  usleep(150000);
	}
    }
  }
}
