#ifndef BomberMan_IGameComponent_h
#define BomberMan_IGameComponent_h

#include <iostream>

#include "Enums.hh"
#include "IAsset.hh"
#include "ISound.hh"
#include "IAnimation.hh"

namespace BomberMan
{
    namespace Field
    {
        class IGameComponent
        {
        public:
            virtual ~IGameComponent(){}

            virtual void					explode(int, eDirection) = 0;
            virtual float					getX() const = 0;
            virtual void					setX(float) = 0;
            virtual float					getY() const = 0;
            virtual void					setY(float) = 0;
            virtual Display::IAsset *		getAsset() const = 0;
            virtual void					setAsset(Display::IAsset *) = 0;
            virtual Display::ISound *		getSound() const = 0;
            virtual void					setSound(Display::ISound *) = 0;
            virtual Display::IAnimation *	getAnimation() const = 0;
            virtual void					setAnimation(Display::IAnimation *) = 0;
        };
    }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class IGameComponent;
  }
}

#endif
