#include "shader.h"

Shader::Shader(GLenum type, unsigned char* data, size_t len)
    : _id(0)
    , _valid(false)
{
    _id = glCreateShader(type);
    if (_id != 0) {
        GLint glLen = (GLint)len;
        glShaderSource(_id, 1, (GLchar**)&data, &glLen);
        glCompileShader(_id);
        GLint status = 0;
        glGetShaderiv(_id, GL_COMPILE_STATUS, &status);
        if (status == GL_TRUE) {
            _valid = true;
        }
        else {
            GLint loglen = 0;
            glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &loglen);
            char* errbuff = new char[loglen];
            glGetShaderInfoLog(_id, loglen, NULL, errbuff);
            MessageBox(NULL, errbuff, "Shader Compilation failed", MB_ICONERROR | MB_OK);
            _valid = false;
            delete[] errbuff;
        }
    }
}

Shader::~Shader()
{
    if (_id != 0) {
        glDeleteShader(_id);
        _id = 0;
    }
}

bool Shader::isValid() const
{
    return _valid;
}

GLuint Shader::getId() const
{
    return _id;
}

//#############

Program::Program(Shader** shaders, size_t count)
    : _id(0)
    , _valid(false)
{
    _id = glCreateProgram();

    // check if we got a valid id
    if (_id == 0) {
        MessageBox(NULL, "Cannot create Program", "Shader Linking Failed", MB_ICONERROR | MB_OK);
    }
    else {
        // link them all
        for (auto i = 0; i < count; i++) {
            glAttachShader(_id, shaders[i]->getId());
        }
        glLinkProgram(_id);

        GLint result, loglen;
        glGetProgramiv(_id, GL_LINK_STATUS, &result);
        glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &loglen);
        if (result != GL_TRUE || loglen > 0) {
            char* errbuff = new char[loglen];
            glGetProgramInfoLog(_id, loglen, NULL, errbuff);
            MessageBox(NULL, errbuff, "Shader Linking Failed", MB_ICONERROR | MB_OK);
            _valid = result == GL_TRUE;
        }

        for (auto i = 0; i < count; i++) {
            glDetachShader(_id, shaders[i]->getId());
        }

        _valid = true;
    }

    // clean up and free up shaders
    for (auto i = 0; i < count; i++) {
        delete shaders[i];
    }
}

Program::~Program()
{
    if (_id != 0) {
        glDeleteProgram(_id);
        _id = 0;
    }
}

bool Program::isValid() const
{
    return _valid;
}

GLuint Program::getId() const
{
    return _id;
}

void Program::use()
{
    glUseProgram(_id);
}

void Program::uniform1f(const char* name, float value)
{
    GLint  loc = glGetUniformLocation(_id, name);
    if (loc != -1) {
        glUniform1f(loc, value);
    }
}
void Program::uniform2f(const char* name, float f1, float f2)
{
    GLint  loc = glGetUniformLocation(_id, name);
    if (loc != -1) {
        glUniform2f(loc, f1, f2);
      }
}
void Program::uniform3f(const char* name, float f1, float f2,  float f3)
{
    GLint  loc = glGetUniformLocation(_id, name);
    if (loc != -1) {
        glUniform3f(loc, f1, f2,  f3);
      }
}
