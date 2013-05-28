//
// InputJS.hh for bomberman in /home/fortin_j/tek2/projects/bomberman/bomberman
//
// Made by julien fortin
// Login   <fortin_j@epitech.net>
//
// Started on  Sun May 26 23:41:49 2013 julien fortin
// Last update Mon May 27 00:28:54 2013 julien fortin
//

#ifndef	__INPUTJS_HH__
#define	__INPUTJS_HH__

#include	"EventEnum.hh"
#include	"IInput.hh"

namespace BomberMan
{
  namespace Input
  {
    class InputJS : public IInput
    {
    private:
      Event::EventDirection::eEventDirection	_direction;
      float					_angle;

    protected:
    public:
      virtual ~InputJS();

      InputJS(float, Event::EventDirection::eEventDirection);

      virtual InputType::eInputType		getInputType() const;

      Event::EventDirection::eEventDirection	getDirection() const;
      float					getAngle() const;

      void	setAngle(float);
      void	setDirection(Event::EventDirection::eEventDirection);

      const InputJS*	set(float, Event::EventDirection::eEventDirection);
    };
  }
}

#endif
