//
// Created by konstantin on 07.01.2021.
//

#include "ObjectFactory.h"

#include <utility>

ObjectFactory::ObjectFactory(std::string filename) : filename(std::move(filename)) {
    loader = new objl::Loader();
}

ObjectFactory::~ObjectFactory() {
    if(loader != nullptr) {
        delete loader;
        loader = nullptr;
    }
}

Object ObjectFactory::createFromFile(const std::string& name) {
    if(loader->LoadFile(filename)) {
        return Object(name, *loader);
    } else {
        throw std::runtime_error(fmt::format("Не удалось загрузить файл {}", filename));
    }
}
