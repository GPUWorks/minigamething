#ifndef _buffer_h
#define _buffer_h

#include "glthings.h"

class Buffer
{
public:
    static Buffer* makeRect(float w=1.0f, float h=1.0f, float z=0.0f);
    static Buffer* makeData(void* data = NULL, size_t dataLen=0);
    static Buffer* makeUvRect();
    void bind();
    void bindAndAttribTo(GLuint attrib);
    void drawArray(GLenum mode);

    GLuint getId() const;
    ~Buffer();

    // disable copying explicitly
    Buffer(const Buffer&) = delete;
    Buffer & operator=(const Buffer&) = delete;
    Buffer(Buffer &&) = delete;
    Buffer & operator=(Buffer&&) = delete;

protected:
    Buffer(void* data, size_t dataLen, GLenum type=GL_ARRAY_BUFFER);

private:
    GLuint _id;
    GLenum _type;
    size_t _elementCount;
};

#endif //_buffer_h
