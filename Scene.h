#ifndef SCENE_H
#define SCENE_H

#include <math.h>
#include <vector>
#include "SceneObject.h"
#include <QEvent>
#include <QGLWidget>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QtOpenGL>
#include <QTimer>

class Scene : public QGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    Scene(QWidget *parent = 0);

    QOpenGLShaderProgram *m_program;
    GLint m_posAttr;
    GLint m_colorAttr;
    GLint m_matrixModelUniform;
    GLint m_matrixProjectionUniform;
    GLint m_matrixViewUniform;
    std::vector<SceneObject> *objects;

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

protected slots:
    void updateScene();

private:
    bool is_mouse_pressed;

    float angle_action;
    float angle_maouse_x;
    float angle_maouse_y;
    float pos_x;
    float pos_y;
    float winHei;
    float winWid;

    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

};

#endif // SCENE_H
