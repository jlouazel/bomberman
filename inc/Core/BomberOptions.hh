//
// BomberOptions.hh for bomberman in /home/fortin_j/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sat Jun  8 13:39:38 2013 julien fortin
// Last update Sun Jun  9 18:52:47 2013 julien fortin
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

      bool			_quickGame;

      unsigned int		_nbPlayer;
      unsigned int		_nbIA;
      unsigned int		_width;
      unsigned int		_height;
      unsigned int		_buffDensity;

    public:
      enum ePlayerSkin { WW, JP, NOSKIN };

    private:
      std::map<unsigned int, ePlayerSkin>	_skins;

    protected:
    public:
      static BomberOptions*	getOptions();
      static void		deleteOptions();

      bool		isQuickGame() const;
      unsigned int	getBuffDensity() const;
      unsigned int	getWidth() const;
      unsigned int	getHeight() const;
      unsigned int	getNbPlayer() const;
      unsigned int	getNbIA() const;
      ePlayerSkin	getSkinForPlayer(unsigned int) const;

      void		init();

      void		setBuffDensity(unsigned int);
      void		setNotQuickGame();
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
