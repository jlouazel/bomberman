#include <utility>

#include "ObjectFactory.hh"
#include "FieldError.hh"

namespace BomberMan
{
  namespace Field
  {
    ObjectFactory::ObjectFactory()
    {
      this->learn(std::pair<eObjectType, eBuffType>(BOMB, NONE), new Object(0.0, 0.0, 0, 0, 0, BOMB, NONE, 3, 5, -1));
      this->learn(std::pair<eObjectType, eBuffType>(BUFF, LIFE), new Object(0.0, 0.0, 0, 0, 0, BUFF, LIFE, 2, 10, -1));
      this->learn(std::pair<eObjectType, eBuffType>(BUFF, SPEED), new Object(0.0, 0.0, 0, 0, 0, BUFF, SPEED, 1, 10, -1));
      this->learn(std::pair<eObjectType, eBuffType>(BUFF, RANGE), new Object(0.0, 0.0, 0, 0, 0, BUFF, RANGE, 1, 10, -1));
    }

    ObjectFactory::~ObjectFactory()
    {
    }

    void        ObjectFactory::learn(std::pair<eObjectType, eBuffType> type, Object * object)
    {
      this->_objects.insert(std::pair<std::pair<eObjectType, eBuffType>, Object *>(type, object));
    }

    Object *    ObjectFactory::create(std::pair<eObjectType, eBuffType> type) const
    {
      if (this->_objects.find(type) != this->_objects.end())
	return new Object(*(this->_objects.find(type))->second);
      else
	throw FieldError(std::string("Failed to create an instance of type 'Object'"), std::string("ObjectFactory::create"), std::string("Trying to create an unknown object"));
    }
  }
}
