//
//  Object.h
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Object__
#define __BomberMan__Object__

#include "AGameComponent.hh"

#include "Enums.hh"
#include "IAsset.hh"
#include "IAnimation.hh"
#include "ISound.hh"

namespace BomberMan
{
    namespace Field
    {
        class Object : public AGameComponent
        {
            eObjectType		_object_type;
            eBuffType		_buff_type;
            int             _power;
            int             _timer;
            
        public:
            Object(eObjectType, eBuffType, int, int);
            Object(const Object &);
            ~Object();
            
            eObjectType getObjectType() const;
            eBuffType   getBuffType() const;
            int         getPower() const;
            void        setPower(int);
            int         getTimer() const;
            void        explode(int, eDirection);
        };
    }
}

#endif /* defined(__BomberMan__Object__) */
