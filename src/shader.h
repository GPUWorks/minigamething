#ifndef _shader_h
#define _shader_h

#include "glthings.h"

/**
 \brief A shader. Can be vertex/fragment/... shader. Multuple ones can be linked into a Program
*/
class Shader
{
public:
    /**
     \brief Constructs a shader. Should only be called via new
     \param type Shader type. Something like GL_FRAGMENT_SHADER or GL_VERTEX_SHADER
     \param data the shader source code. 0 terminated is assumed if len is 0
     \param len the length of the source code
    */
    explicit Shader(GLenum type, unsigned char* data, size_t len);

    // disable copying explicitly
    Shader(const Shader&) = delete;
    Shader & operator=(const Shader&) = delete;
    Shader(Shader &&) = delete;
    Shader & operator=(Shader&&) = delete;

    ///< Destructor
    ~Shader();

    /**
        \return if this shader is valid/sucessfully compiled
    */
    bool isValid() const;

    /**
     * \return opengl id of this shader
    */
    GLuint getId() const;

private:
    GLuint _id;
    bool _valid;
};

/**
 *\brief represents a gpu program (multiple linked shaders)

*/
class Program
{
public:

    /**
     * \brief Constructs a GPU Program and links the shaders. Also takes ownership (!!!) the given shaders
     * \param shaders array of pointers to Shader objects
     * \param count number of shader objects to link
    */
    explicit Program(Shader** shaders, size_t count);
    ~Program();
    // disable copying explicitly
    Program(const Program&) = delete;
    Program & operator=(const Program&) = delete;
    Program(Program &&) = delete;
    Program & operator=(Program&&) = delete;

    /**
     * \return gl id of this shader
    */
    GLuint getId() const;

    /**
     * \return true if this program is valid
    */
    bool isValid() const;

    /**
     * \brief equivalent of glUseProgram(getId());
    */
    void use();

    /**
     * \brief glUniform1f, just with name
    */
    void uniform1f(const char* name, float val);
    void uniform2f(const char* name, float f1, float f2);
    void uniform3f(const char* name, float f1, float f2,  float f3);
private:

    GLuint _id;
    bool _valid;
};

#endif //_shader_h
