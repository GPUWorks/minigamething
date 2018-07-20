#ifndef _menu_h
#define _menu_h

#include "sceneobject.h"
#include "buffer.h"
#include "shader.h"

class Menu : public SceneObject
{
public:
    Menu();
    virtual ~Menu();

    virtual void tick(double ticktime) override;
    virtual void render() override;

private:

    Buffer* backgroundVbo;
    Program* backgroundProgram;
};

#endif // _menu_h
