#include	"BomberMan.hh"
#include	"Video.hpp"
#include	"SoundManager.hh"

namespace BomberMan
{
    namespace Display
    {
      Video::Video(const std::string &video, const std::string &associated_sound)
      {
	this->_isFinished = false;
	Sound::SoundManager::getInstance()->playSound(associated_sound, false);
	this->_flux = cvCaptureFromAVI(video.c_str());
	if (!this->_flux)
	  this->_isFinished = true;
      }

      void	Video::draw(void)
      {
	if (cvGrabFrame(this->_flux))
	  {
	    IplImage* image = cvRetrieveFrame(this->_flux);

	    cvCvtColor(image, image, CV_BGR2RGB);
	    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->width,
			      image->height, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);
	    glEnable(GL_TEXTURE_2D);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
	    gluOrtho2D(0, 800, 1600, 0);
	    glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();
	    glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 0.0f);
	    glVertex2f(0, 0);
	    glTexCoord2f(0.0f, 1.0f);
	    glVertex2f(0, 1600);
	    glTexCoord2f(1.0f, 1.0f);
	    glVertex2f(800, 1600);
	    glTexCoord2f(1.0f, 0.0f);
	    glVertex2f(800, 0);
	    glEnd();
	  }	
      }
      
      bool	Video::isFinished()
      {
	return (this->_isFinished);
      }
    }
}
