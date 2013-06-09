//
// MapOptionsMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 22:47:11 2013 julien fortin
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

#define BUFFMAX		99
#define	BUFFMIN		1
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
      this->_buffDensity = 42;
      this->_wallDensity = 80;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f		vP(10, 16, 0);
      Vector3f		vectorPosition(25, 18, 0);
      Vector3f		vectorLen(50.0, 8.0, 0.0), vArrow(9.0, 10.0, 0.0);
      Vector3f		vectorRotation(0.0, 0.0, 0.0);
      Vector3f		vectorLenNb(9.0, 11.0, 0.0);


      IOnglet *newOnglet = new OngletMenu(MenuEnum::NO, "width",
					  new Texture2d("resources/images/width.png",
							vP, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[0] = new OngletMenu(MenuEnum::NO, "width",
				      new Texture2d("resources/images/widthHover.png",
						    vP, vectorRotation, vectorLen));

      vP.setY(30);
      newOnglet = new OngletMenu(MenuEnum::NO, "height",
				 new Texture2d("resources/images/hieght.png",
					       vP, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[1] = new OngletMenu(MenuEnum::NO, "height",
				      new Texture2d("resources/images/hieghtHover.png",
						    vP, vectorRotation, vectorLen));
      this->_hover[1]->initialize();


      vP.setY(42);
      newOnglet = new OngletMenu(MenuEnum::NO, "buffDensity",
                                 new Texture2d("resources/images/buffDensity.png",
                                               vP, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[2] = new OngletMenu(MenuEnum::NO, "buffDensity",
				       new Texture2d("resources/images/buffDensityHover.png",
						     vP, vectorRotation, vectorLen));
      this->_hover[2]->initialize();

      vP.setY(60);
      newOnglet = new OngletMenu(MenuEnum::NO, "wall",
				 new Texture2d("resources/images/wallDensity.png",
					       vP, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[3] = new OngletMenu(MenuEnum::NO, "wall",
				 new Texture2d("resources/images/wallDensityHover.png",
					       vP, vectorRotation, vectorLen));
      this->_hover[3]->initialize();


      vectorPosition.setY(80);
      newOnglet = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
					  new Texture2d("resources/images/back.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[4] = new OngletMenu(MenuEnum::CUSTOMIZE, "back",
       				       new Texture2d("resources/images/backHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[4]->initialize();

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
	  if (this->_cursor == MapOptionsMenu::_nbOnglet)
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
      Vector3f      vPosition(65.0, 15.0, 0);
      Vector3f      vPositionArrow(57.0, 15.0, 0);

      if (this->_menu)
      	this->_menu->affAllOnglet();

      int       f = this->_width / 100;
      int       s = (this->_width / 10) % 10;
      int	l = this->_width % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(70);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();
      vPosition.setX(75);
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
      	      vPositionArrow.setX(84);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}

      vPosition.setX(65.0);
      vPosition.setY(28.0);
      vPositionArrow.setX(57.0);
      vPositionArrow.setY(28.0);

      f = this->_height / 100;
      s = (this->_height / 10) % 10;
      l = this->_height % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(70);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();
      vPosition.setX(75);
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
      	      vPositionArrow.setX(84);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}



      vPosition.setX(68.0);
      vPosition.setY(40.0);
      vPositionArrow.setX(60.0);
      vPositionArrow.setY(40.0);

      f = this->_buffDensity / 10;
      s = this->_buffDensity % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(73);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();

      if (this->_cursor == 2)
      	{
      	  if (this->_buffDensity > BUFFMIN)
      	    {
      	      this->_arrow[0]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[0]->affOnglet();
      	    }
      	  if (this->_buffDensity < BUFFMAX)
      	    {
      	      vPositionArrow.setX(82);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}


      vPosition.setX(68.0);
      vPosition.setY(60.0);
      vPositionArrow.setX(60.0);
      vPositionArrow.setY(60.0);

      f = this->_wallDensity / 10;
      s = this->_wallDensity % 10;

      this->_nb[f]->getImage()->setPosition(vPosition);
      this->_nb[f]->affOnglet();
      vPosition.setX(73);
      this->_nb[s]->getImage()->setPosition(vPosition);
      this->_nb[s]->affOnglet();

      if (this->_cursor == 3)
      	{
      	  if (this->_wallDensity > BUFFMIN)
      	    {
      	      this->_arrow[0]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[0]->affOnglet();
      	    }
      	  if (this->_wallDensity < BUFFMAX)
      	    {
      	      vPositionArrow.setX(82);
      	      this->_arrow[1]->getImage()->setPosition(vPositionArrow);
      	      this->_arrow[1]->affOnglet();
      	    }
      	}
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
      else
	{
	  if (this->_cursor == 2)
	    {
	      if (this->_buffDensity > BUFFMAX)
		this->_buffDensity = BUFFMAX;
	      else if (this->_buffDensity < BUFFMAX)
		this->_buffDensity++;
	      Core::BomberOptions::getOptions()->setBuffDensity(this->_buffDensity);
	      usleep(50000);
	    }
	  else if (this->_cursor == 3)
	    {
	      if (this->_wallDensity > BUFFMAX)
		this->_wallDensity = BUFFMAX;
	      else if (this->_wallDensity < BUFFMAX)
		this->_wallDensity++;
	      Core::BomberOptions::getOptions()->setWallDensity(this->_wallDensity);
	      usleep(50000);
	    }
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
      else
	{
	  if (this->_cursor == 2)
	    {
	      if (this->_buffDensity < BUFFMIN)
		this->_buffDensity = MIN_SIZE;
	      else if (this->_buffDensity > BUFFMIN)
		this->_buffDensity--;
	      Core::BomberOptions::getOptions()->setBuffDensity(this->_buffDensity);
	      usleep(50000);
	    }
	  else if (this->_cursor == 3)
	    {
	      if (this->_wallDensity < BUFFMIN)
                this->_wallDensity = MIN_SIZE;
              else if (this->_wallDensity > BUFFMIN)
                this->_wallDensity--;
	      Core::BomberOptions::getOptions()->setWallDensity(this->_wallDensity);
              usleep(50000);
	    }
	}
    }
  }
}
