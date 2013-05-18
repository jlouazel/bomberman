//
//  UnixMutex.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "UnixMutex.h"

UnixMutex::UnixMutex(size_t id)
: id(id)
{
    pthread_mutex_init(&(this->mutex), NULL);
}

UnixMutex::~UnixMutex()
{
    pthread_mutex_destroy(&(this->mutex));
}

int                     UnixMutex::lock()
{
    return pthread_mutex_lock(&(this->mutex));
}

int                     UnixMutex::trylock()
{
    return pthread_mutex_trylock(&(this->mutex));
}

int                     UnixMutex::unlock()
{
    return pthread_mutex_unlock(&(this->mutex));
}

pthread_mutex_t *       UnixMutex::getMutex()
{
    return &this->mutex;
}