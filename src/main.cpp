//
// main.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:21:17 2013 julien fortin
// Last update Sat Jun  1 16:34:19 2013 julien fortin
//

#include	<iostream>
#include	"EndOfBomberMan.hh"
#include	"BomberMan.hh"

int	main()
{
  try
    {
      BomberMan::BomberMan::getBomberMan()->run();
    }
  catch (...)
    {
      std::cerr << "Ema Watson occured." << std::endl;
    }
}
