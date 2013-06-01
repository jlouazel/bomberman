//
// EndOfBomberMan.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 16:28:39 2013 julien fortin
// Last update Sat Jun  1 23:20:21 2013 julien fortin
//

#ifndef __ENDOFBOMBERMAN_HH__
#define __ENDOFBOMBERMAN_HH__

#include <exception>
#include <string>

namespace BomberMan
{
  namespace Core
  {
    class EndOfBomberMan : public std::exception
    {
      std::string	_what;
      std::string	_where;
      std::string	_details;

    public:
      EndOfBomberMan(std::string, std::string, std::string);
      ~EndOfBomberMan() throw();

      std::string	getWhat() const;
      std::string	getWhere() const;
      std::string	getDetails() const;
    };
  }
}
#else
namespace BomberMan
{
  namespace Core
  {
    class EndOfBomberMan;
  }
}
#endif
