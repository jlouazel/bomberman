//
//  Resources.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Resources__
#define __BomberMan__Resources__

#include	<map>
#include	<string>
#include	<Image.hpp>

#include "AObject.hpp"
#include "ISound.hh"

namespace BomberMan
{
  namespace Display
  {
    class Resources
    {
    private:
      Resources();
      ~Resources();
      Resources(Resources const&);
      Resources	&operator=(Resources const&);

    private:
      static Resources*	_ressources;

      std::map<std::string, gdl::Image>	_images;

      std::map<std::string, AObject *>		_assets;
      std::map<std::string, ISound *>		_sounds;

    public:
      const gdl::Image*	getImage(const std::string&);


      ISound*		getSound(const std::string &);
      AObject*		getAsset(const std::string &);

      static Resources*	getResources();
      static void	deleteResources();
    };
  }
}

#else
namespace BomberMan
{
  namespace Display
  {
    class Resources;
  }
}
#endif /* defined(__BomberMan__Resources__) */
