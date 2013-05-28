//
//  Empty.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Empty__
#define __BomberMan__Empty__

#include "AGameComponent.hh"

#include "IAsset.hh"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
    namespace Field
    {
        class Empty : public AGameComponent
        {
        public:
            Empty(float x, float y, Display::IAsset * asset, Display::ISound * sound, Display::IAnimation * anim);
            ~Empty();
            
            void	explode(int, eDirection);
        };
    }
}

#endif /* defined(__BomberMan__Empty__) */
