//
//  Resources.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Resources__
#define __BomberMan__Resources__

#include <map>
#include <string>

#include "IAnimation.hh"
#include "IAsset.hh"
#include "IPicture.hh"
#include "ISound.hh"

namespace BomberMan
{
    namespace Display
    {
        class Ressources
        {
            std::map<std::string, IPicture *>	_pictures;
            std::map<std::string, IAsset *>		_assets;
            std::map<std::string, IAnimation *>	_animations;
            std::map<std::string, ISound *>		_sounds;
            
        public:
            Ressources();
            ~Ressources();
            
            IPicture *		getPicture(const std::string &) const;
            IAnimation *	getAnimation(const std::string &) const;
            ISound *		getSound(const std::string &) const;
            IAsset *		getAsset(const std::string &) const;
        };
    }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Resources;
  }
}

#endif /* defined(__BomberMan__Resources__) */
