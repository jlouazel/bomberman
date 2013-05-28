//
//  Resources.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Resources.hh"

namespace BomberMan
{
    namespace Display
    {
        Ressources::Ressources()
        {
        }
        
        Ressources::~Ressources()
        {
        }
        
        IPicture *		Ressources::getPicture(const std::string & name) const
        {
            static_cast<void>(name);
            return 0;
        }
        
        IAnimation *	Ressources::getAnimation(const std::string & name) const
        {
            static_cast<void>(name);
            return 0;
        }
        
        ISound *		Ressources::getSound(const std::string & name) const
        {
            static_cast<void>(name);
            return 0;
        }
        
        IAsset *		Ressources::getAsset(const std::string & name) const
        {
            static_cast<void>(name);
            return 0;
        }
    }
}