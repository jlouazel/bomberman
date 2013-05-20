//
//  IThread.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef BomberMan_IThread_h
#define BomberMan_IThread_h

#include        <pthread.h>

class IThread
{
public:
  virtual       ~IThread(){}
    
  virtual void                exit() = 0;
  virtual int                 join() = 0;
  virtual int                 detach() = 0;
  virtual const pthread_t *   getThread() const = 0;
  virtual boolgetStatus() const = 0;
};

#endif
