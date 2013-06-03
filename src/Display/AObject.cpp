#include <math.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include "MyGame.hpp"
#include "AObject.hpp"
#include "Vector.hpp"

namespace BomberMan
{
    namespace Display
    {
        AObject::AObject(const std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len)
	  : position_(position), rotation_(rotation), len_(len)
        {
	  this->stringTexture_ = texture;
	  std::cout << texture << std::endl;
        }

        void    AObject::setRotation(Vector3f &rotation)
        {
            this->rotation_ = rotation;
        }

        void    AObject::setPosition(Vector3f &position)
        {
            this->position_ = position;
        }

        void    AObject::setLen(Vector3f &len)
        {
            this->len_ = len;
        }

        Vector3f        AObject::getRotation() const
        {
            return (this->rotation_);
        }

        Vector3f        AObject::getPosition() const
        {
            return (this->position_);
        }

        Vector3f        AObject::getLen() const
        {
            return (this->len_);
        }
    }
}
