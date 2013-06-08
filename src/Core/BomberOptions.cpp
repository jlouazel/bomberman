//
// BomberOptions.cpp for bomberman in /home/fortin_j/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  8 13:44:23 2013 julien fortin
// Last update Sat Jun  8 13:49:19 2013 julien fortin
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
    }

    BomberOptions::~BomberOptions()
    {
    }
  }
}
