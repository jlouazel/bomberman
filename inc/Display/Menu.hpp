#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <vector>
#include "AObject.hpp"
#include "IOnglet.hpp"

namespace BomberMan
{
    namespace Display
    {
        class	Menu
        {
        private:
            std::vector <BomberMan::Display::IOnglet *>	_onglet;
        public:
            Menu();
            ~Menu();
        public:
            void			  addOnglet(BomberMan::Display::IOnglet *);
            BomberMan::Display::IOnglet		  *getOneOnglet(int) const;
            ::std::vector <BomberMan::Display::IOnglet *> getOnglet() const;
            void			  affAllOnglet();
        };
    }
}

#endif
