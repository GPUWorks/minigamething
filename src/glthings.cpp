#include "glthings.h"

void* _glDebugMessageCallback = NULL;
void* _glCreateShaderProgramEXT = NULL;
void* _glUseProgram = NULL;
void* _glCreateShader = NULL;
void* _glShaderSource = NULL;
void* _glCompileShader = NULL;
void* _glGetShaderiv = NULL;
void* _glGetShaderInfoLog = NULL;
void* _glGenVertexArrays = NULL;
void* _glBindVertexArray = NULL;
void* _glGenBuffers = NULL;
void* _glBindBuffer = NULL;
void* _glDeleteBuffers = NULL;
void* _glBufferData = NULL;
void* _glVertexAttribPointer = NULL;
void* _glEnableVertexAttribArray = NULL;
void* _glDisableVertexAttribArray = NULL;
void* _glDeleteShader = NULL;
void* _glCreateProgram = NULL;
void* _glAttachShader = NULL;
void* _glLinkProgram = NULL;
void* _glGetProgramiv = NULL;
void* _glGetProgramInfoLog = NULL;
void* _glDetachShader = NULL;
void* _glDeleteProgram = NULL;
void* _glGetUniformLocation = NULL;
void* _glUniform1f = NULL;
void* _glUniform2f = NULL;
void* _glUniform3f = NULL;

bool loadGlPointers()
{
    _glDebugMessageCallback = (void*)wglGetProcAddress("glDebugMessageCallback");
    _glCreateShaderProgramEXT = (void*)wglGetProcAddress("glCreateShaderProgramEXT");
    _glUseProgram = (void*)wglGetProcAddress("glUseProgram");
    _glCreateShader = (void*)wglGetProcAddress("glCreateShader");
    _glShaderSource = (void*)wglGetProcAddress("glShaderSource");
    _glCompileShader = (void*)wglGetProcAddress("glCompileShader");
    _glGetShaderiv = (void*)wglGetProcAddress("glGetShaderiv");
    _glGetShaderInfoLog = (void*)wglGetProcAddress("glGetShaderInfoLog");
    _glDeleteShader = (void*)wglGetProcAddress("glDeleteShader");
    _glCreateProgram = (void*)wglGetProcAddress("glCreateProgram");
    _glAttachShader = (void*)wglGetProcAddress("glAttachShader");
    _glLinkProgram = (void*)wglGetProcAddress("glLinkProgram");
    _glGetProgramiv = (void*)wglGetProcAddress("glGetProgramiv");
    _glGetProgramInfoLog = (void*)wglGetProcAddress("glGetProgramInfoLog");
    _glDetachShader = (void*)wglGetProcAddress("glDetachShader");
    _glDeleteProgram = (void*)wglGetProcAddress("glDeleteProgram");
    _glGetUniformLocation = (void*)wglGetProcAddress("glGetUniformLocation");
    _glUniform1f = (void*)wglGetProcAddress("glUniform1f");
    _glUniform2f = (void*)wglGetProcAddress("glUniform2f");
    _glUniform3f = (void*)wglGetProcAddress("glUniform3f");

    _glGenVertexArrays = (void*)wglGetProcAddress("glGenVertexArrays");
    _glBindVertexArray = (void*)wglGetProcAddress("glBindVertexArray");
    _glGenBuffers = (void*)wglGetProcAddress("glGenBuffers");
    _glBindBuffer = (void*)wglGetProcAddress("glBindBuffer");
    _glDeleteBuffers = (void*)wglGetProcAddress("glDeleteBuffers");
    _glBufferData = (void*)wglGetProcAddress("glBufferData");

    _glVertexAttribPointer = (void*)wglGetProcAddress("glVertexAttribPointer");
    _glEnableVertexAttribArray = (void*)wglGetProcAddress("glEnableVertexAttribArray");
    _glDisableVertexAttribArray = (void*)wglGetProcAddress("glDisableVertexAttribArray");

    return true;
}
