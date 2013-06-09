//
// CreditsMenu.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 21:25:38 2013 julien fortin
// Last update Sun Jun  9 06:40:01 2013 julien fortin
//

#include	"MenuManager.hh"
#include	"SoundManager.hh"
#include	"EndOfBomberMan.hh"
#include	"CreditsMenu.hh"
#include	"Clock.hpp"
#include	<unistd.h>

namespace BomberMan
{
  namespace Display
  {
    CreditsMenu::CreditsMenu()
    {
      this->_video = new Display::Video("./resources/videos/CreditsLight.avi",
					"./resources/sounds/CreditsLight.mp3");
      this->_creditTimer = new gdl::Clock();
      this->_creditTimer->play();
      this->FPS = 21;
      this->constElapsedTime = 1.0 / static_cast<float>(this->FPS);
    }

    CreditsMenu::~CreditsMenu()
    {
    }

    void	CreditsMenu::update()
    {
      static bool	playing = false;

      if (!playing)
	{
	  Sound::SoundManager::getInstance()->stopSound("./resources/sounds/musicIntro2.mp3");
	  playing = true;
	}

      if (!this->_video || (this->_video && this->_video->isFinished()))
        {
	  playing = false;
	  if (this->_video)
	    this->_video->stopSound();
	  Sound::SoundManager::getInstance()->playSound("./resources/sounds/musicIntro2.mp3", true);
	  MenuManager::getMenuManager()->menu(Display::MenuEnum::MAIN);
        }
      this->_creditTimer->update();
    }

    void	CreditsMenu::draw()
    {
      float	elapsedTime;

      elapsedTime = this->_creditTimer->getElapsedTime();
      //      std::cout << elapsedTime << std::endl;
      this->_creditTimer->getUpdateElapsedTime();
      this->_video->draw();
      if (elapsedTime < constElapsedTime)
       	usleep((constElapsedTime - elapsedTime) * 1000000);
    }

    MenuEnum::eMenu	CreditsMenu::getType() const
    {
      return MenuEnum::CREDITS;
    }
  }
}
