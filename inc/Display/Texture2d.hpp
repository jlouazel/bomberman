#ifndef __TEXTURE2D_HPP__
#define __TEXTURE2D_HPP__

#include "AObject.hpp"

namespace BomberMan
{
    namespace Display
    {
        class Texture2d : public AObject
        {
	private:
	  gdl::Image    texture_;
        public:
	  Texture2d(std::string &texture, Vector3f &position,  Vector3f &rotation, Vector3f &len) : AObject(texture, position, rotation, len)
	  {}
        private:
            void initialize();
            void update(gdl::GameClock const &, gdl::Input &);
            void draw(void);
        };
    }
}

#endif
