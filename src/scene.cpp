#include "scene.h"
#include "settings.h"
#include "shader.h"
#include "buffer.h"
#include "glthings.h"

double windows_time()
{
    FILETIME ft;
    ULONGLONG qwResult;
    GetSystemTimePreciseAsFileTime(&ft);
    qwResult = (((ULONGLONG)ft.dwHighDateTime) << 32) + ft.dwLowDateTime;
    return (double)qwResult / 10000000.0;
}
Program* prog = NULL;
Buffer* vbo = 0;

Scene* Scene::_scene = NULL;

Scene::Scene(HDC context,  HWND window)
    : context(context)
    , window(window)
    , starttime(0.0)
    , lastTick(0.0)
    , globVao(0)
{
    _scene = this;
    starttime = windows_time();
    //glDepthMask(GL_TRUE);
    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
    glGenVertexArrays(1, &globVao);
    glBindVertexArray(globVao);
    glEnable(GL_BLEND);
    for (int i = 0; i < MAX_SCENE_OBJECTS; i++) {
        _objects[i] = NULL;
    }

    gUvBuff = Buffer::makeUvRect();
}

Scene::~Scene()
{

}

void Scene::rootUpdate()
{
    if (runtime() - lastTick >= TICKTIME) {
        tick(runtime() - lastTick);
        lastTick = runtime();
    }

    render();

    // delete all marked stuff
    for (int i = 0; i < MAX_SCENE_OBJECTS; i++) {
        if (_objects[i] && _objects[i]->deleted()) {
            delete _objects[i];
            _objects[i] = NULL;
        }
    }
}

void Scene::tick(double ticktime)
{
    for (int i = 0; i < MAX_SCENE_OBJECTS; i++) {
        if (_objects[i] && !_objects[i]->deleted()) {
            _objects[i]->tick(ticktime);
        }
    }
}

void Scene::render()
{
    // clear first
    //glClearColor(1.0, 0.5, 0.25, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  each layer on its own
    for (int layer = (int)SceneObject::Layer::Background; layer < (int)SceneObject::Layer::N_Layers; layer++) {
        for (int i = 0; i < MAX_SCENE_OBJECTS; i++) {
            if (_objects[i] && !_objects[i]->deleted() && _objects[i]->getLayer() ==  layer) {
                _objects[i]->render();
            }
        }
    }

    SwapBuffers(context);
}

double Scene::runtime()
{
    return windows_time() - starttime;
}

Position Scene::getCamera() const
{
    return _camera;
}

Buffer* Scene::getUvBuffer() const
{
    return gUvBuff;
}

Scene* Scene::getScene()
{
    return _scene;
}

void Scene::drawText(const char* text, size_t len, Position at)
{

}

Size Scene::getResolution()
{
    RECT r;
    GetClientRect(window, &r);
    Size result;
    result.w = (float)(r.right-r.left);
    result.h = (float)(r.bottom-r.top);
    return result;
}
