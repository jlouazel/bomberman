#include <iostream>
#include <string>

#include <algorithm>
#include <utility>

#include "IDataFormat.hh"
#include "eFormat.hh"
#include "Parser.hh"
#include "Error.hh"
#include "Xml.hh"

void	aff(std::pair<int, std::string const &> paire) {
  std::cout << "line " << paire.first << "\t: " << paire.second << std::endl;
}

int	main(int ac, char **av)
{
  try {
    if (ac < 2) {
      std::cerr << "Usage is : ./parser file" << std::endl;
      return -1;
    }
    IDataFormat *f = new Xml(av[1]);
    f->generate("pute.xml");
    delete f;
    return 0;
  }
  catch (Error e) {
      std::cerr << "Error of type \"" << e.getWhat() << "\" in " << e.getWhere() << " (" << e.getDetails() << ")" << std::endl;
    }
}







