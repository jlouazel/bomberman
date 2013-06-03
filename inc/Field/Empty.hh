#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include "AGameComponent.hh"

#include "AObject.hpp"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
    namespace Field
    {
        class Empty : public AGameComponent
        {
        public:
            Empty(float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
            ~Empty();

            void	explode(int, eDirection);
        };
    }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Empty;
  }
}

#endif
