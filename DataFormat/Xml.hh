#ifndef	XML_HH__
#define	XML_HH__

#include <list>
#include <string>
#include <utility>
#include "ADataFormat.hh"

enum eBaliseState {
  OPENING,
  CLOSING
};

class Xml : public ADataFormat {
public:
  explicit Xml(std::string const &);
  virtual ~Xml();

  class Balise {
  private:
    std::string			_name;
    eBaliseState		_state;
    Balise *			_parent;
    std::string			_content;
    std::list<Balise *>	_children;
    std::string			_attribute;
    Balise *			_associated;
    std::string			_attributeName;

  public:
    explicit Balise(std::string const &, eBaliseState);
    ~Balise();

    std::string	const &			getName() const;
    eBaliseState				getState() const;
    Balise *					getParent() const;
    std::string const &			getContent() const;
    std::list<Balise *> const &	getChilden() const;
    Balise *					getAssociated() const;

    void			addChild(Balise *);
    void			setParent(Balise *);
    void			setAssociated(Balise *);
    void			setName(std::string const &);
    void			setContent(std::string const &);
    void			setChildren(std::list<Balise *> const &);
  };

  virtual void generate(std::string const &) const;

private:
  std::list<Balise *>		_balises;
};

#endif
