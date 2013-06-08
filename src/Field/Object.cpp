#include "Object.hh"
#include "Wall.hh"

namespace BomberMan
{
  namespace Field
  {
    Object::Object(float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim, eObjectType objectType, eBuffType buffType, int power, int timer, int idPlayer)
      : _object_type(objectType), _buff_type(buffType), _power(power), _timer(timer), _idPlayer(idPlayer)
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
      if (this->_runningTimer >= this->_timer && this->_object_type == BOMB)
	{
	  std::cout << "Y = " << this->_y << " X = " << this->_x << std::endl;
	  manager->setExplosion(this->_y, this->_x, 10);
	  manager->initFrame(this->_y, this->_x, 2);
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

    void        Object::explode(int power, Manager *, int idBomb)
    {
      if (this->_object_type == BOMB)
	this->_runningTimer = this->_timer;
    }

    bool	Object::checkCase(int x, int y, Manager *manager)
    {
      std::list<IGameComponent *> Case = manager->get(x, y);

      for (std::list<IGameComponent *>::iterator it = Case.begin(); it != Case.end(); ++it)
	{
	  if (dynamic_cast<Wall *>(*it) == *it)
	    return (true);
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
	    	    if (this->_x + i > manager->getHeight() - 1)
	    	      return;
	    	    manager->setExplosion(this->_y, this->_x + i, this->_power - i);
		    manager->initFrame(this->_y, this->_x + i, 0);
	    	    if (this->checkCase(this->_y, this->_x + i, manager) == true)
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
	    	    manager->setExplosion(this->_y, this->_x - i, this->_power - i);
		    manager->initFrame(this->_y, this->_x - i, 1);
	    	    if (this->checkCase(this->_y, this->_x - i, manager) == true)
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
	    	    manager->setExplosion(this->_y - i, this->_x, this->_power - i);
		    manager->initFrame(this->_y - i, this->_x, 1);
	    	    if (this->checkCase(this->_y - i, this->_x , manager) == true)
	    	      return;
	    	    i++;
	    	  }
	      }
	    case RIGHT :
	      {
	    	while (i < this->_power)
	    	  {
	    	    if (this->_y + i > manager->getWidth() - 1)
	    	      return;
	    	    manager->setExplosion(this->_y + i, this->_x, this->_power - i);
		    manager->initFrame(this->_y + i, this->_x, 0);
	    	    if (this->checkCase(this->_y + i, this->_x, manager) == true)
	    	      return;
	    	    i++;
	    	  }
	      }
	    }
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
