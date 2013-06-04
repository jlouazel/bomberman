//
// EndOfBomberMan.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 16:33:41 2013 julien fortin
// Last update Sat Jun  1 23:35:23 2013 julien fortin
//

#include "EndOfBomberMan.hh"

namespace BomberMan
{
  namespace Core
  {
    EndOfBomberMan::EndOfBomberMan(std::string what, std::string where, std::string details)
      :   _what(what), _where(where), _details(details)
    {
    }

    EndOfBomberMan::~EndOfBomberMan() throw()
    {
    }

    std::string	EndOfBomberMan::getWhat() const
    {
      return this->_what;
    }

    std::string	EndOfBomberMan::getWhere() const
    {
      return this->_where;
    }

    std::string	EndOfBomberMan::getDetails() const
    {
      return this->_details;
    }
  }
}
