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

namespace BomberMan
{
    namespace Display
    {
        void	MyGame::initialize()
        {
            this->_core = new Core::Core;
            window_.setWidth(WIDTH);
            window_.setHeight(HEIGHT);
            window_.create();
            camera_.initialize();
            std::list<AObject*>::iterator itb = this->objects_.begin();
            for (; itb != this->objects_.end(); ++itb)
                (*itb)->initialize();
        }
        
        void	MyGame::addObject2d(std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len)
        {
            AObject *newObject = new Texture2d(texture, position, rotation, len);
            
            this->objects_.push_back(newObject);
        }
        
        void	MyGame::addObject3d(std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len)
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
        }
        
        void	MyGame::draw(void)
        {
            // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            // glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
            // glClearDepth(1.0f);
            // std::list<AObject*>::iterator itb = this->objects_.begin();
            // for (; itb != this->objects_.end(); ++itb)
            //   (*itb)->draw();
            this->menu_.affAllOnglet();
        }
        
        void	MyGame::unload(void)
        {
        }
    }
}