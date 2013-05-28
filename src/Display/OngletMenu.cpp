#include "Menu.hpp"
#include "OngletMenu.hpp"

BomberMan::Display::OngletMenu::OngletMenu(BomberMan::Display::Menu *menu, ::std::string name, BomberMan::Display::AObject *image)
  : _menu(menu), _name(name), _image(image)
{
}

BomberMan::Display::Menu	*BomberMan::Display::OngletMenu::getContain() const
{
  return (this->_menu);
}

void	BomberMan::Display::OngletMenu::setContain(BomberMan::Display::Menu *newMenu)
{
  this->_menu = newMenu;
}

::std::string   BomberMan::Display::OngletMenu::getName() const
{
  return (this->_name);
}

BomberMan::Display::AObject       *BomberMan::Display::OngletMenu::getImage() const
{
  return (this->_image);
}

void	BomberMan::Display::OngletMenu::setName(::std::string newName)
{
  this->_name = newName;
}

void    BomberMan::Display::OngletMenu::initialize() const
{
  this->_image->initialize();
}

void	BomberMan::Display::OngletMenu::affOnglet() const
{
  this->_image->draw();
}

void    BomberMan::Display::OngletMenu::setPosition(Vector3f &position)
{
  this->_image->setPosition(position);
}
