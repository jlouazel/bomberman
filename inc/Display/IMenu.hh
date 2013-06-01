//
// IMenu.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 18:40:10 2013 julien fortin
// Last update Sat Jun  1 21:27:53 2013 julien fortin
//

#ifndef	__IMENU_HH__
#define	__IMENU_HH__

namespace BomberMan
{
  namespace Display
  {
    class IMenu
    {
    private:
    protected:
    public:
      virtual ~IMenu() {}

      virtual void	update() = 0;
      virtual void	draw() const = 0;
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class IMenu;
  }
}
#endif
