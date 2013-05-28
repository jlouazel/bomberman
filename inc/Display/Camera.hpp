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
            float		angle_;
            int		widthScreen_;
            int		heightScreen_;
        public:
            Camera(void);
        public:
            Vector3f	getPosition() const;
            Vector3f	getRotation() const;
            Vector3f      getLook() const;
            float		getAngle() const;
            int		getHeightScreen() const;
            int		getWidthScreen() const;
            void		setPosition(Vector3f &);
            void		setRotation(Vector3f &);
            void		setLook(Vector3f &);
            void		setAngle(float);
        public:
            void	initialize(void);
            void	update(gdl::GameClock const &, gdl::Input &);
        };
    }
}

#endif
