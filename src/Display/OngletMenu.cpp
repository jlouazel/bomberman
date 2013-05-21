#include "Menu.hpp"
#include "OngletMenu.hpp"

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

void	OngletMenu::setName(std::string newName)
{
  this->_name = newName;
}

void	OngletMenu::affOnglet() const
{
  this->_image->draw();
}
