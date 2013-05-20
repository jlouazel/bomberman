//
//  BomberMan.cpp
//  BomberMan
//
//  Created by manour_m on 18/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include "BomberMan.hh"

int		main()
{
    try
    {
    }
    catch (BomberMan::Controllers::Error e)
    {
        std::cerr << "An error occured concerning controllers : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
    catch (BomberMan::Field::Error e)
    {
        std::cerr << "An error occured concerning the field : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
    catch (BomberMan::Events::Error e)
    {
        std::cerr << "An error occured concerning events : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
    catch (BomberMan::Core::Error e)
    {
        std::cerr << "An error occured concerning the core : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
    catch (BomberMan::DataFormat::Error e)
    {
        std::cerr << "An error occured concerning data format : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
    catch (BomberMan::Display::Error e)
    {
        std::cerr << "An error occured concerning the display : " << e.getWhat()
        << " in " << e.getWhere()
        << " (" << e.getDetails()
        << ")" << std::endl;
    }
}