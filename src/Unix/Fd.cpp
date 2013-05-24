//
// Fd.cpp for bmberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat May 18 17:32:09 2013 julien fortin
// Last update Thu May 23 16:03:15 2013 julien fortin
//

#include	<unistd.h>
#include	"Fd.hh"

#include <unistd.h>

namespace BomberMan
{
  namespace Unix
  {
    Fd::Fd(std::string const &path, int flag, mode_t mode)
    {
      this->_fd = open(path.c_str(), flag, mode);
      write(1, "new fd\n", 7);
    }

    Fd::Fd(int fd)
    {
      this->_fd = fd;
    }

    Fd::~Fd()
    {
      this->closeFd();
    }

    int	Fd::getFd() const
    {
      return this->_fd;
    }

    void	Fd::closeFd() const
    {
      close(this->_fd);
    }
  }
}
