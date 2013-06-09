#ifndef XML_HH__
#define XML_HH__

#include <list>
#include <string>
#include <utility>
#include "ADataFormat.hh"

namespace BomberMan
{
  namespace DataFormat
  {
    enum eBaliseState {
      OPENING,
      CLOSING
    };

    typedef std::list<std::pair <std::string const, std::string const> > attr;

    class Xml : public ADataFormat {
    public:
      Xml();
      Xml(std::string const &);
      virtual ~Xml();

      class Balise {
      private:
	std::string _name;
	eBaliseState _state;
	Balise *_parent;
	std::string _content;
	std::list<Balise *> _children;
	Balise * _associated;
	attr  _attributes;

      public:
	Balise(std::string const &, eBaliseState);
	~Balise();

	std::string const & getName() const;
	eBaliseState getState() const;
	Balise *getParent() const;
	std::string const &getContent() const;
	std::list<Balise *> const &getChilden() const;
	Balise *getAssociated() const;
	attr const & getAttributes() const;

	void addChild(Balise *);
	void setParent(Balise *);
	void setAssociated(Balise *);
	void setAttributes(attr const &);
	void addAttribute(std::pair<std::string, std::string>);
	void setName(std::string const &);
	void setContent(std::string const &);
	void setChildren(std::list<Balise *> const &);
      };

      void		addBalises(std::list<Balise *> &);
      virtual void	generate(std::string const &) const;

    private:
      std::list<Balise *> _balises;
    };
  }
}

#endif
