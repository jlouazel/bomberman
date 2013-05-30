#ifndef __BomberMan__Player__
#define __BomberMan__Player__

#include "AGameComponent.hh"
#include "Object.hh"

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

        public:
            Player(int pv, float speed, int max, int set, float x, float y, Display::IAsset * asset, Display::ISound * sound, Display::IAnimation * anim);
            ~Player();

            void        move();
            void    	setBomb();
            void        acquireObject();
            void        run();
            int         getNbBombMax() const;
            void        setNbBombMax(int);
            int         getNbBombSet() const;
            float       getSpeed() const;
            void        setSpeed(float);
            Object *    getBomb() const;
            void        explode(int, eDirection);
            int         getPv() const;
            void        setPv(int);
        };
    }
}

#endif
