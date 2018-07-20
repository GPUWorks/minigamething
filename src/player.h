#ifndef _player_h
#define _player_h

#include "sceneobject.h"
#include "buffer.h"
#include "shader.h"

class Player : public SceneObject
{
public:
    Player();
    virtual ~Player();

    virtual void tick(double ticktime);
    virtual void render();

    bool hasMoved();

    const float playerMaxspeed = 1.0;
private:
    Buffer* playerVbo;
    Program* playerProgram;
    Position pos;
    float zRotation;
};

#endif                                                      // _player_h
