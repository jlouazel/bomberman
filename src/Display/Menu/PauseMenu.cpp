//
// PauseMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 13:31:10 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"PauseMenu.hh"
#include	<unistd.h>

#include	<iostream>

namespace BomberMan
{
  namespace Display
  {
    PauseMenu::PauseMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f      vectorPosition(25, 15, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      IOnglet *newOnglet = new OngletMenu(MenuEnum::NEWGAME, "newGame",
					  new Texture2d("resources/images/newgame.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[0] = new OngletMenu(MenuEnum::NEWGAME, "newGame",
				       new Texture2d("resources/images/newgameHover.png",
						     vectorPosition, vectorRotation, vectorLen));

      vectorPosition.setY(28);
      newOnglet = new OngletMenu(MenuEnum::LOAD, "continueGame",
				 new Texture2d("resources/images/continuegame.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[1] = new OngletMenu(MenuEnum::LOAD, "continueGame",
				       new Texture2d("resources/images/continuegameHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[1]->initialize();

      vectorPosition.setY(41);
      newOnglet = new OngletMenu(MenuEnum::OPTIONS, "options",
				 new Texture2d("resources/images/options.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[2] = new OngletMenu(MenuEnum::OPTIONS, "options",
				       new Texture2d("resources/images/optionsHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[2]->initialize();

      vectorPosition.setY(54);
      newOnglet = new OngletMenu(MenuEnum::CREDITS, "credits",
				 new Texture2d("resources/images/credits.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);


      this->_hover[3] = new OngletMenu(MenuEnum::CREDITS, "credits",
				       new Texture2d("resources/images/creditsHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[3]->initialize();

      vectorPosition.setY(67);
      newOnglet = new OngletMenu(MenuEnum::QUIT, "quit",
				 new Texture2d("resources/images/quit.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[4] = new OngletMenu(MenuEnum::QUIT,
				       "quit",
				       new Texture2d("resources/images/quitHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[4]->initialize();


      this->_menu->addOnglet(this->_hover[0]);
      this->_menu->initialize();
    }

    PauseMenu::~PauseMenu()
    {
    }

    void	PauseMenu::update()
    {
      const Event::IEvent	*event;
      const Event::Action	*action;
      const Event::Move		*move;

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
	      if ((this->_cursor - 1) > PauseMenu::_nbOnglet)
		this->_cursor = PauseMenu::_nbOnglet;
	      else
		this->_cursor--;
	      this->_cursorMove();
	    }
	  else if (move->getDirection() == Event::EventDirection::DOWN)
	    {
	      if ((this->_cursor + 1) > PauseMenu::_nbOnglet)
		this->_cursor = 0;
	      else
		this->_cursor++;
	      this->_cursorMove();
	    }
	}
      if (event)
	delete event;
    }

    void	PauseMenu::draw()
    {
      if (this->_menu)
	this->_menu->affAllOnglet();
    }

    MenuEnum::eMenu	PauseMenu::getType() const
    {
      return MenuEnum::MAIN;
    }

    void	PauseMenu::_cursorMove()
    {
      if (this->_cursor > PauseMenu::_nbOnglet)
	this->_cursor = 0;
      this->_menu->popBackOnglet();
      this->_menu->addOnglet(this->_hover[this->_cursor]);
      usleep(150000);
    }
  }
}
