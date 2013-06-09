#include "AGameComponent.hh"

namespace BomberMan
{
  namespace Field
  {
    float                               AGameComponent::getX() const
    {
      return this->_x;
    }

    void                                AGameComponent::setX(float x)
    {
      this->_x = x;
    }

    float                               AGameComponent::getY() const
    {
      return this->_y;
    }

    void                                AGameComponent::setY(float y)
    {
      this->_y = y;
    }

    BomberMan::Display::AObject *        AGameComponent::getAsset() const
    {
      return this->_asset;
    }

    void                                AGameComponent::setAsset(Display::AObject * asset)
    {
      this->_asset = asset;
    }

    BomberMan::Display::ISound *        AGameComponent::getSound() const
    {
      return this->_sound;
    }

    void                                AGameComponent::setSound(Display::ISound * sound)
    {
      this->_sound = sound;
    }

    bool				AGameComponent::isEnd() const
    {
      return (this->_end);
    }

    void				AGameComponent::setEnd(bool newBool)
    {
      this->_end = newBool;
    }

    BomberMan::Display::IAnimation *    AGameComponent::getAnimation() const
    {
      return this->_animation;
    }

    void                                AGameComponent::setAnimation(Display::IAnimation *animation)
    {
      this->_animation = animation;
    }
  }
}
