//
// MapOptionsMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 15:19:27 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"MapOptionsMenu.hh"
#include	<unistd.h>

#define	LIMIT_IA	32

namespace BomberMan
{
  namespace Display
  {
    MapOptionsMenu::MapOptionsMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f      vectorPosition(10, 18, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);


      vectorPosition.setY(80);
      IOnglet *newOnglet = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
				 new Texture2d("resources/images/back.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[0] = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
       				       new Texture2d("resources/images/backHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[0]->initialize();

      this->_menu->addOnglet(this->_hover[0]);
      this->_menu->initialize();
    }

    MapOptionsMenu::~MapOptionsMenu()
    {
    }

    void	MapOptionsMenu::update()
    {
      const Event::IEvent       *event;
      const Event::Action       *action;
      const Event::Move         *move;

      event = Event::EventManager::getEventManager()->getEvent();
      if ((action = dynamic_cast<const Event::Action*>(event)))
        {
	  usleep(150000);
	  MenuManager::getMenuManager()->menu(this->_hover[this->_cursor]->getMenu());
	}
      else if ((move = dynamic_cast<const Event::Move*>(event)))
        {
	  if (move->getDirection() == Event::EventDirection::UP)
            {
	      if ((this->_cursor - 1) > MapOptionsMenu::_nbOnglet)
                this->_cursor = MapOptionsMenu::_nbOnglet;
              else
                this->_cursor--;
              this->_cursorMove();
            }
          else if (move->getDirection() == Event::EventDirection::DOWN)
            {
              if ((this->_cursor + 1) > MapOptionsMenu::_nbOnglet)
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

    void	MapOptionsMenu::draw()
    {
      if (this->_menu)
      	this->_menu->affAllOnglet();
    }

    MenuEnum::eMenu	MapOptionsMenu::getType() const
    {
      return MenuEnum::MAPOPTIONS;
    }

    void	MapOptionsMenu::_cursorMove()
    {
      if (this->_cursor > MapOptionsMenu::_nbOnglet)
        this->_cursor = 0;
      this->_menu->popBackOnglet();
      this->_menu->addOnglet(this->_hover[this->_cursor]);
      usleep(150000);
    }

    void	MapOptionsMenu::_cursorRight()
    {
    }

    void	MapOptionsMenu::_cursorLeft()
    {
    }
  }
}
