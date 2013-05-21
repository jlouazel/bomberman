//
//  Field.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "BomberMan.hh"

Field::Field(unsigned int width, unsigned int height)
:   _width(width),
    _height(height),
    _map(width * height, std::list<IGameComponent *>)
{
}

Field::~Field()
{
}

std::list<IGameComponent *> &   Field::get(unsigned int x, unsigned int y)
{
    unsigned int    pos;
    
    pos = y * this->_width + x;
    return this->_map[pos];
}

unsigned int                    Field::getWidth() const
{
    return this->_width;
}

unsigned int                    Field::getHeight() const
{
    return this->height;
}
/*

**
**  Main de test
**


int main()
{
    Field::Field(5, 5)  field;
    Field::ObjectFactory    factory;
    Field::Object * obj;
    Field::Wall wall;
    Field::Player p;
    Field::Empty empty;
    Field::Object object(Field::BOMB, Field::NONE, 5, 5);
    
    try
    {
        obj = factory.create(std::pair<Field::BOMB, Field::NONE>);
        delete obj;
        obj = factory.create(std::pair<Field::BUFF, Field::LIFE>);
        delete obj;
        obj = factory.create(std::pair<Field::BUFF, Field::SPEED>);
        delete obj;
        obj = factory.create(std::pair<Field::BUFF, Field::RANGE>);
        delete obj;
    }
    catch (Field::Error e)
    {
        std::cerr << "An error occured : " << e.getWhat() << " in " << e.getWhere() << " (" << e.getDetails() << ")" << std::endl;
    }
}
*/