//
//  Error.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan_Controller_Error__
#define __BomberMan_Controller_Error__

#include <exception>
#include <string>

namespace BomberMan
{
    namespace Input
    {
        namespace Controller
        {
            class ControllerError : public std::exception
            {
                std::string   _what;
                std::string   _where;
                std::string   _details;
                
            public:
                ControllerError(std::string, std::string, std::string);
                ~ControllerError() throw();
                
                std::string   getWhat() const;
                std::string   getWhere() const;
                std::string   getDetails() const;
            };
        }
    }
}

#endif /* defined(__BomberMan__Error__) */
