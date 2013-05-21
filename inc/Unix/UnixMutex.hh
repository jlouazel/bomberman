//
//  UnixMutex.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__UnixMutex__
#define __BomberMan__UnixMutex__

#include        "IMutex.hh"

class UnixMutex : public IMutex
{
  pthread_mutex_t_mutex;
  size_t          _id;
    
public:
  UnixMutex(size_t);
  ~UnixMutex();
    
  int   lock();
  int   trylock();
  int   unlock();
  pthread_mutex_t *getMutex();
};

#endif /* defined(__BomberMan__UnixMutex__) */