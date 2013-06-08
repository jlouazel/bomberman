//
//  Enums.h
//  BomberMan
//
//  Created by manour_m on 19/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_Enums_h
#define BomberMan_Enums_h

namespace BomberMan
{
    namespace Field
    {
      enum eObjectType	{ BOMB, BUFF };
      enum eBuffType    { NONE, LIFE, SPEED, RANGE, MORE };
      enum eDirection	{ UP, UPRIGHT, RIGHT, DOWNRIGHT, DOWN, DOWNLEFT, LEFT, UPLEFT };
    }
}

#endif
