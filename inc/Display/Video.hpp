#ifndef __VIDEO_HPP__
#define __VIDEO_HPP__

#include <sstream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "AObject.hpp"

namespace BomberMan
{
  namespace Display
  {
    class Video
    {
    private:
      CvCapture*        _flux;
      bool		_isFinished;
      std::string	_sound;

    public:
      Video(const std::string &video, const std::string &associated_sound);

    public:
      void	draw(void);
      bool	isFinished();

      void	stopSound() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Video;
  }
}

#endif
