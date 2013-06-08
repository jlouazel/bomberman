//
// CustomizeMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sat Jun  8 04:07:51 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"Texture2d.hpp"
#include	"Vector.hpp"
#include	"Resources.hh"
#include	"OngletMenu.hpp"
#include	"Events.hh"
#include	"EventManager.hh"
#include	"CustomizeMenu.hh"
#include	<unistd.h>

#define	LIMIT_IA	32

namespace BomberMan
{
  namespace Display
  {
    CustomizeMenu::CustomizeMenu(Core::BomberMan* const core) : _core(core)
    {
      this->_cursor = 0;

      this->_cursorNbPlayer = 0;
      this->_currentsIA = 0;
      this->_menu = new Menu("resources/images/bg.jpg");

      Vector3f      vectorPosition(10, 18, 0), vectorPositionNbPlayer(75, 18, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0), vectorLenNbPlayer(11.0, 9.0, 0.0), vectorIA(9.0, 9.0, 0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      IOnglet *newOnglet = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/numberOfPlayers.png",
							vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[0] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
				       new Texture2d("resources/images/numberOfPlayersHover.png",
						     vectorPosition, vectorRotation, vectorLen));

      this->_nbPlayer[0] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/112.png",
							vectorPositionNbPlayer, vectorRotation, vectorLenNbPlayer));
      this->_nbPlayer[0]->initialize();
      this->_nbPlayer[1] = new OngletMenu(MenuEnum::NO, "numberOfPlayers",
					  new Texture2d("resources/images/122.png",
							vectorPositionNbPlayer, vectorRotation, vectorLenNbPlayer));
      this->_nbPlayer[1]->initialize();

      vectorPosition.setY(31);

      newOnglet = new OngletMenu(MenuEnum::MAPSIZE, "mapSize",
				 new Texture2d("resources/images/mapSize.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);

      this->_hover[1] = new OngletMenu(MenuEnum::MAPSIZE, "mapSize",
				       new Texture2d("resources/images/mapSizeHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[1]->initialize();

      vectorPosition.setY(44);
      newOnglet = new OngletMenu(MenuEnum::NO, "numberOfComputers",
				 new Texture2d("resources/images/numberOfComputers.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[2] = new OngletMenu(MenuEnum::NO, "numberOfComputers",
				       new Texture2d("resources/images/numberOfComputersHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[2]->initialize();


      vectorPositionNbPlayer.setY(43);
      vectorPositionNbPlayer.setX(65);
      this->_arrow[0] = new OngletMenu(MenuEnum::NO, "<",
				       new Texture2d("resources/images/ChevronGauche.png",
						     vectorPositionNbPlayer, vectorRotation, vectorIA));
      vectorPositionNbPlayer.setX(85);
      this->_arrow[1] = new OngletMenu(MenuEnum::NO, ">",
				       new Texture2d("resources/images/ChevronDroite.png",
						     vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_arrow[0]->initialize();
      this->_arrow[1]->initialize();

      vectorPositionNbPlayer.setX(75);

      this->_nbIA[0] = new OngletMenu(MenuEnum::NO, "0",
				      new Texture2d("resources/images/0.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[1] = new OngletMenu(MenuEnum::NO, "1",
				      new Texture2d("resources/images/1.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[2] = new OngletMenu(MenuEnum::NO, "2",
				      new Texture2d("resources/images/2.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[3] = new OngletMenu(MenuEnum::NO, "3",
				      new Texture2d("resources/images/3.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[4] = new OngletMenu(MenuEnum::NO, "4",
				      new Texture2d("resources/images/4.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[5] = new OngletMenu(MenuEnum::NO, "5",
				      new Texture2d("resources/images/5.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[6] = new OngletMenu(MenuEnum::NO, "6",
				      new Texture2d("resources/images/6.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[7] = new OngletMenu(MenuEnum::NO, "7",
				      new Texture2d("resources/images/7.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[8] = new OngletMenu(MenuEnum::NO, "8",
				      new Texture2d("resources/images/8.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      this->_nbIA[9] = new OngletMenu(MenuEnum::NO, "9",
				      new Texture2d("resources/images/9.png",
						    vectorPositionNbPlayer, vectorRotation, vectorIA));
      for (unsigned int i = 0; i < 10; i++)
	this->_nbIA[i]->initialize();



      vectorPosition.setY(70);
      newOnglet = new OngletMenu(MenuEnum::COOK, "letscook",
				 new Texture2d("resources/images/letscook.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[3] = new OngletMenu(MenuEnum::COOK, "letscook",
				       new Texture2d("resources/images/letscookHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[3]->initialize();

      vectorPosition.setY(80);
      newOnglet = new OngletMenu(MenuEnum::NEWGAME, "back",
				 new Texture2d("resources/images/back.png",
					       vectorPosition, vectorRotation, vectorLen));
      this->_menu->addOnglet(newOnglet);
      this->_hover[4] = new OngletMenu(MenuEnum::NEWGAME, "back",
				       new Texture2d("resources/images/backHover.png",
						     vectorPosition, vectorRotation, vectorLen));
      this->_hover[4]->initialize();


      this->_menu->addOnglet(this->_hover[0]);
      this->_menu->initialize();
    }

    CustomizeMenu::~CustomizeMenu()
    {
    }

    void	CustomizeMenu::update()
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
	      if ((this->_cursor - 1) > CustomizeMenu::_nbOnglet)
                this->_cursor = CustomizeMenu::_nbOnglet;
              else
                this->_cursor--;
              this->_cursorMove();
            }
          else if (move->getDirection() == Event::EventDirection::DOWN)
            {
              if ((this->_cursor + 1) > CustomizeMenu::_nbOnglet)
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

    void	CustomizeMenu::draw()
    {
      if (this->_menu)
      	this->_menu->affAllOnglet();
      this->_nbPlayer.at(this->_cursorNbPlayer)->affOnglet();


      int	f = this->_currentsIA / 10;
      int	s = this->_currentsIA % 10;

      if (this->_currentsIA > 0)
	this->_arrow[0]->affOnglet();
      if (this->_currentsIA != LIMIT_IA)
	this->_arrow[1]->affOnglet();

      //std::cout << "current:" << this->_currentsIA << "\tF:" << f << "\tS:" << s << std::endl;
      //Vector3f vectorPosition(71, 31, 0);

      if (f < 10)
	{
	  //this->_nbIA.at(f)->getImage()->setPosition(vectorPosition);
	  //this->_nbIA.at(f)->getImage()->initProp();
	  this->_nbIA.at(f)->affOnglet();
	}
      if (s < 10)
	{
	  // this->_nbIA.at(s)->getImage()->setPosition(vectorPosition);
	  this->_nbIA.at(s)->affOnglet();
	}
    }

    MenuEnum::eMenu	CustomizeMenu::getType() const
    {
      return MenuEnum::CUSTOMIZE;
    }

    void	CustomizeMenu::_cursorMove()
    {
      if (this->_cursor > CustomizeMenu::_nbOnglet)
        this->_cursor = 0;
      this->_menu->popBackOnglet();
      this->_menu->addOnglet(this->_hover[this->_cursor]);
      usleep(150000);
    }

    void	CustomizeMenu::_cursorRight()
    {
      if (this->_cursor == 0)
	{
	  if (this->_cursorNbPlayer == 0)
	    this->_cursorNbPlayer = 1;
	  else
	    this->_cursorNbPlayer = 0;
	  usleep(150000);
	}
      else if (this->_cursor == 2)
	{
	  if (this->_currentsIA >= LIMIT_IA)
	    this->_currentsIA = LIMIT_IA;
	  else
	    this->_currentsIA++;
	  usleep(150000);
	}
    }

    void	CustomizeMenu::_cursorLeft()
    {
      if (this->_cursor == 0)
	{
	  if (this->_cursorNbPlayer == 0)
	    this->_cursorNbPlayer = 1;
	  else
	    this->_cursorNbPlayer = 0;
	  usleep(150000);
	}
      else if (this->_cursor == 2)
	{
	  if ((this->_currentsIA - 1) <= 0)
	    this->_currentsIA = 0;
	  else
	    this->_currentsIA--;
	  usleep(150000);
	}
    }
  }
}
