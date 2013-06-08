//
// main.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:21:17 2013 julien fortin
// Last update Sat Jun  8 15:40:04 2013 julien fortin
//

#include	<iostream>
#include	"EndOfBomberMan.hh"
#include	"BomberMan.hh"

int	main()
{
  try
    {
      BomberMan::Core::BomberMan game;

      game.run();
    }
  catch (const BomberMan::Core::EndOfBomberMan &)
    {
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  catch (...)
    {
      std::cerr << "An `Emma Watson` occured." << std::endl;
    }
}
