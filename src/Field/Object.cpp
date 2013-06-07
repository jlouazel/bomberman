#include "Object.hh"

namespace BomberMan
{
  namespace Field
  {
    Object::Object(float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim, eObjectType objectType, eBuffType buffType, int power, int timer)
      : _object_type(objectType), _buff_type(buffType), _power(power), _timer(timer)
    {
      this->_x = x;
      this->_y = y;
      this->_asset = asset;
      this->_sound = sound;
      this->_animation = anim;
      this->_runningTimer = 0;
      this->_end = false;
    }

    Object::Object(const Object & other)
      :   _object_type(other._object_type), _buff_type(other._buff_type), _power(other._power), _timer(other._timer)
    {
      this->_x = other._x;
      this->_y = other._y;
      this->_asset = other._asset;
      this->_sound = other._sound;
      this->_animation = other._animation;
    }

    Object::~Object()
    {
    }

    void	Object::setX(float x)
    {
      Display::Vector3f newVectorPosition(x * 220, this->_asset->getPosition().getY(), this->_asset->getPosition().getZ());
      this->_x = x;
      std::cout << "x = " << x << "X = " << x * 220 << std::endl;
      this->_asset->setPosition(newVectorPosition);
    }

    void	Object::setY(float y)
    {
      Display::Vector3f newVectorPosition(this->_asset->getPosition().getX(), this->_asset->getPosition().getY(), y * 220);
      this->_y = y;
      this->_asset->setPosition(newVectorPosition);
    }

    void	Object::initialize()
    {
      this->_asset->initialize();
    }

    void        Object::update(gdl::GameClock const & gameClock, Manager *manager)
    {
      this->_asset->update(gameClock);
      this->_runningTimer += gameClock.getElapsedTime();
      if (this->_runningTimer >= this->_timer)
	{
	  this->explode(this->_power, UP);
	  this->explode(this->_power, RIGHT);
	  this->explode(this->_power, DOWN);
	  this->explode(this->_power, LEFT);
	  // this->explode(this->_power, UP, manager);
	  // this->explode(this->_power, RIGHT, manager);
	  // this->explode(this->_power, DOWN, manager);
	  // this->explode(this->_power, LEFT, manager);
	  this->_end = true;
	}
    }

    bool	Object::isEnd() const
    {
      return (this->_end);
    }

    void        Object::draw(gdl::GameClock const & gameClock)
    {
      this->_asset->draw();
    }

    eObjectType Object::getObjectType() const
    {
      return this->_object_type;
    }

    eBuffType   Object::getBuffType() const
    {
      return this->_buff_type;
    }

    void        Object::setPower(int power)
    {
      this->_power = power;
    }

    int         Object::getPower() const
    {
      return this->_power;
    }

    int         Object::getTimer() const
    {
      return this->_timer;
    }

    void        Object::explode(int damages, eDirection direction)//, Manager *manager)
    {
      if (this->_object_type == BOMB)
	{
	  std::cout << "Explosion !" << std::endl;
	  // propagation++
	}
      // propagation
      // delete this;
    }

    bool	Object::operator==(IGameComponent *objectToCompare)
    {
      if (dynamic_cast<Object *>(objectToCompare) == objectToCompare)
	{
	  Object *object = static_cast<Object *>(objectToCompare);
	  if (this->_power == object->getPower() && this->_object_type == object->getObjectType() && this->_buff_type == object->getBuffType())
	    return (true);
	}
      return (false);
    }
  }
}
