//
//  ThreadPool.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__ThreadPool__
#define __BomberMan__ThreadPool__

#include <list>
#include <sys/types.h>

#include "IThread.hh"

namespace BomberMan
{
    namespace Unix
    {
        class ThreadPool
        {
            std::list<IThread *>	_threads;
            size_t  				_count;
            
        public:
            ThreadPool();
            ~ThreadPool();
            
            void	addThread();
            size_t	getNbThread() const;
        };
    }
}

#endif /* defined(__BomberMan__ThreadPool__) */
