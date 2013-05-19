//
//  Player.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Player__
#define __BomberMan__Player__

#include "AGameComponent.h"
#include "Object.h"

class Player : public AGameComponent
{
protected:
    int         _pv;
    float       _speed;
    int         _nb_bomb_max;
    int         _nb_bomb_set;
    Object &    _bomb;
    
public:
    Player();
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
    Object &    getBomb() const;
    void        explode(int, Field::eDirection);
    int         getPv() const;
    void        setPv(int);
};

#endif /* defined(__BomberMan__Player__) */
