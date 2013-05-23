#ifndef __IONGLET_HPP__
#define __IONGLET_HPP__

namespace BomberMan
{
    namespace Display
    {
        class	IOnglet
        {
        public:
            virtual ~IOnglet() {};
            virtual void affOnglet() const = 0;
	    virtual void initialize() const = 0;
        };
    }
}

#endif
