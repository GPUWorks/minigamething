#include "menu.h"
#include "scene.h"
#include "player.h"

extern unsigned char resources_base_vert[];
extern unsigned int resources_base_vert_len;
extern unsigned char resources_menubackground_frag[];
extern unsigned int resources_menubackground_frag_len;

Menu::Menu()
{
    backgroundVbo = Buffer::makeRect(2.0,2.0,0.0);
    Shader* bgshaders[2];
    bgshaders[0] = new Shader(GL_VERTEX_SHADER, resources_base_vert, resources_base_vert_len);
    bgshaders[1] = new Shader(GL_FRAGMENT_SHADER, resources_menubackground_frag, resources_menubackground_frag_len);
    backgroundProgram = new Program(bgshaders, 2);

    Scene::getScene()->createObject(new Player());
}

Menu::~Menu()
{
    MessageBox(NULL, "IM BEING", "DELETED", 0);
}
void Menu::render()
{
    backgroundProgram->use();
    auto res = Scene::getScene()->getResolution();
    backgroundProgram->uniform1f("time", (float)Scene::getScene()->runtime());
    backgroundProgram->uniform2f("res", res.w, res.h);
    backgroundVbo->bindAndAttribTo(0);
    backgroundVbo->drawArray(GL_TRIANGLES);
}

void Menu::tick(double ticktime)
{

}
