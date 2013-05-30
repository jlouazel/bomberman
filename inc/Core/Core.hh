#ifndef BomberMan_Core_h
#define BomberMan_Core_h

#include <list>
#include "CoreError.hh"

namespace BomberMan
{
  namespace Core
  {
    class Core
    {
    private:
      //Field::Manager * _manager;


    public:
      Core();
      ~Core();

      void	update();
    };
  }
}

#endif
