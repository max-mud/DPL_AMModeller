#include "Scene_template.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);
    Scene_template w;
    w.show();

    return aa.exec();
}
