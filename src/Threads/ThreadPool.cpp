//
//  ThreadPool.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "ThreadPool.hh"
#include "UnixThread.hh"

ThreadPool::ThreadPool()
{
}

ThreadPool::~ThreadPool()
{
}

void	ThreadPool::addThread()
{
    this->_count++;
}

size_t	ThreadPool::getNbThread() const
{
    return this->_count;
}
