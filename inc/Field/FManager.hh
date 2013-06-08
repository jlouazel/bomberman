#ifndef __BOMBERMAN_FIELD_MANAGER__
#define __BOMBERMAN_FIELD_MANAGER__

#include <vector>
#include <iostream>
#include <utility>
#include <list>
#include "IGameComponent.hh"

namespace BomberMan
{
  namespace Field
  {
    class Player;
  }
}

namespace BomberMan
{
  namespace Field
  {
    class Manager
    {
      unsigned int	_width;
      unsigned int	_height;
      unsigned int	_nbCuves;

      std::vector<std::list<IGameComponent *> >	_map;

      Manager(const Manager &);
      Manager &	operator=(const Manager &);

    public:
      Manager();					// Genere une map aleatoire en tout points
      // Manager(unsigned int);				// Genere une map aleatoire en fonction d'un niveau donne
      // Manager(std::string const &);			// Genere une map en fonction d'un seed
      // Manager(unsigned int width, unsigned int height);	// Genere une map aleatoire avec une taille predefinie
      ~Manager();

      unsigned int			getWidth() const;
      unsigned int			getHeight() const;
      std::list<IGameComponent *> &	get(unsigned int, unsigned int);
      void				addComponent(unsigned int, unsigned int, IGameComponent *);
      void				delComponent(unsigned int, unsigned int, IGameComponent *);
      void				setExplosion(unsigned int, unsigned int, int);
      void				randomize(std::list<Player *> const &);
      void				initFrame(int, int, int);
    };
  }
}

#else
namespace BomberMan
{
  namespace Field
  {
    class Manager;
  }
}

#endif
