//
//  Empty.cpp
//  BomberMan
//
//  Created by manour_m on 17/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "Empty.hh"

BomberMan::Field::Empty::Empty()
{
}

BomberMan::Field::Empty::~Empty()
{
}

void    BomberMan::Field::Empty::explode(int damages, BomberMan::Field::eDirection direction)
{
  static_cast<void>(damages);
  static_cast<void>(direction);
    // propagation
}
