#include "SceneObject.h"

SceneObject::SceneObject(float *vertices_array, float *colors_array, float *normals_array, QObject *parent) : QObject(parent)
{
    loadObject(vertices_array, colors_array, normals_array);
}

void SceneObject::loadObject(float *vertices_array, float *colors_array, float *normals_array)
{
    vertices = vertices_array;
    colors = colors_array;

    if (normals_array)
        normals = normals_array;
    else
        ;
}
