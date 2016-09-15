#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QOpenGLFunctions>

class Scene : public QGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    Scene(QWidget *parent = 0);

    QOpenGLShaderProgram *m_program;

    void initializeGL(); // Метод для инициализирования opengl
    void resizeGL(int nWidth, int nHeight); // Метод вызываемый после каждого изменения размера окна
    void paintGL(); // Метод для вывода изображения на экран
    GLint m_posAttr;
    GLint m_colorAttr;
    GLint m_matrixUniform;

};

#endif // SCENE_H
