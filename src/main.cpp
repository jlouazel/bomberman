#include	<iostream>
#include	"EndOfBomberMan.hh"
#include	"BomberMan.hh"
#include	"FormatError.hh"
#include	"FieldError.hh"
#include	"DisplayError.hh"

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
  catch (const BomberMan::Display::DisplayError & e)
    {
      std::cerr << e.getWhat() << "-" << e.getWhere() << "-" << e.getDetails() << std::endl;
    }
  catch (const BomberMan::Field::FieldError & e)
    {
      std::cerr << e.getWhat() << "-" << e.getWhere() << "-" << e.getDetails() << std::endl;
    }
  catch (const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
    }
  // catch (...)
  //   {
  //     std::cerr << "An `Emma Watson` occured." << std::endl;
  //   }
}
