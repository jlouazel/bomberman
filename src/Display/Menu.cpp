#include <algorithm>
#include <vector>
#include "AObject.hpp"
#include "IOnglet.hpp"
#include "Menu.hpp"
#include "Texture2d.hpp"

BomberMan::Display::Menu::Menu(std::string &texture)
{
  BomberMan::Display::Vector3f      vectorPosition(0, 0, 0);
  BomberMan::Display::Vector3f      vectorLen(100.0, 100.0, 0.0);
  BomberMan::Display::Vector3f      vectorRotation(0.0, 0.0, 0.0);

  this->_stringTextureFond = texture;
  this->_textureFond = new BomberMan::Display::Texture2d(this->_stringTextureFond, vectorPosition, vectorRotation, vectorLen);
  this->_textureFond->initialize();
}

BomberMan::Display::Menu::Menu()
{
  BomberMan::Display::Vector3f      vectorPosition(0, 0, 0);
  BomberMan::Display::Vector3f      vectorLen(100.0, 100.0, 0.0);
  BomberMan::Display::Vector3f      vectorRotation(0.0, 0.0, 0.0);

  this->_stringTextureFond = "Texture/Fond.jpg";
  this->_textureFond = new BomberMan::Display::Texture2d(this->_stringTextureFond, vectorPosition, vectorRotation, vectorLen);
  this->_textureFond->initialize();
}

BomberMan::Display::Menu::~Menu()
{
}

void	BomberMan::Display::Menu::addOnglet(BomberMan::Display::IOnglet *newOnglet)
{
  this->_onglet.push_back(newOnglet);
}

BomberMan::Display::IOnglet	*BomberMan::Display::Menu::getOneOnglet(int i) const
{
  if (static_cast <unsigned int> (i) < this->_onglet.size())
    return (this->_onglet[i]);
  return (this->_onglet.back());
}

std::vector <BomberMan::Display::IOnglet *> BomberMan::Display::Menu::getOnglet() const
{
  return (this->_onglet);
}

void	BomberMan::Display::Menu::affAllOnglet()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  this->_textureFond->draw();
  std::vector<IOnglet *>::iterator it = this->_onglet.begin();
  for (; it != this->_onglet.end(); ++it)
    (*it)->affOnglet();
}
