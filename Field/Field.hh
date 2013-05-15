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
    enum eObjectType	{ BOMB, BUFF };
    enum eBuffType		{ LIFE, SPEED, RANGE };
    
#include <list>
#include <vector>
    
#include "Human.h"
#include "IA.h"
#include "Wall.h"
#include "Bomb.h"
#include "Buff.h"
#include "Empty.h"

class   Field
    {
        std::vector<std::vector<std::list<IGameComponent *> > >	_map;
        
    public:
        Field();
        ~Field();
        
        std::list<IGameComponent *>	&	getGameComponent(int x, int y) const;
    }
}

#endif
