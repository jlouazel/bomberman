#include "Vector.hpp"

namespace BomberMan
{
    namespace Display
    {
        Vector3f::Vector3f(void)
        : x(0.0f), y(0.0f), z(0.0f)
        {
        }
        
        Vector3f::Vector3f(float x, float y, float z)
        : x(x), y(y), z(z)
        {
        }
        
        float	Vector3f::getX() const
        {
            return (this->x);
        }
        
        float	Vector3f::getY() const
        {
            return (this->y);
        }
        
        float	Vector3f::getZ() const
        {
            return (this->z);
        }
        
        void	Vector3f::setX(float x)
        {
            this->x = x;
        }
        
        void	Vector3f::setY(float y)
        {
            this->y = y;
        }
        
        void	Vector3f::setZ(float z)
        {
            this->z = z;
        }
    }
}