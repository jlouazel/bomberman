#ifndef __BomberMan_Field_Manager__
#define __BomberMan_Field_Manager__

#include <vector>
#include <iostream>
#include <utility>
#include <list>

#include "IGameComponent.hh"
#include "Camera.hpp"

namespace BomberMan
{
    namespace Field
    {
        class Manager
        {
<<<<<<< HEAD
	  unsigned int							_width;
	  unsigned int							_height;
	  std::vector<std::list<IGameComponent *> >				_map;
	  Display::Camera							*_camera;


	  Manager(const Manager &);
	  Manager &	operator=(const Manager &);

=======
            unsigned int	_width;
            unsigned int	_height;
            
            std::vector<std::list<IGameComponent *> >	_map;
                        
            Manager(const Manager &);
            Manager &	operator=(const Manager &);
            
>>>>>>> 90c3fd04f4bb1d55a2fe62dcb4d9d1a2881981c8
        public:
	  Manager(unsigned int width, unsigned int height);
            ~Manager();
            
            std::list<IGameComponent *> &	get(unsigned int, unsigned int);
            unsigned int				       getWidth() const;
            unsigned int					getHeight() const;
        };
    }
}

#else
namespace BomberMan
{
    namespace Field
    {
        class Manager;
    }
}

#endif
