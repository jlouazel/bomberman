#ifndef __ONGLETMENU_HPP__
#define __ONGLETMENU_HPP__

#include	<string>
#include	"AObject.hpp"
#include	"IMenu.hh"
#include	"IOnglet.hpp"

namespace BomberMan
{
  namespace Display
  {
    class	OngletMenu : public IOnglet
    {
    private:
      MenuEnum::eMenu	_menu;
      std::string	_name;
      AObject	*	_image;

    private:
      OngletMenu();

    public:
      OngletMenu(MenuEnum::eMenu, std::string const&,  AObject *);

    public:
      MenuEnum::eMenu		getMenu() const;
      const std::string	&getName() const;
      void		setName(std::string const &);
      void		affOnglet() const;
      void		initialize() const;
      AObject *	getImage() const;
      void		setPosition(Vector3f &);
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class OngletMenu;
  }
}
#endif
