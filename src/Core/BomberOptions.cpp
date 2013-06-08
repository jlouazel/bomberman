//
// BomberOptions.cpp for bomberman in /home/fortin_j/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  8 13:44:23 2013 julien fortin
// Last update Sat Jun  8 17:20:24 2013 julien fortin
//

#include	"EndOfBomberMan.hh"
#include	"BomberOptions.hh"

namespace BomberMan
{
  namespace Core
  {
    BomberOptions*	BomberOptions::_options = 0;

    BomberOptions*	BomberOptions::getOptions()
    {
      if (!BomberOptions::_options)
	BomberOptions::_options = new BomberOptions;
      if (!BomberOptions::_options)
	throw EndOfBomberMan("BomberOption", "getOption", "NULL pointer");
      return BomberOptions::_options;
    }

    void		BomberOptions::deleteOptions()
    {
      if (BomberOptions::_options)
	delete BomberOptions::_options;
    }

    BomberOptions::BomberOptions()
    {
      this->_nbPlayer = 1;
      this->setSkinForPlayer(1, BomberOptions::WW);
      this->setSkinForPlayer(2, BomberOptions::JP);
    }

    BomberOptions::~BomberOptions()
    {
    }

    unsigned int	BomberOptions::getNbPlayer() const
    {
      return this->_nbPlayer;
    }

    unsigned int	BomberOptions::getNbIA() const
    {
      return this->_nbIA;
    }

    BomberOptions::ePlayerSkin		BomberOptions::getSkinForPlayer(unsigned int id) const
    {
      if (this->_skins.count(id) > 0)
	return this->_skins.at(id);
      return NOSKIN;
    }

    void	BomberOptions::setSkinForPlayer(unsigned int i, ePlayerSkin s)
    {
      this->_skins[i] = s;
    }

    void	BomberOptions::setNbPlayer(unsigned int n)
    {
      this->_nbPlayer = n;
    }

    void	BomberOptions::setNbIA(unsigned int n)
    {
      this->_nbIA = n;
    }
  }
}
