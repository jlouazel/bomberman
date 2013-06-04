#include	<algorithm>
#include	"IGameComponent.hh"
#include	"EventManager.hh"
#include	"InputManager.hh"
#include	"KeyBoardManager.hh"
#include	"MenuManager.hh"
#include	"Resources.hh"
#include	"BomberMan.hh"
#include	"EndOfBomberMan.hh"
#include	"Empty.hh"

#include	<iostream>

namespace BomberMan
{
    namespace Core
    {
        BomberMan::BomberMan()
        {
        }
        
        BomberMan::~BomberMan()
        {
            if (this->_currentGame)
                delete this->_currentGame;
        }
        
        void	BomberMan::initialize()
        {
            // valeur par defaut : BomberMan inactif
            this->_intro = false;
            this->_menu = false;
            this->_game = true;
            this->_currentGame = new BomberGame;
            
            // initialisation : 1ere sequence = intro + load assets / ressources
            this->_initializeWindow();
            this->_initializeIntro();
            this->_initializeResources();
            this->_initializeInput();
            this->_initializeEvent();
            this->_initializeMenu();
            
            /* Initialisation ressources GDL */
            /* Initialise Display */
        }
        
        void	BomberMan::_initializeWindow()
        {
            this->window_.setTitle("Breaking Bad");
            this->window_.setHeight(BOMBER_HEIGHT);
            this->window_.setWidth(BOMBER_WIDTH);
            this->window_.create();
            this->camera_.initialize();
        }
        
        void	BomberMan::_initializeResources() const
        {
            Display::Resources::getResources();
        }
        
        void	BomberMan::_initializeIntro()
        {
            this->_intro = false;
        }
        
        void	BomberMan::_initializeInput() const
        {
            Input::InputManager::getInputManager()->init();
        }
        
        void	BomberMan::_initializeEvent() const
        {
            Event::EventManager::getEventManager();
        }
        
        void	BomberMan::_initializeMenu() const
        {
            Display::MenuManager::getMenuManager();
        }
        
        void	BomberMan::update(void)
        {
            Input::Controller::KeyBoardManager::getKeyBoardManager()->treatInput(this->input_);
            if (this->_intro)
                this->_updateIntro();
            else
            {
                if (this->_menu)
                    this->_updateMenu();
                else if (this->_game)
                    this->_updateGame();
            }
        }
        
        void	BomberMan::_updateIntro()
        {
            std::cout << "UPDATE INTRO\n";
            this->_intro = true;
            this->_menu = false; /* true */
            Display::MenuManager::getMenuManager()->menu(Display::Menu::MAIN);
        }
        
        void	BomberMan::_updateMenu()
        {
            std::cout << "UPDATE MENU\n";
            Display::MenuManager::getMenuManager()->update();
        }
        
        void	BomberMan::_updateGame()
        {
            if (this->_currentGame)
            {
                // this->_currentGame->update();
                this->_currentGame->getManager()->Field::Manager::get(0, 0).front()->getAsset()->update(gameClock_);
            }
        }
        
        void	BomberMan::draw(void)
        {
            camera_.update(gameClock_, input_);
            if (this->_intro)
                this->_drawIntro();
            else
            {
                if (this->_menu || this->_game)
                {
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
                    glClearDepth(1.0f);
                    glMatrixMode(GL_MODELVIEW);
                }
                if (this->_menu)
                    this->_drawMenu();
                else if (this->_game)
                    this->_drawGame();
            }
        }
        
        void	BomberMan::_drawIntro() const
        {
        }
        
        void	BomberMan::_drawMenu() const
        {
            Display::MenuManager::getMenuManager()->draw();
        }
        
        static void	affObjs(Field::IGameComponent * comp)
        {
            if (dynamic_cast<Field::Empty *>(comp) == comp)
            {
                comp->getAsset()->draw();
                std::cout << "Empty (" << comp->getX() << ";" << comp->getY() << ")" << std::endl;
                std::cout << "-------> " << comp->getAsset()->getPosition().getX() << std::endl;
                std::cout << "-------> " << comp->getAsset()->getPosition().getY() << std::endl;
                std::cout << "-------> " << comp->getAsset()->getPosition().getZ() << std::endl;
            }
        }
        
        void	BomberMan::_drawGame() const
        {
            // std::cout << "--START DRAW GAME--" << std::endl;
            // for (unsigned int y = 0; y != this->_currentGame->getManager()->Field::Manager::getHeight(); y++)
            // 	for (unsigned int x = 0; x != this->_currentGame->getManager()->Field::Manager::getWidth(); x++)
            // 	  std::for_each(this->_currentGame->getManager()->Field::Manager::get(x, y).begin(), this->_currentGame->getManager()->Field::Manager::get(x, y).end(), affObjs);
            this->_currentGame->getManager()->Field::Manager::get(0, 0).front()->getAsset()->draw();
            // std::cout << "--DRAW GAME--" << std::endl;
            //this->_currentGame->draw();
            
            for (unsigned int y = 0; y != this->_currentGame->getManager()->Field::Manager::getHeight(); y++)
                for (unsigned int x = 0; x != this->_currentGame->getManager()->Field::Manager::getWidth(); x++)
                    std::for_each(this->_currentGame->getManager()->Field::Manager::get(x, y).begin(), this->_currentGame->getManager()->Field::Manager::get(x, y).end(), affObjs);
            std::cout << "--DRAW GAME--" << std::endl;
        }
        
        void	BomberMan::unload(void)
        {
            Input::InputManager::deleteInputManager();
            Event::EventManager::deleteEventManager();
            Display::MenuManager::deleteMenuManager();
            Display::Resources::deleteResources();
        }
    }
}
