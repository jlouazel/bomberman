//
//  ASound.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__ASound__
#define __BomberMan__ASound__

#include "ISound.hh"

namespace BomberMan
{
    namespace Display
    {
        class ASound : public ISound
        {
        public:
            
        };
    }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class ASound;
  }
}

#endif /* defined(__BomberMan__ASound__) */
