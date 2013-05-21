#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Game.hpp>
#include <GameClock.hpp>
#include <Image.hpp>
#include <Input.hpp>
#include <Model.hpp>
#include <cstdlib>
#include <list>
#include <string>

#include "AObject.hpp"
#include "Vector.hpp"
#include "Camera.hpp"
#include "Menu.hpp"

#define WIDTH 1920
#define HEIGHT 1080

namespace BomberMan
{
    namespace Display
    {
        class MyGame : public gdl::Game
        {
        private:
            std::list<AObject*>   objects_;
            Camera		camera_;
            Menu			menu_;
            
        public:
            void		setMenu(const BomberMan::Display::Menu &);
            BomberMan::Display::Menu		getMenu() const;
            BomberMan::Display::Camera	*getCamera();
        public:
            MyGame() : gdl::Game()
            {}
            void  initialize();
            void  update(void);
            void	draw(void);
            void	unload(void);
            void	addObject(::std::string &, BomberMan::Display::Vector3f &, BomberMan::Display::Vector3f &);
        };
    }
}

#endif
