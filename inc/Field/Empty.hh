#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include "AGameComponent.hh"

#include "IAsset.hh"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
    namespace Field
    {
        class Empty : public AGameComponent
        {
        public:
            Empty(float x, float y, Display::IAsset * asset = 0, Display::ISound * sound = 0, Display::IAnimation * anim = 0);
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
