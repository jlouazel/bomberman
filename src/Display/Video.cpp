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
	this->_sound = associated_sound;
	this->_flux = cvCaptureFromAVI(video.c_str());
	if (!this->_flux)
	  this->_isFinished = true;
      }

      void	Video::draw(void)
      {
	static int	i = 0;

	if (i == 0)
	  {
	    Sound::SoundManager::getInstance()->playSound(this->_sound, false);
	    i = 1;
	  }
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
	else
	  this->_isFinished = true;
      }

      bool	Video::isFinished()
      {
	return (this->_isFinished);
      }

      void	Video::stopSound() const
      {
	Sound::SoundManager::getInstance()->stopSound(this->_sound);
      }
    }
}