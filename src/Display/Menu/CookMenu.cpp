//
// CookMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 02:24:32 2013 julien fortin
//

#include	"BomberOptions.hh"
#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"CookMenu.hh"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    CookMenu::CookMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_current = 0;
      this->_cursor = 0;
      this->_menu = new Menu("resources/images/bg.jpg");
      this->_menu->initialize();

      Vector3f      vectorPosition(17, 0, 0);
      Vector3f      vectorLen(65.0, 100.0, 0.0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      this->_player[0] = new OngletMenu(MenuEnum::LOADING, "go",
					new Texture2d("resources/images/WWmenu.png",
						      vectorPosition, vectorRotation, vectorLen));
      this->_player[1] = new OngletMenu(MenuEnum::LOADING, "go",
					new Texture2d("resources/images/JPmenu.png",
						      vectorPosition, vectorRotation, vectorLen));

      this->_player[0]->initialize();
      this->_player[1]->initialize();

      Vector3f      bP(25, 92, 0);
      Vector3f      bL(50.0, 8.0, 0.0);

      this->_back[0] = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
				      new Texture2d("resources/images/back.png",
						    bP, vectorRotation, bL));
      this->_back[1] = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
				      new Texture2d("resources/images/backHover.png",
						    bP, vectorRotation, bL));
      this->_back[0]->initialize();
      this->_back[1]->initialize();


      Vector3f      vP(0, 44, 0);
      Vector3f      vL(20.0, 20.0, 0.0);

      this->_left = new OngletMenu(MenuEnum::NO, "<",
				   new Texture2d("resources/images/ChevronGauche.png",
						 vP, vectorRotation, vL));

      vP.setX(80);
      this->_right = new OngletMenu(MenuEnum::NO, ">",
				    new Texture2d("resources/images/ChevronDroite.png",
						  vP, vectorRotation, vL));
      this->_left->initialize();
      this->_right->initialize();

    }

    CookMenu::~CookMenu()
    {
    }

    void	CookMenu::update()
    {
      const Event::IEvent       *event;
      const Event::Action       *action;
      const Event::Move         *move;

      event = Event::EventManager::getEventManager()->getEvent();
      if ((action = dynamic_cast<const Event::Action*>(event)))
        {
	  if (this->_current == 0)
	    {
	      Core::BomberOptions::getOptions()->setSkinForPlayer(0, Core::BomberOptions::WW);
	      Core::BomberOptions::getOptions()->setSkinForPlayer(1, Core::BomberOptions::JP);
	    }
	  else
	    {
	      Core::BomberOptions::getOptions()->setSkinForPlayer(0, Core::BomberOptions::JP);
	      Core::BomberOptions::getOptions()->setSkinForPlayer(1, Core::BomberOptions::WW);
	    }
	  usleep(150000);
	  if (!this->_cursor)
	    {
	      Core::BomberOptions::getOptions()->setNotQuickGame();
	      MenuManager::getMenuManager()->menu(this->_player[this->_current]->getMenu());
	    }
	  else
	    MenuManager::getMenuManager()->menu(this->_back[0]->getMenu());
	}
      else if ((move = dynamic_cast<const Event::Move*>(event)))
	{
	  if (move->getDirection() == Event::EventDirection::UP
	      || move->getDirection() == Event::EventDirection::DOWN)
	    {
	      if (!this->_cursor)
		this->_cursor = 1;
	      else
		this->_cursor = 0;
	      usleep(150000);
	    }
	  else if (move->getDirection() == Event::EventDirection::RIGHT && !this->_cursor)
            {
	      if (this->_current == 0)
		this->_current = 1;
	      else
		this->_current = 1;
	      usleep(150000);
	    }
          else if (move->getDirection() == Event::EventDirection::LEFT && !this->_cursor)
            {
	      if (this->_current == 1)
		this->_current = 0;
	      else
		this->_current = 0;
	      usleep(150000);
	    }
	}
      if (event)
        delete event;
    }

    void	CookMenu::draw()
    {
      if (this->_menu)
        this->_menu->affAllOnglet();
      if (!this->_current)
	{
	  if (!this->_cursor)
	    this->_right->affOnglet();
	  this->_player[0]->affOnglet();
	}
      else
	{
	  if (!this->_cursor)
	    this->_left->affOnglet();
	  this->_player[1]->affOnglet();
	}
      this->_back[this->_cursor]->affOnglet();
    }

    MenuEnum::eMenu	CookMenu::getType() const
    {
      return MenuEnum::COOK;
    }
  }
}
