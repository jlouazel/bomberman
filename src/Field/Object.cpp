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
      this->_explosion = false;
    }

    Object::Object(const Object & other)
      :   _object_type(other._object_type), _buff_type(other._buff_type), _power(other._power), _timer(other._timer)
    {
      this->_x = other._x;
      this->_y = other._y;
      this->_asset = other._asset;
      this->_sound = other._sound;
      this->_animation = other._animation;
      this->_explosion = other._explosion;
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
	  this->bombExplode(this->_power, UP, manager);
	  this->bombExplode(this->_power, RIGHT, manager);
	  this->bombExplode(this->_power, DOWN, manager);
	  this->bombExplode(this->_power, LEFT, manager);
	  this->_end = true;
	  this->_runningTimer = 0;
	}
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

    void        Object::explode(int power)
    {
      
    }

    bool	Object::checkCase(int x, int y, Manager *manager)
    {
      std::list<IGameComponent *> Case = manager->get(x, y);

      std::cout << "SIZE = " << Case.size() << std::endl;
      for (std::list<IGameComponent *>::iterator it = Case.begin(); it != Case.end(); ++it)
	{
	  if (!(dynamic_cast<Empty *>(*it) == *it))
	    {
	      std::cout << "lalal" << std::endl;
	      if (dynamic_cast<Object *>(*it) == *it)
		std::cout << "Je suis un object." << std::endl;
	      return (true);
	    }
	}
      return (false);
    }

    void        Object::bombExplode(int damages, eDirection direction, Manager *manager)
    {
      if (this->_object_type == BOMB)
      	{
      	  int	i = 0;
	  switch (direction)
	    {
	    case UP :
	      {
		while (i < this->_power)
		  {
		    if (this->_x + i > manager->getHeight())
		      return;
		    manager->setExplosion(this->_x + i, this->_y, this->_power - i);
		    std::cout << "Explosion en : X = " << this->_x + i << " Y = " << this->_y << " deplacement up" << std::endl;
		    if (this->checkCase(this->_x + i, this->_y, manager) == true)
		      return;
		    i++;
		  }
	      }
	    case DOWN :
	      {
		while (i < this->_power)
		  {
		    if (this->_x - i < 0)
		      return;
		    manager->setExplosion(this->_x - i, this->_y, this->_power - i);
		    std::cout << "Explosion en : X = " << this->_x - i << " Y = " << this->_y << " deplacement down" << std::endl;
		    if (this->checkCase(this->_x - i, this->_y, manager) == true)
		      return;
		    i++;
		  }
	      }
	    case LEFT :
	      {
		while (i < this->_power)
		  {
		    if (this->_y - i < 0)
		      return;
		    manager->setExplosion(this->_x, this->_y - i, this->_power - i);
		    std::cout << "Explosion en : X = " << this->_x << " Y = " << this->_y - i << " deplacement left" << std::endl;
		    if (this->checkCase(this->_x, this->_y - i , manager) == true)
		      return;
		    i++;
		  }
	      }
	    case RIGHT :
	      {
		while (i < this->_power)
		  {
		    if (this->_y + i > manager->getWidth())
		      return;
		    manager->setExplosion(this->_x, this->_y + i, this->_power - i);
		    std::cout << "Explosion en : X = " << this->_x << " Y = " << this->_y + i << " deplacement right" << std::endl;
		    if (this->checkCase(this->_x, this->_y + i, manager) == true)
		      return;
		    i++;
		  }
	      }
	    }
	  // propagation++
	}
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
