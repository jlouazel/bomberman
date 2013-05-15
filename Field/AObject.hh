//
//  AObject.h
//  BomberMan
//
//  Created by manour_m on 15/05/13.
//
//

#ifndef BomberMan_AObject_h
#define BomberMan_AObject_h

#include "AGameComponent.hh"

class AObject : public AGameComponent
{
protected:
    eObjectType		_object_type;
    
public:
    virtual ~AObject(){}
    
    virtual void			explode() = 0;
    virtual eObjectType		getObjectType() const;
};

#endif
