//
// main.cpp for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  1 01:21:17 2013 julien fortin
// Last update Tue Jun  4 02:46:52 2013 Happy
//

#include	<iostream>
#include	"EndOfBomberMan.hh"
#include	"BomberMan.hh"

int	main()
{
  try
    {
      BomberMan::Core::BomberMan Game;
      // BomberMan::Display::MyGame Game;

      Game.run();
      // BomberMan::Core::BomberMan::getBomberMan()->run();
    }
  catch (...)
    {
      std::cerr << "An `Emma Watson` occured." << std::endl;
    }
}
