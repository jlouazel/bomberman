//
//  Resources.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Resources.hh"

BomberMan::Display::Ressources::Ressources()
{
}

BomberMan::Display::Ressources::~Ressources()
{
}

BomberMan::Display::IPicture *		BomberMan::Display::Ressources::getPicture(const ::std::string & name) const
{
  static_cast<void>(name);
  return 0;
}

BomberMan::Display::IAnimation *	BomberMan::Display::Ressources::getAnimation(const ::std::string & name) const
{
  static_cast<void>(name);
  return 0;
}

BomberMan::Display::ISound *		BomberMan::Display::Ressources::getSound(const ::std::string & name) const
{
  static_cast<void>(name);
  return 0;
}

BomberMan::Display::IAsset *		BomberMan::Display::Ressources::getAsset(const ::std::string & name) const
{
  static_cast<void>(name);
  return 0;
}
