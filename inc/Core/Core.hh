//
//  Core.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_Core_h
#define BomberMan_Core_h

#include "CoreError.hh"

namespace BomberMan
{
  namespace Core
  {
    class Core
    {
    private:
      Core(Core const&);
      Core        &operator=(Core const&);

      int	_run();

    protected:
    public:
      ~Core();
      Core();

      int run();
    };
  }
}

#endif
