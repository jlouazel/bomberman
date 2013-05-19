#ifndef	__ERROR_HH__
#define __ERROR_HH__

class Error : public std::exception
{
private:
  std::string  	_what;
  std::string 	_where;
  std::string 	_details;

public:

  Error(std::string const &, std::string const &, std::string const &);
  ~Error() throw();

  std::string const & getWhat() const;
  std::string const & getWhere() const;
  std::string const & getDetails() const;
};

#endif
