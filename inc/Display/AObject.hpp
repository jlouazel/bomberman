#ifndef __AOBJECT_HPP__
#define __AOBJECT_HPP__

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
#include "Vector.hpp"
#include "Camera.hpp"

namespace BomberMan
{
    namespace Display
    {
        class    AObject
        {
        protected:
            Vector3f	position_;
            Vector3f	rotation_;
            Vector3f	len_;
            gdl::Image	texture_;
            Camera	*camera_;
            // protected:
            //   void		relativeRotation();
        public:
            AObject(std::string &texture, BomberMan::Display::Vector3f &position, BomberMan::Display::Vector3f &len, BomberMan::Display::Camera *camera);
            virtual void	initialize(void) = 0;
            virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
            virtual void	draw(void) = 0;
        };
    }
}

#endif
