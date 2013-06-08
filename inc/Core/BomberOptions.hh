//
// BomberOptions.hh for bomberman in /home/fortin_j/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  8 13:39:38 2013 julien fortin
// Last update Sat Jun  8 13:47:18 2013 julien fortin
//

#ifndef	__BOMBEROPTIONS_HH__
#define	__BOMBEROPTIONS_HH__

namespace BomberMan
{
  namespace Core
  {
    class BomberOptions
    {
    private:
      ~BomberOptions();
      BomberOptions();
      BomberOptions(BomberOptions const&);
      BomberOptions	&operator=(BomberOptions const&);

    private:
      static BomberOptions*	_options;

    protected:
    public:
      static BomberOptions*	getOptions();
      static void		deleteOptions();
    };
  }
}

#else
namespace BomberMan
{
  namespace Core
  {
    class BomberOptions;
  }
}
#endif
