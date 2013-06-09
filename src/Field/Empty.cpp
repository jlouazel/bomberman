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
      this->_frame = 0;
      this->_playerTakeDomage = 0;
      this->_idBomb = -1;
    }

    Empty::~Empty()
    {
    }

    int   Empty::getIdBomb() const
    {
      return (this->_idBomb);
    }

      void        Empty::update(gdl::GameClock const & gameClock, Manager *manager)
      {
	if (this->_playerTakeDomage != 0)
	  {
	    if (this->_frame >= 1)
	      {
		this->_playerTakeDomage = 0;
		this->_frame = 0;
	      }
	    this->_frame++;
	  }
	this->_asset->update(gameClock);
	this->_clock->update();
	if (this->_clock->getTotalElapsedTime() >= 0.93)
	  {
	    this->_explosion = false;
	    this->_idBomb = -1;
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

    void	Empty::setFrame(int i)
    {
      this->_frame = i;
    }

    void	Empty::setIdBomb(int i)
    {
      this->_idBomb = i;
    }

    void    Empty::explode(int damages, Manager *manager, int idBomb)
      {
	if (this->_isGround == true)
	  {
	    // std::cout << "Empty X = " << this->_x << " Y = " << this->_y << std::endl;
	    this->_idBomb = idBomb;
	    this->_explosion = true;
	    this->_playerTakeDomage = damages * 10;
	    Display::Vector3f      vectorLen(0.0, 0.0, 0.0);
	    Display::Vector3f      vectorRot(0.0, 0.0, 0.0);
	    Display::Vector3f      vectorPosition(this->_x * 220, 0.0, this->_y * 220);
	    this->_textureExplosion = new Display::Texture3d("models/SmokeExplosion.fbx", vectorPosition, vectorRot, vectorLen);
	    this->_textureExplosion->initialize();
	    this->_clock->play();
	  }
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
