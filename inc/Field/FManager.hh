#ifndef __BomberMan_Field_Manager__
#define __BomberMan_Field_Manager__

#include <vector>
#include <iostream>
#include <utility>
#include <list>

#include "IGameComponent.hh"

namespace BomberMan
{
    namespace Field
    {
        class Manager
        {
            unsigned int	_width;
            unsigned int	_height;

            std::vector<std::list<IGameComponent *> >	_map;

            Manager(const Manager &);
            Manager &	operator=(const Manager &);

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
