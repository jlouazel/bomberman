#include <list>
#include <iostream>
#include <Image.hpp>
#include <math.h>
#include <unistd.h>
#include "MyGame.hpp"
#include "Gif.hpp"

namespace BomberMan
{
  namespace Display
  {
    Gif*	Gif::_gif = 0;

    Gif*	Gif::getGif()
    {
      if (!Gif::_gif)
	{
	  Vector3f      vectorPosition(20, 0, 0);
	  Vector3f      vectorLen(60.0, 100.0, 0.0);
	  Vector3f      vectorRotation(0.0, 0.0, 0.0);

	  Gif::_gif = new Gif("./resources/images/Running", vectorPosition, vectorRotation, vectorLen, 16);
	}
      return Gif::_gif;
    }

    void	Gif::deleteGif()
    {
      if (Gif::_gif)
	delete Gif::_gif;
      Gif::_gif = 0;
    }

    Gif::Gif(const std::string &texture_begining, Vector3f &position, Vector3f &rotation, Vector3f &len, int number_of_frames) : number_of_frames(number_of_frames)
    {
      for (int i = 0; i < number_of_frames; i++)
	{
	  std::ostringstream	ostream;
	  ostream << i;
	  this->_frames.push_back(new Texture2d(texture_begining + "_" + ostream.str() + ".jpg", position, rotation, len));
	}
      this->initialize();
    }

    void	Gif::initialize()
    {
      for (std::list<AObject *>::iterator it = this->_frames.begin(); it != this->_frames.end(); it++)
	(*it)->initialize();
    }

    void	Gif::draw(void)
    {
      static int	current_frame = 0;
      int		i = 0;
      for (std::list<AObject *>::iterator it = this->_frames.begin(); it != this->_frames.end(); it++)
	  {
	    if (i == current_frame)
	      {
		std::cout << "Draw=" << current_frame << std::endl;
		(*it)->draw();
	      }
	    i++;
	  }
      current_frame++;
      current_frame = current_frame % this->number_of_frames;
    }
  }
}
