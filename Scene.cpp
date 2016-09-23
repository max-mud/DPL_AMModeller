#include "Scene.h"

Scene::Scene(QWidget* parent) : QGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScene()));
    timer->start();
    angle_action = 0;
    angle_maouse_x = 0;
    angle_maouse_y = 0;
    is_mouse_pressed = false;
    pos_x = 0;
    pos_y = 0;
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);

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

void Scene::resizeGL(int n_width, int n_height)
{
    winWid = n_width;
    winHei = n_height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)n_width, (GLint)n_height);
    updateGL();
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!m_program->bind())
        return;

    GLfloat m_size = 100;
    GLfloat a = 1;
    GLfloat R = (a * pow(6., 0.5)) / 4.;
    GLfloat H = a * pow((2. / 3.), 0.5);
    GLfloat r = (a * pow(3., 0.5)) / 3.;
    GLfloat h = (a * pow(3., 0.5)) / 2.;
    GLfloat vertices[] =
    {

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
    };

    GLfloat colors[] = {

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
    };

    //Матрицы:

    QMatrix4x4 matrixModel;
    QMatrix4x4 matrixProjection;
    QMatrix4x4 matrixView;

    //Матрица ПРОЕКЦИИ
    matrixProjection.perspective(30., winWid/winHei, 0.01, 800.);

    //Матрица ВИДА
    QVector3D eye(0., 0., 400.);
    QVector3D center(0., 0., 0.);
    QVector3D up(0., 1., 0.);
    matrixView.lookAt(eye, center, up);
    matrixView.rotate(angle_maouse_x, 0., 1., 0.);
    matrixView.rotate(angle_maouse_y, cos((angle_maouse_x * M_PI) / 180.), 0., sin((angle_maouse_x * M_PI) / 180.));

    //Матрица МОДЕЛИ
    //GLfloat alph = sin((angle_action * M_PI) / 180.) * 100;
    matrixModel.setToIdentity();
    //matrixModel.rotate(angle_action, 1., 0., 0.);
    //matrixModel.translate(alph / pow(2., 0.5), alph / pow(2., 0.5), 0.);

    //Связывание и отрисовка
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colorAttr, 4, GL_FLOAT, GL_FALSE, 0, colors);
    m_program->setUniformValue(m_matrixModelUniform, matrixModel);
    m_program->setUniformValue(m_matrixProjectionUniform, matrixProjection);
    m_program->setUniformValue(m_matrixViewUniform, matrixView);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colorAttr);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 3, 3);
    glDrawArrays(GL_TRIANGLES, 6, 3);
    glDrawArrays(GL_TRIANGLES, 9, 3);

    glDisableVertexAttribArray(m_colorAttr);
    glDisableVertexAttribArray(m_posAttr);

}

void Scene::updateScene()
{
    angle_action += 0.2;
    if (angle_action < 360)
        angle_action += 0.2;
    else
        angle_action = 0.2;
    updateGL();
}

void Scene::mouseMoveEvent(QMouseEvent *ev)
{
    if (is_mouse_pressed)
    {
        angle_maouse_y += ev->y() - pos_y;
        if (angle_maouse_y >= 360.)
            angle_maouse_y = angle_maouse_y - 360.;

        if (angle_maouse_y <= -360.)
            angle_maouse_y = angle_maouse_y + 360.;

//        if ((angle_maouse_y > -90. && angle_maouse_y <= 90.) || angle_maouse_y > 270. || angle_maouse_y <= -270.)
            angle_maouse_x += ev->x() - pos_x;
//        else
//            angle_maouse_x -= ev->x() - pos_x;

        if (angle_maouse_x >= 360.)
            angle_maouse_x = angle_maouse_x - 360.;

        if (angle_maouse_x <= -360.)
            angle_maouse_x = angle_maouse_x + 360.;

        pos_x = ev->x();
        pos_y = ev->y();
    }
    pos_x = ev->x();
    pos_y = ev->y();
    updateScene();
}

void Scene::mousePressEvent(QMouseEvent *ev)
{
    is_mouse_pressed = true;
    pos_x = ev->x();
    pos_y = ev->y();
}

void Scene::mouseReleaseEvent(QMouseEvent *ev)
{
    is_mouse_pressed = false;
}
