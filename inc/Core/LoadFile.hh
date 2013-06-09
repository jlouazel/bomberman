#ifndef	__LOADFILE_HH__
#define	__LOADFILE_HH__

#include <string>

#include "Player.hh"

namespace BomberMan
{
  namespace Core
  {
    class LoadFile
    {
    private:
      unsigned int	_second;
      unsigned int	_minute;
      unsigned int	_hour;
      unsigned int	_day;
      unsigned int	_month;
      unsigned int	_year;

      unsigned int	_players;
      unsigned int	_ias;

      unsigned int	_width;
      unsigned int	_height;

      std::string	_fileName;
    public:
      LoadFile();
      ~LoadFile();

      void			setSecond(unsigned int);
      void			setMinute(unsigned int);
      void			setHour(unsigned int);
      void			setDay(unsigned int);
      void			setMonth(unsigned int);
      void			setYear(unsigned int);
      void			setNbPlayers(unsigned int);
      void			setNbIas(unsigned int);
      void			setWidth(unsigned int);
      void			setHeight(unsigned int);
      void			setFileName(std::string const &);

      unsigned int		getSecond(void) const;
      unsigned int		getMinute(void) const;
      unsigned int		getHour(void) const;
      unsigned int		getDay(void) const;
      unsigned int		getMonth(void) const;
      unsigned int		getYear(void) const;
      unsigned int		getNbPlayers(void) const;
      unsigned int		getNbIas(void) const;
      unsigned int		getWidth(void) const;
      unsigned int		getHeight(void) const;
      std::string const &	getFileName() const;
    };
  }
}

#else
namespace BomberMan
{
  namespace Core
  {
    class LoadFile;
  }
}

#endif
