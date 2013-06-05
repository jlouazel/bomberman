//
// KeyBoardManager.hh for bomberman in /home/fortin_j/tek2/projects/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Tue May 21 20:23:08 2013 julien fortin
// Last update Wed Jun  5 13:56:33 2013 julien fortin
//

#ifndef	__KEYBOARDMANAGER_HH__
#define	__KEYBOARDMANAGER_HH__

#include	<list>
#include	<map>
#include	<utility>
#include	<Input.hpp>
#include	"Player.hh"
#include	"EventEnum.hh"

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

	bool				_qwerty;
	bool				_multiples;
	std::list<gdl::Keys::Key>	_mappingP1;
	std::list<gdl::Keys::Key>	_mappingP2;

	std::map<gdl::Keys::Key, void (KeyBoardManager::*)(const Field::Player* const)>	_keys;
	std::map<const Field::Player* const, gdl::Keys::Key>	_run;

	gdl::Input*	_input;

      private:
	void	_up(const Field::Player* const);

	bool	_upLeft(const Field::Player* const);
	bool	_upRight(const Field::Player* const);

	void	_left(const Field::Player* const);
	void	_right(const Field::Player* const);

	void	_down(const Field::Player* const);
	bool	_downLeft(const Field::Player* const);
	bool	_downRight(const Field::Player* const);

	void	_action(const Field::Player* const);

	bool	_activeSpeed(const Field::Player* const);

      private:
	void	_treatInputForPlayer(gdl::Input&,
				     const std::list<gdl::Keys::Key>&);

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
