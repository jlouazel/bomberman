#ifndef __TEXTURE2D_HPP__
#define __TEXTURE2D_HPP__

#include "AObject.hpp"

namespace BomberMan
{
  namespace Display
  {
    class Texture2d : public AObject
    {
    private:
      gdl::Image	_texture;

    public:
      Texture2d(const std::string &texture, Vector3f &position,  Vector3f &rotation, Vector3f &len) : AObject(texture, position, rotation, len){}

      void	initialize();
      void	update(gdl::GameClock const &);
      void	draw(void);
      void	play(std::string const &, char) {};
      void	stop(std::string const &) {};
      double	get_anim_speed(std::string const &) { return 0; };
      void	set_anim_speed(std::string const &, double) {};
      void	info() {};
      void	setColor(unsigned char, unsigned char, unsigned char) {};
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Texture2d;
  }
}

#endif
