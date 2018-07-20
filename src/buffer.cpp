#include "buffer.h"

Buffer::Buffer(void* data, size_t dataLen, GLenum type)
    : _id(0)
    , _type(type)
    , _elementCount(dataLen/sizeof(float)/ 3)
{
    glGenBuffers(1, &_id);
    if (data != NULL) {
        bind();
        glBufferData(_type, dataLen, data, GL_STATIC_DRAW);
    }
}

Buffer::~Buffer()
{
    if (_id != 0) {
        glDeleteBuffers(1, &_id);
    }
}

GLuint Buffer::getId() const
{
    return _id;
}

void Buffer::bind()
{
    glBindBuffer(_type, _id);
}

void Buffer::bindAndAttribTo(GLuint attrib)
{
    bind();
    glEnableVertexAttribArray(attrib);
    glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Buffer::drawArray(GLenum mode)
{
    glDrawArrays(mode, 0, _elementCount);
}

Buffer* Buffer::makeData(void* data, size_t dataLen)
{
    return new Buffer(data, dataLen);
}

Buffer* Buffer::makeRect(float w, float h, float z)
{
    float hw = w / 2.0f;
    float hh = h / 2.0f;
    float rect[] = {
        -hw, -hh, z, // bottom left
        hw, -hh, z, // bottom right
        -hw, hh, z, // top left
        -hw, hh, z, // top left
        hw, -hh, z, // bottom right
        hw, hh, z // top right
    };
    return new Buffer((void*)rect, 18 * sizeof(float));
}

Buffer* Buffer::makeUvRect()
{
    float rect[] = {
        0., 1., 0.,                                         // bottom left
        1., 1., 0.,                                         // bottom right
        0., 0., 0.,                                         // top left
        0., 0., 0.,                                         // top left
        1., 1., 0.,                                         // bottom right
        1., 0., 0.                                          // top right
      };
    return new Buffer((void*)rect, 18 * sizeof(float));
}
