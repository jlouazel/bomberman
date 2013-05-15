//
//  Field.h
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#ifndef BomberMan_Field_h
#define BomberMan_Field_h

namespace Field
{
#include "Human.h"
#include "IA.h"
#include "Wall.h"
#include "Bomb.h"
#include "Buff.h"
#include "Empty.h"

class   Field
    {
        std::array<std::array<std::list<IGameComponent *> > >	_map;
        
    public:
        std::list<IGameComponent *>	&	getGameComponent(int x, int y) const;
    }
}

#endif
