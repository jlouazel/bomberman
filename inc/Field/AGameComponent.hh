#ifndef __BOMBERMAN__AGAMECOMPONENT__
#define __BOMBERMAN__AGAMECOMPONENT__

#include <Input.hpp>
#include <Clock.hpp>
#include <GameClock.hpp>
#include "IGameComponent.hh"
#include "AObject.hpp"
#include "FManager.hh"

namespace BomberMan
{
  namespace Field
  {
    class AGameComponent : public IGameComponent
    {
    protected:
      float					_x;
      float					_y;
      Display::AObject *			_asset;
      Display::ISound *		_sound;
      Display::IAnimation *	_animation;
      bool			_end;

    public:
      virtual ~AGameComponent(){}

      virtual void					explode(int) = 0;
      virtual bool                      operator==(IGameComponent *) = 0;
      virtual bool        isEnd() const;
      virtual void  draw(gdl::GameClock const &) = 0;
      virtual void  update(gdl::GameClock const &, Manager *) = 0;
      virtual float					getX() const;
      virtual void					setX(float);
      virtual float					getY() const;
      virtual void					setY(float);
      virtual Display::AObject *		getAsset() const;
      virtual void					setAsset(Display::AObject *);
      virtual Display::ISound *		getSound() const;
      virtual void					setSound(Display::ISound *);
      virtual Display::IAnimation *   getAnimation() const;
      virtual void					setAnimation(Display::IAnimation *);

    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class AGameComponent;
  }
}

#endif /* defined(__BomberMan__AGameComponent__) */
