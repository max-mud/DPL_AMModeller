#include "Scene.h"
#include "Scene_template.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scene_template w;
    w.show();

    Scene s;
    s.show();

    return a.exec();
}
