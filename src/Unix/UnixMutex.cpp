//
//  UnixMutex.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "UnixMutex.hh"

BomberMan::Unix::UnixMutex::UnixMutex(size_t id)
  : _id(id)
{
  pthread_mutex_init(&(this->_mutex), NULL);
}

BomberMan::Unix::UnixMutex::~UnixMutex()
{
  pthread_mutex_destroy(&(this->_mutex));
}

int                     BomberMan::Unix::UnixMutex::lock()
{
  return pthread_mutex_lock(&(this->_mutex));
}

int                     BomberMan::Unix::UnixMutex::trylock()
{
  return pthread_mutex_trylock(&(this->_mutex));
}

int                     BomberMan::Unix::UnixMutex::unlock()
{
  return pthread_mutex_unlock(&(this->_mutex));
}

pthread_mutex_t *       BomberMan::Unix::UnixMutex::getMutex()
{
  return &this->_mutex;
}
