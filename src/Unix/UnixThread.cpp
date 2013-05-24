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

BomberMan::Unix::UnixThread::UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id)
  : _id(id)
{
  pthread_create(&(this->_thread), attr, func, arg);
}

BomberMan::Unix::UnixThread::~UnixThread()
{
  this->exit();
}

void                    BomberMan::Unix::UnixThread::exit()
{
  int     return_value;

  return_value = 0;
  pthread_exit((void *)&return_value);
}

int                     BomberMan::Unix::UnixThread::join()
{
  return pthread_join(this->_thread, NULL);
}

int                     BomberMan::Unix::UnixThread::detach()
{
  return pthread_detach(this->_thread);
}

const pthread_t *       BomberMan::Unix::UnixThread::getThread() const
{
  return &(this->_thread);
}
