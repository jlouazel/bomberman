//
// main.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:21:17 2013 julien fortin
// Last update Sun Jun  9 16:23:21 2013 julien fortin
//

#include	<iostream>
#include	"EndOfBomberMan.hh"
#include	"BomberMan.hh"
#include	"FormatError.hh"

int	main(int, char**, char **env)
{
  if (!env)
    return 1;
  try
    {
      BomberMan::Core::BomberMan game;

      game.run();
    }
  catch (const BomberMan::Core::EndOfBomberMan &)
    {
    }
  catch (const BomberMan::DataFormat::FormatError & e)
    {
      std::cerr << e.getWhat() << "-" << e.getWhere() << "-" << e.getDetails() << std::endl;
    }
  catch (...)
    {
      std::cerr << "An `Emma Watson` occured." << std::endl;
    }
}
