#include "Vector.hpp"

BomberMan::Display::Vector3f::Vector3f(void)
  : x(0.0f), y(0.0f), z(0.0f)
{
}

BomberMan::Display::Vector3f::Vector3f(float x, float y, float z)
  : x(x), y(y), z(z)
{
}

float	BomberMan::Display::Vector3f::getX() const
{
  return (this->x);
}

float	BomberMan::Display::Vector3f::getY() const
{
  return (this->y);
}

float	BomberMan::Display::Vector3f::getZ() const
{
  return (this->z);
}

void	BomberMan::Display::Vector3f::setX(float x)
{
  this->x = x;
}

void	BomberMan::Display::Vector3f::setY(float y)
{
  this->y = y;
}

void	BomberMan::Display::Vector3f::setZ(float z)
{
  this->z = z;
}
