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
            std::vector <IOnglet *>	_onglet;
            std::string				_stringTextureFond;
            AObject *				_textureFond;
        public:
            Menu(std::string &);
            Menu();
            ~Menu();
        public:
            void			  		addOnglet(IOnglet *);
            IOnglet *				getOneOnglet(int) const;
            std::vector <IOnglet *>	getOnglet() const;
            void					affAllOnglet();
        };
    }
}

#endif
