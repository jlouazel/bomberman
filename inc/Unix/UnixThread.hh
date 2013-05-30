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

namespace BomberMan
{
    namespace Unix
    {
        class UnixThread : public IThread
        {
        private:
            pthread_t	_thread;
            size_t		_id;
            
        public:
            UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id);
            ~UnixThread();
            
            void	exit();
            int		join();
            int		detach();
            
            const pthread_t *   getThread() const;
        };
    }
}

#else
namespace BomberMan
{
  namespace Unix
  {
    class UnixThread;
  }
}

#endif /* defined(__BomberMan__UnixThread__) */
