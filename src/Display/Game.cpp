#include <string>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Game.hpp>
#include <GameClock.hpp>
#include <Image.hpp>
#include <Input.hpp>
#include <Model.hpp>
#include <string>
#include <iostream>
#include "MyGame.hpp"
#include "AObject.hpp"
#include "Texture2d.hpp"
#include "Texture3d.hpp"
#include "Vector.hpp"
#include "IOnglet.hpp"
#include "OngletMenu.hpp"

namespace BomberMan
{
    namespace Display
    {
        void	MyGame::initialize()
        {
	  // Vector3f      vectorPosition(25, 15, 0);
	  // Vector3f      vectorLen(50.0, 8.0, 0.0);
	  // Vector3f      vectorRotation(0.0, 0.0, 0.0);
	  Vector3f      vectorPosition(500, 0, -500);
	  Vector3f      vectorLen(0.0, 0.0, 0.0);
	  Vector3f      vectorRotation(0.0, 0.0, 0.0);
	  IOnglet       *newOnglet;

	  this->_core = new Core::Core;
	  window_.setWidth(WIDTH);
	  window_.setHeight(HEIGHT);
	  window_.create();
	  camera_.initialize();
	  Menu	*firstMenu = new Menu("texture/Fond.jpg");
	  Menu	*continueGame = new Menu("texture/Fond.jpg");

	  newOnglet = new OngletMenu(continueGame, "continueGame", new Texture2d("texture/continuegame.png", vectorPosition, vectorRotation, vectorLen));
	  firstMenu->addOnglet(newOnglet);
	  vectorPosition.setY(28);
	  newOnglet = new OngletMenu(continueGame, "newGame", new Texture2d("texture/newgame.png", vectorPosition, vectorRotation, vectorLen));
	  firstMenu->addOnglet(newOnglet);
	  vectorPosition.setY(41);
	  newOnglet = new OngletMenu(continueGame, "option", new Texture2d("texture/options.png", vectorPosition, vectorRotation, vectorLen));
	  firstMenu->addOnglet(newOnglet);
	  vectorPosition.setY(54);
	  newOnglet = new OngletMenu(continueGame, "credit", new Texture2d("texture/credits.png", vectorPosition, vectorRotation, vectorLen));
	  firstMenu->addOnglet(newOnglet);
	  vectorPosition.setY(67);
	  newOnglet = new OngletMenu(continueGame, "quit", new Texture2d("texture/quit.png", vectorPosition, vectorRotation, vectorLen));
	  firstMenu->addOnglet(newOnglet);
	  this->menu_ = *firstMenu;
	  this->menu_.initialize();
	  this->addObject3d("libgdl/assets/marvin.fbx", vectorPosition, vectorRotation, vectorLen);
	  std::list<AObject*>::iterator itb = this->objects_.begin();
	  for (; itb != this->objects_.end(); ++itb)
	    (*itb)->initialize();
        }

        void	MyGame::addObject2d(const std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len)
        {
            AObject *newObject = new Texture2d(texture, position, rotation, len);
            
            this->objects_.push_back(newObject);
        }
        
        void	MyGame::addObject3d(const std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len)
        {
            AObject *newObject = new Texture3d(texture, position, rotation, len);
            
            this->objects_.push_back(newObject);
        }
        
        void	MyGame::setMenu(const Menu &menu)
        {
            this->menu_ = menu;
        }
        
        Menu	MyGame::getMenu() const
        {
            return (this->menu_);
        }
        
        Camera  *MyGame::getCamera()
        {
            return (&this->camera_);
        }
        
        void	MyGame::update(void)
        {
	  /* Core::update();*/
	  std::list<AObject*>::iterator itb = this->objects_.begin();
	  for (; itb != this->objects_.end(); ++itb)
	    (*itb)->update(gameClock_, input_);
	  camera_.update(gameClock_, input_);
	  this->menu_.update();
        }
        
        void	MyGame::draw(void)
        {
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
	  glClearDepth(1.0f);
	  std::list<AObject*>::iterator itb = this->objects_.begin();
	  for (; itb != this->objects_.end(); ++itb)
	    (*itb)->draw();
	  // this->menu_.affAllOnglet();
        }

        void	MyGame::unload(void)
        {
        }
    }
}
