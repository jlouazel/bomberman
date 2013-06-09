#include "LoadFile.hh"

namespace BomberMan
{
  namespace Core
  {
    LoadFile::LoadFile()
    {
    }

    LoadFile::~LoadFile()
    {
    }

    void			LoadFile::setSecond(unsigned int second)
    {
      this->_second = second;
    }

    void			LoadFile::setMinute(unsigned int minute)
    {
      this->_minute = minute;
    }

    void			LoadFile::setHour(unsigned int hour)
    {
      this->_hour = hour;
    }

    void			LoadFile::setDay(unsigned int day)
    {
      this->_day = day;
    }

    void			LoadFile::setMonth(unsigned int month)
    {
      this->_month = month;
    }

    void			LoadFile::setYear(unsigned int year)
    {
      this->_year = year;
    }

    void			LoadFile::setNbPlayers(unsigned int players)
    {
      this->_players = players;
    }

    void			LoadFile::setNbIas(unsigned int ias)
    {
      this->_ias = ias;
    }

    void			LoadFile::setWidth(unsigned int width)
    {
      this->_width = width;
    }

    void			LoadFile::setHeight(unsigned int height)
    {
      this->_height = height;
    }

    void			LoadFile::setFileName(std::string const & filename)
    {
      this->_fileName = filename;
    }

    unsigned int		LoadFile::getSecond(void) const
    {
      return this->_second;
    }

    unsigned int		LoadFile::getMinute(void) const
    {
      return this->_minute;
    }

    unsigned int		LoadFile::getHour(void) const
    {
      return this->_hour;
    }

    unsigned int		LoadFile::getDay(void) const
    {
      return this->_day;
    }

    unsigned int		LoadFile::getMonth(void) const
    {
      return this->_month;
    }

    unsigned int		LoadFile::getYear(void) const
    {
      return this->_year;
    }

    unsigned int		LoadFile::getNbPlayers(void) const
    {
      return this->_players;
    }

    unsigned int		LoadFile::getNbIas(void) const
    {
      return this->_ias;
    }

    unsigned int		LoadFile::getWidth(void) const
    {
      return this->_width;
    }

    unsigned int		LoadFile::getHeight(void) const
    {
      return this->_height;
    }

    std::string const &		LoadFile::getFileName() const
    {
      return this->_fileName;
    }
  }
}
