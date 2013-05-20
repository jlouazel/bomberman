//
//  UnixThread.h
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__UnixThread__
#define __BomberMan__UnixThread__

#include        "IThread.hh"

class UnixThread : public IThread
{
private:
    pthread_t     thread;
    size_t        id;
    
public:
    UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id);
    ~UnixThread();
    
    void                exit();
    int                 join();
    int                 detach();
    const pthread_t *   getThread() const;
};

#endif /* defined(__BomberMan__UnixThread__) */
