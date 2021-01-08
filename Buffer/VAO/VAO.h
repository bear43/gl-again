//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VAO_H
#define UNTITLED2_VAO_H

#include "../AbstractBuffer.h"
#include "../Buffer/Buffer.h"

/**
 * Buffer uses first two indices in array:
 * [0] -> vertex
 * [1] -> textureCoords
 * [2] -> normals
 * [3] -> ambientColor
 * [4] -> diffuseColor
 * [5] -> specularColor
 */
class VAO : public AbstractBuffer
{
public:
    VAO(const string &name);


    virtual ~VAO();

    void bindBuffer() override;
    void deleteBuffer();
    void unbindBuffer();
    /**
     * Accepts Buffer with correct data format:
     * |x y z| |texU texV| |normalX normalY normalZ|
     * All components are float type.
     * @param buffer Buffer with data described above.
     */
    void linkWithVBO(Buffer *buffer);
    /**
     * Accepts EBO with correct format:
     * |vertex1 vertex2 vertex3|
     * (Triangle polygon is used).
     * @param buffer Buffer with indices.
     */
    void linkWithEBO(Buffer *buffer);
    /**
     * Accepts material data.
     * |ambientR ambientG ambientB| |diffuseR diffuseG diffuseB|
     * |specularR specularG specularB|
     * @param buffer Buffer with material data described above.
     */
    void linkWithMaterial(Buffer *buffer);
};


#endif //UNTITLED2_VAO_H
