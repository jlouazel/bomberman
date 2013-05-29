#include "Menu.hpp"
#include "OngletMenu.hpp"

namespace BomberMan
{
    namespace Display
    {
        OngletMenu::OngletMenu(Menu *menu, std::string name, AObject *image)
        : _menu(menu), _name(name), _image(image)
        {
        }
        
        Menu	*OngletMenu::getContain() const
        {
            return (this->_menu);
        }
        
        void	OngletMenu::setContain(Menu *newMenu)
        {
            this->_menu = newMenu;
        }
        
        std::string   OngletMenu::getName() const
        {
            return (this->_name);
        }
        
        AObject       *OngletMenu::getImage() const
        {
            return (this->_image);
        }
        
        void	OngletMenu::setName(std::string newName)
        {
            this->_name = newName;
        }
        
        void    OngletMenu::initialize() const
        {
	  this->_image->initialize();
	  this->_menu->initialize();
        }
        
      void	OngletMenu::affOnglet() const
        {
	  this->_image->draw();
        }
        
        void    OngletMenu::setPosition(Vector3f &position)
        {
            this->_image->setPosition(position);
        }
    }
}
