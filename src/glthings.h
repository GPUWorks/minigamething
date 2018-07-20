#ifndef _glthings_h
#define _glthings_h

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#include <stdint.h>

bool loadGlPointers();

#define glDebugMessageCallback ((PFNGLDEBUGMESSAGECALLBACKARBPROC)_glDebugMessageCallback)
extern void* _glDebugMessageCallback;

#define glCreateShaderProgramEXT ((PFNGLCREATESHADERPROGRAMEXTPROC)_glCreateShaderProgramEXT)
extern void* _glCreateShaderProgramEXT;

#define glUseProgram ((PFNGLUSEPROGRAMPROC)_glUseProgram)
extern void* _glUseProgram;

#define glCreateShader ((PFNGLCREATESHADERPROC)_glCreateShader)
extern void* _glCreateShader;

#define glShaderSource ((PFNGLSHADERSOURCEPROC)_glShaderSource)
extern void* _glShaderSource;

#define glCompileShader ((PFNGLCOMPILESHADERPROC)_glCompileShader)
extern void* _glCompileShader;

#define glGetShaderiv ((PFNGLGETSHADERIVPROC)_glGetShaderiv)
extern void* _glGetShaderiv;

#define glGetShaderInfoLog ((PFNGLGETSHADERINFOLOGPROC)_glGetShaderInfoLog)
extern void* _glGetShaderInfoLog;

#define glDeleteShader ((PFNGLDELETESHADERPROC)_glDeleteShader)
extern void* _glDeleteShader;

#define glCreateProgram ((PFNGLCREATEPROGRAMPROC)_glCreateProgram)
extern void* _glCreateProgram;

#define glAttachShader ((PFNGLATTACHSHADERPROC)_glAttachShader)
extern void* _glAttachShader;

#define glLinkProgram ((PFNGLLINKPROGRAMPROC)_glLinkProgram)
extern void* _glLinkProgram;

#define glGetProgramiv ((PFNGLGETPROGRAMIVPROC)_glGetProgramiv)
extern void* _glGetProgramiv;

#define glGetProgramInfoLog ((PFNGLGETPROGRAMINFOLOGPROC)_glGetProgramInfoLog)
extern void* _glGetProgramInfoLog;

#define glDetachShader ((PFNGLDETACHSHADERPROC)_glDetachShader)
extern void* _glDetachShader;

#define glDeleteProgram ((PFNGLDELETEPROGRAMPROC)_glDeleteProgram)
extern void* _glDeleteProgram;

#define glGetUniformLocation ((PFNGLGETUNIFORMLOCATIONPROC)_glGetUniformLocation)
extern void* _glGetUniformLocation;

#define glUniform1f ((PFNGLUNIFORM1FPROC)_glUniform1f)
extern void* _glUniform1f;
# define glUniform2f ((PFNGLUNIFORM2FPROC)_glUniform2f)
extern void* _glUniform2f;
# define glUniform3f ((PFNGLUNIFORM3FPROC)_glUniform3f)
extern void* _glUniform3f;

#define glGenVertexArrays ((PFNGLGENVERTEXARRAYSPROC)_glGenVertexArrays)
extern void* _glGenVertexArrays;

#define glBindVertexArray ((PFNGLBINDVERTEXARRAYPROC)_glBindVertexArray)
extern void* _glBindVertexArray;

#define glGenBuffers ((PFNGLGENBUFFERSPROC)_glGenBuffers)
extern void* _glGenBuffers;

#define glBindBuffer ((PFNGLBINDBUFFERPROC)_glBindBuffer)
extern void* _glBindBuffer;

#define glDeleteBuffers ((PFNGLDELETEBUFFERSPROC)_glDeleteBuffers)
extern void* _glDeleteBuffers;

#define glBufferData ((PFNGLBUFFERDATAPROC)_glBufferData)
extern void* _glBufferData;


#define glVertexAttribPointer ((PFNGLVERTEXATTRIBPOINTERPROC)_glVertexAttribPointer)
extern void* _glVertexAttribPointer;

#define glEnableVertexAttribArray ((PFNGLENABLEVERTEXATTRIBARRAYPROC)_glEnableVertexAttribArray)
extern void* _glEnableVertexAttribArray;

#define glDisableVertexAttribArray ((PFNGLDISABLEVERTEXATTRIBARRAYPROC)_glDisableVertexAttribArray)
extern void* _glDisableVertexAttribArray;

#endif //_glthings_h
