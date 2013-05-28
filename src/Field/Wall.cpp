//
//  Wall.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Wall.hh"

namespace BomberMan
{
    namespace Field
    {
        Wall::Wall(bool breakable, int pv, float x, float y, BomberMan::Display::IAsset * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
        :   _breakable(breakable), _pv(pv)
        {
            this->_x = x;
            this->_y = y;
            this->_asset = asset;
            this->_sound = sound;
            this->_animation = anim;
        }
        
        Wall::~Wall()
        {
        }
        
        int     Wall::getPv() const
        {
            return this->_pv;
        }
        
        void    Wall::setPv(int pv)
        {
            this->_pv = pv;
        }
        
        void    Wall::explode(int damages, eDirection direction)
        {
            static_cast<void>(direction);
            if (this->_breakable == true)
            {
                this->_pv -= damages;
                // changement d'asset (breches?)
                if (this->_pv < 0)
                {
                    delete this;
                }
            }
        }
    }
}