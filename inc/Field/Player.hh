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
      int	  _id;
      int         _pv;
      float       _speed;
      float	  _realSpeed;
      int         _nb_bomb_max;
      int         _nb_bomb_set;
      int	  _power;
      Object *    _bomb;
      std::list<gdl::Clock *>   _clock;
      Display::AObject *   _walking;
      Display::AObject *   _mark;
      Display::AObject *   _run;
      Display::AObject *   _dead;
      Display::AObject *   _dying;
      Display::Camera *	  _camera;
      bool	  _isMoving;
      bool        _isRunning;
      int         _nbCaisseDestroyed;
      int         _nbPlayerKilled;
      int	  _nbBuffTaked;
      bool	  _moveOk;

    public:
      Player(int id, int pv, float speed, int max, int set, float x, float y, Display::AObject * asset, Display::ISound * sound, Display::IAnimation * anim);
      Player(Player *);
      ~Player();

      void        move(float, float, float, Manager *);
      void	  newBomb();
      void	  setBomb(Manager *);
      void        run(gdl::GameClock const &);
      int         getNbBombMax() const;
      void        setNbBombMax(int);
      int         getNbBombSet() const;
      float       getSpeed() const;
      float       getRealSpeed() const;
      void        setSpeed(float);
      Object *    getBomb() const;
      void        explode(int, Manager *, int);
      int         getPv() const;
      int	  getPower() const;
      void        setPv(int);
      void	  setCamera(Display::Camera *);
      void	  update(gdl::GameClock const &, Manager *);
      void	  draw(gdl::GameClock const &);
      void	  initialize();
      bool	  checkMyMove(float, float, Manager *);
      bool        operator==(IGameComponent *other);
      void	  checkBuff(Manager *);
      void	  operator=(Player &);
      void	  imDyingDraw();
      bool	  getIsMoving() const;
      bool        getIsRunning() const;
      void	  setIsMoving(bool);
      void        setIsRunning(bool);
      Display::AObject *  getRun() const;
      Display::AObject *  getMark() const;
      Display::Camera *	  getCamera() const;
      Display::AObject *  getWalking() const;
      Display::AObject *  getAsset() const;
      int		  getNbBuffTaked() const;
      int		  getNbPlayerKilled() const;
      int		  getNbCaisseDestroyed() const;
      void		  setNbBuffTaked(int);
      void		  setNbPlayerKilled(int);
      void		  setNbCaisseDestroyed(int);
      int		  getId() const;
      void		  setMoveOk(bool);
      bool		  getMoveOk() const;
      void		  updateCamera(gdl::GameClock const & gameClock);
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
