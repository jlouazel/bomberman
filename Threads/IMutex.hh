//
//  IMutex.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_IMutex_h
#define BomberMan_IMutex_h

#include        <pthread.h>

class IMutex
{
public:
    virtual       ~IMutex(){}
    
    virtual int   				lock() = 0;
    virtual int  			 	trylock() = 0;
    virtual int   				unlock() = 0;
    virtual pthread_mutex_t *	getMutex() = 0;
};

#endif
