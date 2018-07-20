#include "sceneobject.h"
#include <windows.h>

SceneObject::SceneObject()
    : _deleted(false)
    ,  _layer(Background)
{

}

SceneObject::~SceneObject()
{
    MessageBox(NULL, "CAR BEING", "DELETED", 0);
}

bool SceneObject::deleted()
{
    return _deleted;
}

void SceneObject::deleteLater()
{
    _deleted = true;
}

SceneObject::Layer SceneObject::getLayer() const
{
    return _layer;
}
