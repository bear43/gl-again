//
// Created by konstantin on 13.12.2020.
//

#ifndef UNTITLED_IDHOLDER_H
#define UNTITLED_IDHOLDER_H


#include <GL/gl.h>

class IdHolder {
protected:
    GLuint id = 0;
public:
    GLuint getId() const;
    void setId(GLuint id);
    GLuint * getIdPointer();
};


#endif //UNTITLED_IDHOLDER_H
