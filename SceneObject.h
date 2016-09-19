#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QObject>

class SceneObject : public QObject
{
    Q_OBJECT
public:
    explicit SceneObject(float *, float * = 0, float * = 0, QObject *parent = 0);

private:
    float *colors;
    float *normals;
    float *vertices;

    void loadObject(float *, float * = 0, float * = 0);

signals:

public slots:
};

#endif // SCENEOBJECT_H
