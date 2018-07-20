#include "player.h"
#include "glthings.h"
#include "scene.h"

extern unsigned char resources_object_vert[];
extern unsigned int resources_object_vert_len;
extern unsigned char resources_player_frag[];
extern unsigned int resources_player_frag_len;

Player::Player()
{
    playerVbo = Buffer::makeRect(1.,1.,-0.1);
    Shader* bgshaders[2];
    bgshaders[0] = new Shader(GL_VERTEX_SHADER, resources_object_vert, resources_object_vert_len);
    bgshaders[1] = new Shader(GL_FRAGMENT_SHADER, resources_player_frag, resources_player_frag_len);
    playerProgram = new Program(bgshaders, 2);
    zRotation = 0;
    _layer = Foreground;
}

Player::~Player()
{

}

void Player::tick(double ticktime)
{
    if (GetAsyncKeyState('D')) {
        pos.x += playerMaxspeed*ticktime;
    }
    if (GetAsyncKeyState('A')) {
        pos.x -= playerMaxspeed*ticktime;
      }
    if (GetAsyncKeyState('W')) {
        pos.y += playerMaxspeed*ticktime;
      }
    if (GetAsyncKeyState('S')) {
        pos.y -= playerMaxspeed*ticktime;
      }
}

void Player::render()
{
    playerProgram->use();
    auto res = Scene::getScene()->getResolution();
    auto camera = Scene::getScene()->getCamera();
    playerProgram->uniform1f("time", (float)Scene::getScene()->runtime());
    playerProgram->uniform2f("res", res.w, res.h);
    playerProgram->uniform3f("position",  pos.x,  pos.y,  pos.z);
    playerProgram->uniform3f("camera",  camera.x,  camera.y,  camera.z);
    playerProgram->uniform1f("zRotation",  zRotation);
    playerVbo->bindAndAttribTo(0);
    Scene::getScene()->getUvBuffer()->bindAndAttribTo(1);
    //->bindAndAttribTo(1);
    playerVbo->drawArray(GL_TRIANGLES);
}
