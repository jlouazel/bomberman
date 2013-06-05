#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "GameClock.hpp"
#include "Input.hpp"
#include "Vector.hpp"

namespace BomberMan
{
  namespace Display
  {
    class Camera
    {
    private:
      Vector3f	position_;
      Vector3f	rotation_;
      Vector3f	look_;
      float	angle_;
      int	widthScreen_;
      int	heightScreen_;
      int	distanceX;
      int	distanceY;

    public:
      Camera(void);

      Vector3f	getPosition() const;
      Vector3f	getRotation() const;
      Vector3f	getLook() const;
      int	getDistanceX() const;
      int	getDistanceY() const;
      float		getAngle() const;
      int			getHeightScreen() const;
      int			getWidthScreen() const;
      void		setPosition(Vector3f &);
      void		setRotation(Vector3f &);
      void		setLook(Vector3f &);
      void		setAngle(float);
      void		initialize(void);
      void		update(gdl::GameClock const &);
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Camera;
  }
}

#endif
