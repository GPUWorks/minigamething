#ifndef _sceneobject_h
#define _sceneobject_h

#include "position.h"

class SceneObject
{
public:
    enum Layer {
        Background = 0,
        Foreground,
        Effect,
        Ui,
        N_Layers
    };

    friend class Scene;
    SceneObject();
    virtual ~SceneObject();

    SceneObject(const SceneObject&) = delete;
    SceneObject & operator=(const SceneObject&) = delete;
    SceneObject(SceneObject &&) = delete;
    SceneObject & operator=(SceneObject&&) = delete;


    virtual void tick(double ticktime) {}
    virtual void render() {}

    virtual Layer getLayer() const;

    bool deleted();
    void deleteLater();
private:
    bool _deleted;

protected:
    Layer _layer;
};

#endif
