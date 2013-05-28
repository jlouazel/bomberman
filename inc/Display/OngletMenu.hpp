#ifndef __ONGLETMENU_HPP__
#define __ONGLETMENU_HPP__

#include <string>
#include "AObject.hpp"
#include "Menu.hpp"
#include "IOnglet.hpp"

namespace BomberMan
{
    namespace Display
    {
        class	OngletMenu : public IOnglet
        {
        private:
            Menu *		_menu;
            std::string	_name;
            AObject	*	_image;
            
        private:
            OngletMenu();
        
        public:
            OngletMenu(Menu *menu, std::string,  AObject *);

        public:
            Menu *		getContain() const;
            std::string	getName() const;
            void		setContain(Menu *newMenu);
            void		setName(std::string newName);
            void		affOnglet() const;
            void		initialize() const;
            AObject *	getImage() const;
            void		setPosition(Vector3f &);
        };
    }
}

#endif
