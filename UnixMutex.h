//
//  UnixMutex.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__UnixMutex__
#define __BomberMan__UnixMutex__

#include        "IMutex.h"

class UnixMutex : public IMutex
{
    pthread_mutex_t       mutex;
    size_t                id;
    
public:
    UnixMutex(size_t);
	~UnixMutex();
    int   lock();
    int   trylock();
    int   unlock();
    pthread_mutex_t * getMutex();
};

#endif /* defined(__BomberMan__UnixMutex__) */