#include <Clock.hpp>

#include "Vector.hpp"
#include "Empty.hh"
#include "FManager.hh"
#include "Texture3d.hpp"

namespace BomberMan
{
  namespace Field
  {
    Empty::Empty(bool isGround, float x, float y, BomberMan::Display::AObject * asset, BomberMan::Display::ISound * sound, BomberMan::Display::IAnimation * anim)
    {
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f      vectorPosition(x * 220, 0.0, y * 220);

      this->_x = x;
      this->_y = y;
      this->_isGround = isGround;
      if (asset == 0)
	this->_asset = new Display::Texture3d("models/Floor.fbx", vectorPosition, vectorRot, vectorLen);
      else
	this->_asset = asset;
      this->_textureExplosion = new Display::Texture3d("models/SmokeExplosion.fbx", vectorPosition, vectorRot, vectorLen);
      this->_asset->initialize();
      this->_sound = sound;
      this->_animation = anim;
      this->_explosion = false;
      this->_end = false;
      this->_textureExplosion->initialize();
      this->_clock = new gdl::Clock();
      this->_frame = -1;
      this->_playerTakeDomage = 0;
    }

    Empty::~Empty()
    {
    }

    void        Empty::update(gdl::GameClock const & gameClock, Manager *manager)
    {
      static_cast<void>(gameClock);
      static_cast<void>(manager);
      if (this->_playerTakeDomage != 0)
	{
	  // std::cout << "KIKOU : " << this->_frame << std::endl;
	  this->_frame++;
	  // std::cout << "KIKOU2 : " << this->_frame << std::endl;
	  if (this->_frame == 0)
	    {
	      // std::cout << "END Of kikou" << std::endl;
	      this->_playerTakeDomage = 0;
	      this->_frame = -1;
	    }
	}
      this->_asset->update(gameClock);
      this->_clock->update();
      if (this->_clock->getTotalElapsedTime() >= 0.93)
	{
	  this->_explosion = false;
	  this->_clock->pause();
	  this->_clock->reset();
	  this->_clock->pause();
	}
      if (this->_explosion == true)
	this->_textureExplosion->update(gameClock);
    }

    void        Empty::draw(gdl::GameClock const & gameClock)
    {
      this->_asset->draw();
      if (this->_explosion == true)
	this->_textureExplosion->draw();
    }

    void    Empty::explode(int damages)
    {
      // std::cout << "EXPLOSION in X = " << this->_x << " Y = " << this->_y << std::endl;
      this->_explosion = true;
      this->_playerTakeDomage = damages;
      Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
      Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
      Display::Vector3f      vectorPosition(this->_x * 220, 0.0, this->_y * 220);
      this->_textureExplosion = new Display::Texture3d("models/SmokeExplosion.fbx", vectorPosition, vectorRot, vectorLen);
      this->_textureExplosion->initialize();
      this->_clock->play();
    }

    bool	Empty::operator==(IGameComponent *other)
    {
      if (dynamic_cast<Empty *>(other) == other)
	if (other->getX() == this->_x && other->getY() == this->_y)
	  return (true);
      return (false);
    }

    int	Empty::getPlayerTakeDomage() const
    {
      return (this->_playerTakeDomage);
    }
  }
}
