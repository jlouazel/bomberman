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
            static Manager *							_manager;

            unsigned int								_width;
            unsigned int								_height;
            std::vector<std::list<IGameComponent *> >	_map;

            Manager(unsigned int width, unsigned int height);
            Manager(const Manager &);
            Manager &	operator=(const Manager &);
            ~Manager();

        public:
            std::list<IGameComponent *> &	get(unsigned int, unsigned int);
            unsigned int					getWidth() const;
            unsigned int					getHeight() const;
            static Manager *    getInstance();
            static void			initInstance(unsigned int width, unsigned int height);
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
