#ifndef __AOBJECT_HPP__
#define __AOBJECT_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Game.hpp>
#include <GameClock.hpp>
#include <Image.hpp>
#include <Input.hpp>
#include <Model.hpp>
#include <string>

#include "Vector.hpp"
#include "Camera.hpp"

namespace BomberMan
{
  namespace Display
  {
    class    AObject
    {
    protected:
      std::string		stringTexture_;
      Vector3f		position_;
      Vector3f		rotation_;
      Vector3f		len_;
    public:
      AObject(const std::string &texture, Vector3f &position, Vector3f &rotation, Vector3f &len);

      virtual void	initialize(void) = 0;
      virtual void	update(gdl::GameClock const &) = 0;
      virtual void	draw(void) = 0;
      virtual void	play(std::string const & _name, char state) = 0;
      virtual void	stop(std::string const & name) = 0;
      virtual double	get_anim_speed(std::string const &name) = 0;
      virtual void	set_anim_speed(std::string const &name, double speed) = 0;
      virtual void	info() = 0;
      virtual void	setColor(unsigned char r, unsigned char g, unsigned char b) = 0;
      virtual bool      anim_is_ended() const = 0;

      void			setRotation(Vector3f &);
      void			setPosition(Vector3f &);
      void			setLen(Vector3f &);
      Vector3f		getRotation() const;
      Vector3f		getPosition() const;
      Vector3f		getLen() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class AObject;
  }
}

#endif
