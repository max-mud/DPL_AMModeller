#include <QtGui>
#include "Scene.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Scene s;
    s.setWindowTitle("QT OpenGL - Lesson 1");
    s.setGeometry(100,100,500,500); // Смещение и положение окна
    s.show();
    //s.setMouseTracking(true); // вызывать метод mouseMoveEvent при изменении позиции указателя, даже без клика кнопкой мыши
    //s.setCursor(QCursor(Qt::BlankCursor));

    return app.exec();
}
