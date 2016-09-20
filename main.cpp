#include <QtGui>
#include "MainWindow.h"
#include "Template_MainWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWindow MW;
//    MW.setWindowTitle("QT OpenGL - Lesson 1");
//    MW.setGeometry(650,350,500,500);
    MW.show();

    Template_MainWindow t_MW;
    t_MW.show();

    return app.exec();
}
