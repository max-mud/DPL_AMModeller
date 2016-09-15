#include "Scene.h"

Scene::Scene(QWidget* parent) : QGLWidget(parent)
{
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();
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
    m_matrixUniform = m_program->uniformLocation("matrix");
}

void Scene::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    if (!m_program->bind())
        return;

    QMatrix4x4 matrix;
    matrix.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);
    matrix.translate(0.0f, 0.0f, -1.0f);

    m_program->setUniformValue(m_matrixUniform, matrix);

    GLfloat m_size = 1;
    GLfloat vertices[] =
    {
        m_size * 0.0f,  m_size * 0.5f,
        m_size * -0.5f, m_size * -0.5f,
        m_size * 0.5f,  m_size * -0.5f
    };

    GLfloat colors[] = {
        1.f,  0.f,  0.f,
        0.f,  1.f,  0.f,
        0.f,  0.f,  1.f
    };

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colorAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colorAttr);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(m_colorAttr);
    glDisableVertexAttribArray(m_posAttr);

}
