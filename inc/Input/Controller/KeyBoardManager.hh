//
// KeyBoardManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:23:08 2013 julien fortin
// Last update Tue Jun  4 19:19:28 2013 julien fortin
//

#ifndef	__KEYBOARDMANAGER_HH__
#define	__KEYBOARDMANAGER_HH__

#include	<list>
#include	<map>
#include	<utility>
#include	<Input.hpp>
#include	"Player.hh"

namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      class KeyBoardManager
      {
      private:
	KeyBoardManager(KeyBoardManager const&);
	KeyBoardManager	&operator=(KeyBoardManager const&);

      private:
	static KeyBoardManager *	_keyboardManager;

	std::list<std::pair<gdl::Keys::Key, gdl::Keys::Key> >	_mappingP1;
	std::list<std::pair<gdl::Keys::Key, gdl::Keys::Key> >	_mappingP2;

	std::map<gdl::Keys::Key, void (KeyBoardManager::*)(const Field::Player* const) const>	_keys;

      private:
	void	_up(const Field::Player* const) const;
	void	_upLeft(const Field::Player* const) const;
	void	_upRight(const Field::Player* const) const;

	void	_left(const Field::Player* const) const;
	void	_right(const Field::Player* const) const;

	void	_down(const Field::Player* const) const;
	void	_downLeft(const Field::Player* const) const;
	void	_downRight(const Field::Player* const) const;

	void	_action(const Field::Player* const) const;

      private:
	void	_treatInputForPlayer(gdl::Input&,
				     const std::list<std::pair<gdl::Keys::Key, gdl::Keys::Key> >&);

      public:
	~KeyBoardManager();
	KeyBoardManager();

	void			initMapping(bool);
	void			treatInput(gdl::Input&);

	static KeyBoardManager*	getKeyBoardManager();
	static void		deleteKeyBoardManager();

      };
    }
  }
}

#else
namespace BomberMan
{
  namespace Input
  {
    namespace Controller
    {
      class KeyBoardManager;
    }
  }
}

#endif
