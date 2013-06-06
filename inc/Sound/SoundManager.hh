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