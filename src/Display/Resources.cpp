//
//  Resources.cpp
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include	<iostream>
#include	"Texture3d.hpp"
#include	"Texture2d.hpp"
#include	"Resources.hh"
#include	"EndOfBomberMan.hh"

namespace BomberMan
{
  namespace Display
  {
    Resources*	Resources::_ressources = 0;

    Resources*	Resources::getResources()
    {
      if (!Resources::_ressources)
	Resources::_ressources = new Resources;
      if (!Resources::_ressources)
	throw Core::EndOfBomberMan("Resources", "getResources", "NULL pointer");
      return Resources::_ressources;
    }

    void	Resources::deleteResources()
    {
      delete Resources::_ressources;
      Resources::_ressources = 0;
    }

    Resources::Resources()
    {
      this->_images["continueGame"] = gdl::Image::load("models/continuegame.png");
      this->_images["newGame"] = gdl::Image::load("models/newgame.png");
      this->_images["options"] = gdl::Image::load("models/options.png");
      this->_images["credits"] = gdl::Image::load("models/credits.png");
      this->_images["quit"] = gdl::Image::load("models/quit.png");

      for (std::map<std::string, gdl::Image>::iterator it = this->_images.begin();
      	   it != this->_images.end(); ++it)
	it->second.bind();





      Vector3f      vectorPosition(0, 0, 0);
      Vector3f      vectorLen(50.0, 8.0, 0.0);
      Vector3f      vectorRotation(0.0, 0.0, 0.0);

      this->_assets.insert(std::pair<std::string, AObject *>("marvin", new Texture3d("libgdl/assets/marvin.fbx", vectorPosition, vectorRotation, vectorLen)));
      this->_assets.insert(std::pair<std::string, AObject *>("walter", new Texture3d("models/WWunmoved.fbx", vectorPosition, vectorRotation, vectorLen)));
      this->_assets.insert(std::pair<std::string, AObject *>("walterWalking", new Texture3d("models/WWwalking.fbx", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setX(25);
      // this->_assets.insert(std::pair<std::string, AObject *>("newGame",  new Texture2d("models/newgame.png", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setY(28);
      //      this->_assets.insert(std::pair<std::string, AObject *>("continueGame",  new Texture2d("models/continuegame.png", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setY(15);
      //      this->_assets.insert(std::pair<std::string, AObject *>("continueGame",  new Texture2d("models/continuegame.png", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setY(41);
      //this->_assets.insert(std::pair<std::string, AObject *>("options",  new Texture2d("models/options.png", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setY(54);
      //      this->_assets.insert(std::pair<std::string, AObject *>("credits",  new Texture2d("models/credits.png", vectorPosition, vectorRotation, vectorLen)));
      vectorPosition.setY(67);
      //this->_assets.insert(std::pair<std::string, AObject *>("quit",  new Texture2d("models/quit.png", vectorPosition, vectorRotation, vectorLen)));
      // std::map<std::string, AObject *>::iterator itb = this->_assets.begin();
      // for (;itb != this->_assets.end(); ++itb)
      // 	(*itb).second->initialize();
    }

    Resources::~Resources()
    {
    }

    const gdl::Image*	Resources::getImage(const std::string &name)
    {
      if (this->_images.count(name) > 0)
	return &this->_images[name];
      return 0;
    }

    ISound *		Resources::getSound(const std::string & name)
    {
      if (this->_sounds.count(name) > 0)
	{
	  //this->_sounds[name];
	}
      return 0;
    }

    AObject *		Resources::getAsset(const std::string & name)
    {
      std::cout << this->_assets.count(name) << std::endl;
      if (this->_assets.count(name) > 0)
	{
	  this->_assets[name];
	}
      return 0;
    }
  }
}
