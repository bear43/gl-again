//
// Created by konstantin on 06.01.2021.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include "../AbstractBuffer.h"

class Buffer : public AbstractBuffer {
protected:
    GLenum usage;
    GLenum target;
    GLsizei size = 0;
    GLvoid* data = nullptr;

public:
    Buffer(const string &name, GLenum usage, GLenum target);

    void bindBuffer() override;

    void unbindBuffer() override;

    void fill(GLsizei size, GLvoid* data);

    GLenum getUsage() const;

    void setUsage(GLenum usage);

    GLenum getTarget() const;

    void setTarget(GLenum target);

    void deleteBuffer() override;

};


#endif //UNTITLED_BUFFER_H
