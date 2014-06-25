#ifndef SCENE_H
#define SCENE_H

#include <QList>

#include "src/render/object/drawable.h"

class Scene
{
public:
    Scene();

    void draw();

private:
    QList<Drawable*> m_drawableList;
};

#endif // SCENE_H
