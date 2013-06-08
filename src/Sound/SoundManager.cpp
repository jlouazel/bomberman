#include <iostream>
#include <algorithm>
#include "SoundManager.hh"

namespace BomberMan
{
  namespace Sound
  {
    SoundManager *SoundManager::_instance = 0;

    SoundManager::SoundManager()
    {
      FMOD_System_Create(&this->_system);
      FMOD_System_Init(this->_system, 1024, FMOD_INIT_NORMAL, 0);
    }
    SoundManager	*SoundManager::getInstance()
    {
      if (!SoundManager::_instance)
	SoundManager::_instance = new SoundManager;
      return SoundManager::_instance;
    }
    void	SoundManager::addNewSound(const std::string &sound)
    {
      FMOD_SOUND *s;
      FMOD_RESULT check;

      check = FMOD_System_CreateSound(this->_system, sound.c_str(), FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &s);
      if (check != FMOD_OK)
	std::cout << "Cannot load " << sound << std::endl;
      else
	this->_sounds[sound] = s;
    }

    void	SoundManager::playSound(const std::string &sound, bool loop)
    {
      if (loop)
	{
	  FMOD_Sound_SetLoopCount(this->_sounds[sound], -1);
	  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_sounds[sound], 0, 0);
	}
      else
	{
	  FMOD_Sound_SetLoopCount(this->_sounds[sound], 0);
	  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_sounds[sound], 0, 0);
	}
    }

    void	SoundManager::stopSound(const std::string &sound)
    {
      FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_sounds[sound], 1, 0);
    }

    static	void	releaseSounds(std::pair<const std::string, FMOD_SOUND*> i)
    {
      FMOD_Sound_Release(i.second);
    }

    SoundManager::~SoundManager()
    {
      for_each(this->_sounds.begin(), this->_sounds.end(), releaseSounds);
      FMOD_System_Close(this->_system);
      FMOD_System_Release(this->_system);
    }
  }
}

