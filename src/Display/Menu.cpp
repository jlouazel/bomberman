#include <algorithm>
#include <vector>
#include "AObject.hpp"
#include "IOnglet.hpp"
#include "Menu.hpp"
#include "Texture2d.hpp"

namespace BomberMan
{
    namespace Display
    {
        Menu::Menu(std::string &texture)
        {
            Vector3f      vectorPosition(0, 0, 0);
            Vector3f      vectorLen(100.0, 100.0, 0.0);
            Vector3f      vectorRotation(0.0, 0.0, 0.0);
            
            this->_stringTextureFond = texture;
            this->_textureFond = new Texture2d(this->_stringTextureFond, vectorPosition, vectorRotation, vectorLen);
            this->_textureFond->initialize();
        }
        
        Menu::Menu()
        {
            Vector3f      vectorPosition(0, 0, 0);
            Vector3f      vectorLen(100.0, 100.0, 0.0);
            Vector3f      vectorRotation(0.0, 0.0, 0.0);
            
            this->_stringTextureFond = "Texture/Fond.jpg";
            this->_textureFond = new Texture2d(this->_stringTextureFond, vectorPosition, vectorRotation, vectorLen);
            this->_textureFond->initialize();
        }
        
        Menu::~Menu()
        {
        }
        
        void	Menu::addOnglet(IOnglet *newOnglet)
        {
            this->_onglet.push_back(newOnglet);
        }
        
        IOnglet	*Menu::getOneOnglet(int i) const
        {
            if (static_cast <unsigned int> (i) < this->_onglet.size())
                return (this->_onglet[i]);
            return (this->_onglet.back());
        }
        
        std::vector <IOnglet *> Menu::getOnglet() const
        {
            return (this->_onglet);
        }
        
        void	Menu::affAllOnglet()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
            glClearDepth(1.0f);
            this->_textureFond->draw();
            std::vector<IOnglet *>::iterator it = this->_onglet.begin();
            for (; it != this->_onglet.end(); ++it)
                (*it)->affOnglet();
        }
    }
}