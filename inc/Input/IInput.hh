//
// IInput.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 26 23:37:40 2013 julien fortin
// Last update Mon May 27 00:10:02 2013 julien fortin
//

#ifndef	__IINPUT_HH__
#define	__IINPUT_HH__

namespace BomberMan
{
  namespace Input
  {
    struct InputType
    {
      enum eInputType { JS, KB };
    };

    class IInput
    {
    private:
    protected:
    public:
      virtual ~IInput() {}

      virtual InputType::eInputType	getInputType() const = 0;
    };
  }
}

#endif
