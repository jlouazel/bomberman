#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

namespace BomberMan
{
    namespace Display
    {
        class Vector3f
        {
        private:
            float x;
            float y;
            float z;
        public:
            Vector3f(void);
            Vector3f(float x, float y, float z);
            float	getX() const;
            float	getY() const;
            float	getZ() const;
            void	setX(float);
            void	setY(float);
            void	setZ(float);
        };
    }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Vector3f;
  }
}

#endif
