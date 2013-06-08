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
      Gif::Gif(const std::string &texture_begining, Vector3f &position, Vector3f &rotation, Vector3f &len, int number_of_frames) : number_of_frames(number_of_frames)
      {
	std::ostringstream	ostream;

	for (int i = 0; i < number_of_frames; i++)
	  {
	    ostream << i;
	    this->_frames.push_back(new Texture2d(texture_begining + "_" + ostream.str() + ".jpg", position, rotation, len));
	  }
      }

      void	Gif::initialize()
      {
	for (std::list<AObject *>::iterator it = this->_frames.begin(); it != this->_frames.end(); it++)
	  (*it)->initialize();
      }

      void	Gif::draw(void)
      {
	static int	current_frame;
	int		i = 0;
	for (std::list<AObject *>::iterator it = this->_frames.begin(); it != this->_frames.end(); it++)
	  {
	    if (i == current_frame)
	      (*it)->draw();
	    i++;
	  }
	current_frame++;
	current_frame = current_frame % this->number_of_frames;
      }
    }
}
