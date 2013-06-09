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

namespace BomberMan
{
  namespace Display
  {
    CreditsMenu::CreditsMenu()
    {
      this->_video = new Display::Video("./resources/videos/CreditsLight.avi",
					"./resources/sounds/CreditsLight.mp3");
    }

    CreditsMenu::~CreditsMenu()
    {
    }

    void	CreditsMenu::update()
    {
      if (!this->_video || (this->_video && this->_video->isFinished()))
        {
	  if (this->_video)
	    this->_video->stopSound();
	  Sound::SoundManager::getInstance()->playSound("./resources/sounds/musicIntro2.mp3", true);
	  MenuManager::getMenuManager()->menu(Display::MenuEnum::MAIN);
        }
    }

    void	CreditsMenu::draw()
    {
      this->_video->draw();
    }

    MenuEnum::eMenu	CreditsMenu::getType() const
    {
      Sound::SoundManager::getInstance()->stopSound("./resources/sounds/musicIntro2.mp3");
      return MenuEnum::CREDITS;
    }
  }
}
