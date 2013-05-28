//
//  Empty.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Empty.hh"
#include "FManager.hh"

namespace BomberMan
{
    namespace Field
    {
        Empty::Empty(float x, float y, BomberMan::Display::IAsset * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
        {
            this->_x = x;
            this->_y = y;
            this->_asset = asset;
            this->_sound = sound;
            this->_animation = anim;
        }
        
        Empty::~Empty()
        {
        }
        
        void    Empty::explode(int damages, eDirection direction)
        {
            Manager *	field;
            int	x;
            int	y;
            
            x = static_cast<int>(this->_x);
            y = static_cast<int>(this->_y);
            // recup item list en map[x][y]
            // si items > 0
            // traitement specifique
            
            // si 0 items
            damages--;
            // propagation
        }
    }
}