//
// Created by konstantin on 07.01.2021.
//

#ifndef UNTITLED_OBJECTFACTORY_H
#define UNTITLED_OBJECTFACTORY_H

#include "../Object.h"

class ObjectFactory {
protected:
    std::string filename;
    objl::Loader *loader = nullptr;
public:
    ObjectFactory(std::string filename);

    Object createFromFile(const std::string& name);

    virtual ~ObjectFactory();
};


#endif //UNTITLED_OBJECTFACTORY_H
