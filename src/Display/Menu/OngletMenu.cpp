#include "OngletMenu.hpp"

namespace BomberMan
{
  namespace Display
  {
    OngletMenu::OngletMenu(MenuEnum::eMenu menu, std::string const &name, AObject *image)
      : _menu(menu), _name(name), _image(image)
    {
    }

    MenuEnum::eMenu	OngletMenu::getMenu() const
    {
      return (this->_menu);
    }

    const std::string   &OngletMenu::getName() const
    {
      return (this->_name);
    }

    AObject       *OngletMenu::getImage() const
    {
      return (this->_image);
    }

    void	OngletMenu::setName(std::string const &newName)
    {
      this->_name = newName;
    }

    void    OngletMenu::initialize() const
    {
      this->_image->initialize();
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
