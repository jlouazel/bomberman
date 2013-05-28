//
//  Error.h
//  BomberMan
//
//  Created by manour_m on 20/05/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __EVENTERROR_HH___
#define __EVENTERROR_HH____

#include	<exception>
#include	<string>

namespace BomberMan
{
  namespace Event
  {
    class EventError : public std::exception
    {
      std::string   _what;
      std::string   _where;
      std::string   _details;

    public:
      EventError(std::string, std::string, std::string);
      ~EventError() throw();

      std::string   getWhat() const;
      std::string   getWhere() const;
      std::string   getDetails() const;
    };
  }
}

#endif /* defined(__BomberMan__Error__) */
