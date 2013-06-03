#ifndef __TEXTURE3D_HPP__
#define __TEXTURE3D_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Model.hpp>
#include "AObject.hpp"

namespace BomberMan
{
    namespace Display
    {
        class Texture3d : public AObject
        {
        private:
            gdl::Model model_;
            
        public:
            Texture3d(const std::string &, Vector3f &, Vector3f &, Vector3f &);
            ~Texture3d();
            
            void	initialize();
            void	update(gdl::GameClock const &);
            void	draw();
            void	play(std::string const & _name, char state);
            void	stop(std::string const & name);
            double	get_anim_speed(std::string const &name);
            void	set_anim_speed(std::string const &name, double speed);
            void	info();
        };
    }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Texture3d;
  }
}

#endif
