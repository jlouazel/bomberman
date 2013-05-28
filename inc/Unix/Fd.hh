//
// Fd.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat May 18 17:12:50 2013 julien fortin
// Last update Thu May 23 13:08:30 2013 julien fortin
//

#ifndef	__FD_HH__
#define	__FD_HH__

#include	<string>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>

namespace BomberMan
{
  namespace Unix
  {
    class Fd
    {
    private:
      int	_fd;

    private:
      Fd();
      Fd &	operator=(Fd const&);

    protected:
    public:
      ~Fd();
      Fd(int);
      Fd(std::string const&, int, mode_t = 0);

      int	getFd() const;
      void	closeFd() const;
    };
  }
}

#endif
