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
      gdl::Image    texture_;

    public:
      Texture2d(const std::string &texture, Vector3f &position,  Vector3f &rotation, Vector3f &len) : AObject(texture, position, rotation, len){}

    private:
      void	initialize();
      void	update(gdl::GameClock const &, gdl::Input &);
      void	draw(void);
      void	play(std::string const & _name, char state) {};
      void	stop(std::string const & name) {};
      double	get_anim_speed(std::string const &name) {};
      void	set_anim_speed(std::string const &name, double speed) {};
      void	info() {};
    };
  }
}

#endif
