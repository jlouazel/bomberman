//
// MapOptionsMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 01:06:32 2013 julien fortin
//

#include	"BomberOptions.hh"
#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"MapOptionsMenu.hh"
#include	<unistd.h>

#define	MIN_SIZE	3
#define	MAX_SIZE	999
#define	LIMIT_IA	32

namespace BomberMan
{
  namespace Display
  {
    MapOptionsMenu::MapOptionsMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;
      this->_width = 6;
      this->_height = 7;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f		vectorPosition(25, 18, 0);
      Vector3f		vectorLen(50.0, 8.0, 0.0), vArrow(9.0, 10.0, 0.0);
      Vector3f		vectorRotation(0.0, 0.0, 0.0);
      Vector3f		vectorLenNb(9.0, 11.0, 0.0);

      vectorPosition.setY(80);
      IOnglet *newOnglet = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
					  new Texture2d("resources/images/back.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_menu->initialize();

      this->_back = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
       				       new Texture2d("resources/images/backHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_back->initialize();

      this->_arrow[0] = new OngletMenu(MenuEnum::NO, "<",
                                       new Texture2d("resources/images/ChevronGauche.png",
                                                     vectorPosition, vectorRotation, vArrow));
      this->_arrow[1] = new OngletMenu(MenuEnum::NO, ">",
                                       new Texture2d("resources/images/ChevronDroite.png",
                                                     vectorPosition, vectorRotation, vArrow));
      this->_arrow[0]->initialize();
      this->_arrow[1]->initialize();



      this->_nb[0] = new OngletMenu(MenuEnum::NO, "0",
                                      new Texture2d("resources/images/0.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[1] = new OngletMenu(MenuEnum::NO, "1",
                                      new Texture2d("resources/images/1.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[2] = new OngletMenu(MenuEnum::NO, "2",
                                      new Texture2d("resources/images/2.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[3] = new OngletMenu(MenuEnum::NO, "3",
                                      new Texture2d("resources/images/3.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[4] = new OngletMenu(MenuEnum::NO, "4",
                                      new Texture2d("resources/images/4.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[5] = new OngletMenu(MenuEnum::NO, "5",
                                      new Texture2d("resources/images/5.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[6] = new OngletMenu(MenuEnum::NO, "6",
                                      new Texture2d("resources/images/6.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[7] = new OngletMenu(MenuEnum::NO, "7",
                                      new Texture2d("resources/images/7.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[8] = new OngletMenu(MenuEnum::NO, "8",
                                      new Texture2d("resources/images/8.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      this->_nb[9] = new OngletMenu(MenuEnum::NO, "9",
                                      new Texture2d("resources/images/9.png",
                                                    vectorPosition, vectorRotation, vectorLenNb));
      for (unsigned int i = 0; i < 10; i++)
        this->_nb[i]->initialize();
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
	  if (this->_cursor == MapOptionsMenu::_nbOnglet)
	    MenuManager::getMenuManager()->menu(this->_back->getMenu());
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
      Vector3f      vPosition(40.0, 15.0, 0);
      Vector3f      vPositionArrow(32.0, 15.0, 0);

      if (this->_menu)
      	this->_menu->affAllOnglet();

      int       f = this->_width / 100;
      int       s = (this->_width / 10) % 10;
      int	l = this->_width % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(45);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();
      vPosition.setX(50);
      this->_nb[l]->getImage()->setPosition(vPosition);
      this->_nb[l]->affOnglet();

      if (this->_cursor == 0)
      	{
      	  if (this->_width > MIN_SIZE)
      	    {
      	      this->_arrow[0]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[0]->affOnglet();
      	    }
      	  if (this->_width < MAX_SIZE)
      	    {
      	      vPositionArrow.setX(59);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}

      vPosition.setX(40.0);
      vPosition.setY(28.0);
      vPositionArrow.setX(32.0);
      vPositionArrow.setY(28.0);

      f = this->_height / 100;
      s = (this->_height / 10) % 10;
      l = this->_height % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(45);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();
      vPosition.setX(50);
      this->_nb[l]->getImage()->setPosition(vPosition);
      this->_nb[l]->affOnglet();

      if (this->_cursor == 1)
      	{
      	  if (this->_height > MIN_SIZE)
      	    {
      	      this->_arrow[0]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[0]->affOnglet();
      	    }
      	  if (this->_height < MAX_SIZE)
      	    {
      	      vPositionArrow.setX(59);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}

      if (this->_cursor == MapOptionsMenu::_nbOnglet)
	this->_back->affOnglet();
    }

    MenuEnum::eMenu	MapOptionsMenu::getType() const
    {
      return MenuEnum::MAPOPTIONS;
    }

    void	MapOptionsMenu::_cursorMove()
    {
      if (this->_cursor > MapOptionsMenu::_nbOnglet)
        this->_cursor = 0;
      usleep(150000);
    }

    void	MapOptionsMenu::_cursorRight()
    {
      if (this->_cursor == 0)
	{
	  if (this->_width > MAX_SIZE)
	    this->_width = MAX_SIZE;
	  else if (this->_width < MAX_SIZE)
	    this->_width++;
	  Core::BomberOptions::getOptions()->setWidth(this->_width);
	  usleep(50000);
	}
      else if (this->_cursor == 1)
	{
	  if (this->_height > MAX_SIZE)
	    this->_height = MAX_SIZE;
	  else if (this->_height < MAX_SIZE)
	    this->_height++;
	  Core::BomberOptions::getOptions()->setHeight(this->_width);
	  usleep(50000);
	}
    }

    void	MapOptionsMenu::_cursorLeft()
    {
      if (this->_cursor == 0)
	{
	  if (this->_width < MIN_SIZE)
	    this->_width = MIN_SIZE;
	  else if (this->_width > MIN_SIZE)
	    this->_width--;
	  Core::BomberOptions::getOptions()->setWidth(this->_width);
	  usleep(50000);
	}
      else if (this->_cursor == 1)
	{
	  if (this->_height < MIN_SIZE)
	    this->_height = MIN_SIZE;
	  else if (this->_height > MIN_SIZE)
	    this->_height--;
	  Core::BomberOptions::getOptions()->setHeight(this->_width);
	  usleep(50000);
	}
    }
  }
}
