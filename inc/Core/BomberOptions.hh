//
// BomberOptions.hh for bomberman in /home/fortin_j/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  8 13:39:38 2013 julien fortin
// Last update Sat Jun  8 19:53:44 2013 julien fortin
//

#ifndef	__BOMBEROPTIONS_HH__
#define	__BOMBEROPTIONS_HH__

#include	<map>

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

      unsigned int		_nbPlayer;
      unsigned int		_nbIA;
      unsigned int		_width;
      unsigned int		_height;

    public:
      enum ePlayerSkin { WW, JP, NOSKIN };

    private:
      std::map<unsigned int, ePlayerSkin>	_skins;

    protected:
    public:
      static BomberOptions*	getOptions();
      static void		deleteOptions();

      unsigned int	getWidth() const;
      unsigned int	getHeight() const;
      unsigned int	getNbPlayer() const;
      unsigned int	getNbIA() const;
      ePlayerSkin	getSkinForPlayer(unsigned int) const;

      void		setWidth(unsigned int);
      void		setHeight(unsigned int);
      void		setSkinForPlayer(unsigned int, ePlayerSkin);
      void		setNbIA(unsigned int);
      void		setNbPlayer(unsigned int);
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