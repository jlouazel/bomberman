//
//  UnixMutex.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "UnixMutex.hh"

namespace BomberMan
{
    namespace Unix
    {
        UnixMutex::UnixMutex(size_t id)
        : _id(id)
        {
            pthread_mutex_init(&(this->_mutex), NULL);
        }
        
        UnixMutex::~UnixMutex()
        {
            pthread_mutex_destroy(&(this->_mutex));
        }
        
        int                 UnixMutex::lock()
        {
            return pthread_mutex_lock(&(this->_mutex));
        }
        
        int                 UnixMutex::trylock()
        {
            return pthread_mutex_trylock(&(this->_mutex));
        }
        
        int                 UnixMutex::unlock()
        {
            return pthread_mutex_unlock(&(this->_mutex));
        }
        
        pthread_mutex_t *   UnixMutex::getMutex()
        {
            return &this->_mutex;
        }
    }
}