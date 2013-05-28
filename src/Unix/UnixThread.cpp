//
//  UnixThread.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include	<unistd.h>
#include	<signal.h>
#include	"UnixThread.hh"

namespace BomberMan
{
    namespace Unix
    {
        UnixThread::UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id)
        : _id(id)
        {
            pthread_create(&(this->_thread), attr, func, arg);
        }
        
        UnixThread::~UnixThread()
        {
            this->exit();
        }
        
        void                UnixThread::exit()
        {
            int     return_value;
            
            return_value = 0;
            pthread_exit((void *)&return_value);
        }
        
        int                 UnixThread::join()
        {
            return pthread_join(this->_thread, NULL);
        }
        
        int                 UnixThread::detach()
        {
            return pthread_detach(this->_thread);
        }
        
        const pthread_t *   UnixThread::getThread() const
        {
            return &(this->_thread);
        }
    }
}