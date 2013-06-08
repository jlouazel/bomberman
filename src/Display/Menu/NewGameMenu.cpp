//
// NewGameMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 01:14:27 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"NewGameMenu.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    NewGameMenu::NewGameMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f      vectorPosition(25, 15, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      IOnglet *newOnglet = new OngletMenu(MenuEnum::QUICKGAME, "quickGame",
					  new Texture2d("resources/images/quickGame.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[0] = new OngletMenu(MenuEnum::QUICKGAME, "quickGame",
				       new Texture2d("resources/images/quickGameHover.png",
						     vectorPosition, vectorRotation, vectorLen));

      vectorPosition.setY(28);
      newOnglet = new OngletMenu(MenuEnum::CUSTOMIZE, "customize",
				 new Texture2d("resources/images/customize.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[1] = new OngletMenu(MenuEnum::CUSTOMIZE, "customize",
				       new Texture2d("resources/images/customizeHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[1]->initialize();

      vectorPosition.setY(41);
      newOnglet = new OngletMenu(MenuEnum::MAIN, "back",
				 new Texture2d("resources/images/back.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[2] = new OngletMenu(MenuEnum::MAIN, "back",
                                       new Texture2d("resources/images/backHover.png",
                                                     vectorPosition, vectorRotation, vectorLen));
      this->_hover[2]->initialize();

      this->_menu->addOnglet(this->_hover[0]);
      this->_menu->initialize();
    }

    NewGameMenu::~NewGameMenu()
    {
    }

    void	NewGameMenu::update()
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
	      MenuManager::getMenuManager()->menu(this->_hover[this->_cursor]->getMenu());
	    }
	}
      else if ((move = dynamic_cast<const Event::Move*>(event)))
        {
	  if (move->getDirection() == Event::EventDirection::UP)
            {
	      if ((this->_cursor - 1) > NewGameMenu::_nbOnglet)
                this->_cursor = NewGameMenu::_nbOnglet;
              else
                this->_cursor--;
              this->_cursorMove();
            }
          else if (move->getDirection() == Event::EventDirection::DOWN)
            {
              if ((this->_cursor + 1) > NewGameMenu::_nbOnglet)
                this->_cursor = 0;
              else
                this->_cursor++;
              this->_cursorMove();
            }
        }
      if (event)
        delete event;
    }

    void	NewGameMenu::draw()
    {
      if (this->_menu)
	this->_menu->affAllOnglet();
    }

    MenuEnum::eMenu	NewGameMenu::getType() const
    {
      return MenuEnum::NEWGAME;
    }

    void	NewGameMenu::_cursorMove()
    {
      if (this->_cursor > NewGameMenu::_nbOnglet)
        this->_cursor = 0;
      this->_menu->popBackOnglet();
      this->_menu->addOnglet(this->_hover[this->_cursor]);
      usleep(150000);
    }
  }
}
