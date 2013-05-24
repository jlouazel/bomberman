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
      Texture3d(std::string &, Vector3f &, Vector3f &, Vector3f &, Camera *);
      ~Texture3d();

      void	initialize();
      void	update(gdl::GameClock const &, gdl::Input &);
      void	draw();
    };
  }
}
#endif