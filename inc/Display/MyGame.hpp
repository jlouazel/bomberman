#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include <Clock.hpp>
#include <Color.hpp>
#include <Game.hpp>
#include <GameClock.hpp>
#include <Image.hpp>
#include <Input.hpp>
#include <Model.hpp>
#include <cstdlib>
#include <list>
#include <string>

#include "OngletMenu.hpp"
#include "Texture2d.hpp"
#include "Texture3d.hpp"
#include "AObject.hpp"
#include "IOnglet.hpp"
#include "Vector.hpp"
#include "Camera.hpp"
#include "Vector.hpp"
#include "Menu.hpp"

#define WIDTH 1920
#define HEIGHT 1080

namespace BomberMan
{
  namespace Display
  {
    class MyGame : public gdl::Game
    {
    private:
      std::list<AObject*>	objects_;
      Camera			camera_;
      Menu			menu_;
      //Engine::Core *		_core;

    public:
      MyGame() : ::gdl::Game(){}

      void	initialize();
      void	update(void);
      void	draw(void);
      void	unload(void);
      void	addObject3d(const std::string &, Vector3f &, Vector3f &, Vector3f &);
      void	addObject2d(const std::string &, Vector3f &, Vector3f &, Vector3f &);
      void	setMenu(const Menu &);
      Menu	getMenu() const;
      Camera *	getCamera();

    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class MyGame;
  }
}

#endif
