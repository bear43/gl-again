//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_BUFFER_H
#define UNTITLED2_BUFFER_H

#include <GL/glew.h>
#include "../Common/IdHolder.h"
#include <GL/gl.h>
#include <string>

using namespace std;

class AbstractBuffer : public IdHolder
{
protected:
    bool buffer_created = false;
    string name;
    explicit AbstractBuffer(const string &name) : IdHolder(), name(name)
    {}
    AbstractBuffer() = default;
public:
    virtual void bindBuffer() = 0;
    virtual void unbindBuffer() = 0;
    virtual void deleteBuffer() = 0;
};

#endif //UNTITLED2_BUFFER_H
