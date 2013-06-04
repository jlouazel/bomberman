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
    class Manager
    {
      unsigned int	_width;
      unsigned int	_height;

      std::vector<std::list<IGameComponent *> >	_map;

      Manager(const Manager &);
      Manager &	operator=(const Manager &);

    public:
      Manager();					// Genere une map aleatoire en tout points
      // Manager(unsigned int);				// Genere une map aleatoire en fonction d'un niveau donne
      // Manager(std::string const &);			// Genere une map en fonction d'un seed
      // Manager(unsigned int width, unsigned int height);	// Genere une map aleatoire avec une taille predefinie
      ~Manager();

      std::list<IGameComponent *> &	get(unsigned int, unsigned int);
      unsigned int				       getWidth() const;
      unsigned int					getHeight() const;
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
