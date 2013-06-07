#ifndef __BomberMan__Player__
#define __BomberMan__Player__

#include <Clock.hpp>
#include <Color.hpp>
#include <Model.hpp>
#include <math.h>

#include "EventManager.hh"
#include "AEvent.hh"
#include "IEvent.hh"
#include "EventEnum.hh"
#include "Move.hh"
#include "EventError.hh"
#include "AGameComponent.hh"
#include "Object.hh"
#include "Camera.hpp"

namespace BomberMan
{
  namespace Field
  {
    class Player : public AGameComponent
    {
    protected:
      int         _pv;
      float       _speed;
      int         _nb_bomb_max;
      int         _nb_bomb_set;
      Object *    _bomb;
      Display::AObject *   _walking;
      Display::AObject *   _mark;
      Display::AObject *   _run;
      Display::Camera *	  _camera;
      bool	  _isMoving;
      bool        _isRunning;

    public:
      Player(int pv, float speed, int max, int set, float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
      Player(Player *);
      ~Player();

      void        move(float, float, float, Manager *);
      void	  newBomb();
      void	  setBomb(Manager *);
      void        acquireObject();
      void        run(gdl::GameClock const &);
      int         getNbBombMax() const;
      void        setNbBombMax(int);
      int         getNbBombSet() const;
      float       getSpeed() const;
      void        setSpeed(float);
      Object *    getBomb() const;
      void        explode(int, eDirection, Manager *manager);
      int         getPv() const;
      void        setPv(int);
      void	  setCamera(Display::Camera *);
      void	  update(gdl::GameClock const &, Manager *);
      void	  draw(gdl::GameClock const &);
      void	  initialize();
      bool	  checkMyMove(float, float, Manager *);
      bool        operator==(IGameComponent *other);

      void	operator=(Player &);

      bool	  getIsMoving() const;
      bool        getIsRunning() const;
      Display::AObject *  getRun() const;
      Display::AObject *  getMark() const;
      Display::Camera *	  getCamera() const;
      Display::AObject *  getWalking() const;
      Display::AObject *  getAsset() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Player;
  }
}

#endif
