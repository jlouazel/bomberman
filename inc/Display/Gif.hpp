#ifndef __GIF_HPP__
#define __GIF_HPP__

#include <sstream>
#include "AObject.hpp"

namespace BomberMan
{
  namespace Display
  {
    class Gif
    {
    private:
      int			number_of_frames;
      std::list<AObject *>	_frames;

    public:
      Gif(const std::string &texture_begining, Vector3f &position, Vector3f &rotation, Vector3f &len, int number_of_frames);

    public:
      void	initialize();
      void	draw(void);
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Gif;
  }
}

#endif
