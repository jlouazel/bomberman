#include <algorithm>
#include <vector>
#include "AObject.hpp"
#include "IOnglet.hpp"
#include "Menu.hpp"

BomberMan::Display::Menu::Menu()
{
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

std::vector <IOnglet *> Menu::getOnglet() const
{
  return (this->_onglet);
}

void	BomberMan::Display::Menu::affAllOnglet()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::vector<IOnglet *>::iterator it = this->_onglet.begin();
  for (; it != this->_onglet.end(); ++it)
    (*it)->affOnglet();
}
