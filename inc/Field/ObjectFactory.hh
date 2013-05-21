//
//  ObjectFactory.h
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__ObjectFactory__
#define __BomberMan__ObjectFactory__

#include <map>
#include <utility>

#include "Object.hh"
#include "Enums.hh"

namespace BomberMan
{
    namespace Field
    {
        class ObjectFactory
        {
            ::std::map< ::std::pair<BomberMan::Field::eObjectType, BomberMan::Field::eBuffType>, BomberMan::Field::Object *>   _objects;
            
        public:
            ObjectFactory();
            ~ObjectFactory();
            
            void        learn(::std::pair<BomberMan::Field::eObjectType, BomberMan::Field::eBuffType>, Object *);
            Object *    create(::std::pair<BomberMan::Field::eObjectType, BomberMan::Field::eBuffType>) const;
        };
    }
}

#endif /* defined(__BomberMan__ObjectFactory__) */
