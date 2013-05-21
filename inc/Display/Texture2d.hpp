#ifndef __TEXTURE2D_HPP__
#define __TEXTURE2D_HPP__

#include "AObject.hpp"

namespace BomberMan
{
    namespace Display
    {
        class Texture2d : public AObject
        {
        public:
            Texture2d(std::string &texture, Vector3f &position, Vector3f len, Camera *camera) : AObject(texture, position, len, camera)
            {}
        private:
            void initialize();
            void update(gdl::GameClock const &, gdl::Input &);
            void draw(void);
        };
    }
}

#endif
