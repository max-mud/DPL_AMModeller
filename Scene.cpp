#include "Scene.h"

Scene::Scene(QWidget* parent) : QGLWidget(parent)
{
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/Vertex.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/Fragment.glsl");
    if (!m_program->link())
    {
        qWarning("Error: WTF Link not work");
        return;
    }

    m_posAttr = m_program->attributeLocation("vertex");
    m_colorAttr = m_program->attributeLocation("color");
    m_matrixModelUniform = m_program->uniformLocation("matrixModel");
    m_matrixProjectionUniform = m_program->uniformLocation("matrixProjection");
    m_matrixViewUniform = m_program->uniformLocation("matrixView");
}

void Scene::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!m_program->bind())
        return;

    QMatrix4x4 matrixModel;
    QMatrix4x4 matrixProjection;
    QMatrix4x4 matrixView;

    matrixProjection.perspective(60., 1., 1., 401);
    //matrixProjection.ortho(-200.0f, 200.0f, -200.0f, 200.0f, -200.0f, 200.0f);
    //matrixProjection.translate(0.0f, 0.0f, -0.0f);

    matrixModel.setToIdentity();

    QVector3D eye(200., 200., -200.);
    QVector3D center(0., 0., 0.);
    //QVector3D up(1. * pow(3., 0.5), -1. * pow(3., 0.5), 1. * pow(3., 0.5));


    /*QVector3D eye(0., 0., -100.);
    QVector3D center(0., 0., 0.);*/
    QVector3D up(0., 1., 0.);

    matrixView.lookAt(eye, center, up);

    m_program->setUniformValue(m_matrixModelUniform, matrixModel);
    m_program->setUniformValue(m_matrixProjectionUniform, matrixProjection);
    m_program->setUniformValue(m_matrixViewUniform, matrixView);

    GLfloat m_size = 100;
    GLfloat a = 1;
    GLfloat R = (a * pow(6., 0.5)) / 4.;
    GLfloat H = a * pow((2. / 3.), 0.5);
    GLfloat r = (a * pow(3., 0.5)) / 3.;
    GLfloat h = (a * pow(3., 0.5)) / 2.;
    GLfloat vertices[] =
    {
        /*
        m_size * 0.f,  m_size * R, m_size * 0.0f,

        m_size * 0.f, m_size * (R - H), m_size * r,

        m_size * a / 2.f, m_size * (R - H), m_size * (r - h),

        m_size * -a / 2.f, m_size * (R - H), m_size * (r - h),
        */

        //--------------------------------


        //1
        m_size * 0.f,  m_size * R, m_size * 0.0f,
        m_size * 0.f, m_size * (R - H), m_size * r,
        m_size * a / 2.f, m_size * (R - H), m_size * (r - h),

        //2
        m_size * 0.f,  m_size * R, m_size * 0.0f,
        m_size * 0.f, m_size * (R - H), m_size * r,
        m_size * -a / 2.f, m_size * (R - H), m_size * (r - h),

        //3
        m_size * 0.f,  m_size * R, m_size * 0.0f,
        m_size * a / 2.f, m_size * (R - H), m_size * (r - h),
        m_size * -a / 2.f, m_size * (R - H), m_size * (r - h),

        //4
        m_size * 0.f, m_size * (R - H), m_size * r,
        m_size * a / 2.f, m_size * (R - H), m_size * (r - h),
        m_size * -a / 2.f, m_size * (R - H), m_size * (r - h),

        /*
        m_size * 0.f, m_size * 1.f, m_size * 0.f,
        m_size * -0.5f, m_size * -0.5f, m_size * 0.f,
        m_size * 0.5f, m_size * -0.5f, m_size * 0.f
        */
    };

    GLfloat colors[] = {
        /*

        //1
        0.f,  0.f,  0.f, 1.0f,
        1.f,  0.f,  0.f, 1.0f,
        0.f,  1.f,  0.f, 1.0f,

        //2
        0.f,  0.f,  0.f, 1.0f,
        1.f,  0.f,  0.f, 1.0f,
        0.f,  0.f,  1.f, 1.0f,

        //3
        0.f,  0.f,  0.f, 1.0f,
        0.f,  1.f,  0.f, 1.0f,
        0.f,  0.f,  1.f, 1.0f,

        //4
        1.f,  0.f,  0.f, 1.0f,
        0.f,  1.f,  0.f, 1.0f,
        0.f,  0.f,  1.f, 1.0f
            */
        //1
        1.f,  0.f,  0.f, 1.0f,
        1.f,  0.f,  0.f, 1.0f,
        1.f,  0.f,  0.f, 1.0f,

        //2
        0.f,  1.f,  0.f, 1.0f,
        0.f,  1.f,  0.f, 1.0f,
        0.f,  1.f,  0.f, 1.0f,

        //3
        0.f,  0.f,  1.f, 1.0f,
        0.f,  0.f,  1.f, 1.0f,
        0.f,  0.f,  1.f, 1.0f,

        //4
        0.f,  0.f,  0.f, 1.0f,
        0.f,  0.f,  0.f, 1.0f,
        0.f,  0.f,  0.f, 1.0f
    };

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colorAttr, 4, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colorAttr);

    glPointSize(10);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 3, 3);
    glDrawArrays(GL_TRIANGLES, 6, 3);
    glDrawArrays(GL_TRIANGLES, 9, 3);

    glDisableVertexAttribArray(m_colorAttr);
    glDisableVertexAttribArray(m_posAttr);

}
