#ifndef __SOUND_MANAGER_HH__
#define __SOUND_MANAGER_HH__

#include <map>
#include <string>
#include <fmod.h>

namespace BomberMan
{
  namespace Sound
  {
    class SoundManager
    {
    private:
      static SoundManager *_instance;
      FMOD_SYSTEM	*_system;
      FMOD_CHANNEL	*_music;
      FMOD_CHANNEL	*_sound;
      std::map<std::string, FMOD_SOUND *>	_sounds;

    private:
      SoundManager();
      SoundManager(SoundManager const& copy);
      SoundManager& operator=(SoundManager const& copy);
      ~SoundManager();

    public:
      static	SoundManager *getInstance();
      void      addNewSound(const std::string &sound);
      void	playSound(const std::string &sound, bool loop);
      void	stopSound(const std::string &sound);

    };
  }
}

#else

namespace BomberMan
{
  namespace Sound
  {
    class SoundManager;
  }
}

#endif
