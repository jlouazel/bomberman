//
//  Error.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __BomberMan__Error__
#define __BomberMan__Error__

#include <exception>
#include <string>

class Error : public std::exception
{
    std::string &	_what;
    std::string &   _where;
    std::string &   _details;
    
public:
    Error(std::string &, std::string &, std::string &);
    ~Error();
    
    std::string &   getWhat() const;
    std::string &   getWhere() const;
    std::string &   getDetails() const;
};

#endif /* defined(__BomberMan__Error__) */
