#ifndef _scene_h
#define _scene_h

#include "glthings.h"
#include "sceneobject.h"
#include "settings.h"
#include "buffer.h"

class Scene
{
public:
    explicit Scene(HDC context, HWND window);
    ~Scene();

    void rootUpdate();

    void tick(double ticktime);
    void render();

    double runtime();

    template<class T>
    T* createObject(T* newObject)
    {
        for (int i = 0; i < MAX_SCENE_OBJECTS; i++) {
            if (_objects[i] == NULL) {
                _objects[i] = (SceneObject*)newObject;
                return newObject;
            }
        }
        MessageBox(NULL, "Cannot allocate any more objects", "SCENE ERROR", 0);
        delete newObject;
        return NULL;
    }

    Position getCamera() const;
    Buffer* getUvBuffer() const;

    static Scene* getScene();

    void drawText(const char* text, size_t len, Position at);
    Size getResolution();

private:
    HDC context;
    HWND window;
    double starttime;
    double lastTick;
    GLuint globVao;
    Buffer* gUvBuff;

    Position _camera;

    static Scene* _scene;
    SceneObject* _objects[MAX_SCENE_OBJECTS];
};

#endif
