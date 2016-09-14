#ifndef SCENE_TEMPLATE_H
#define SCENE_TEMPLATE_H

#include <QMainWindow>

namespace Ui {
class Scene_template;
}

class Scene_template : public QMainWindow
{
    Q_OBJECT

public:
    explicit Scene_template(QWidget *parent = 0);
    ~Scene_template();

private:
    Ui::Scene_template *ui;
};

#endif // SCENE_TEMPLATE_H
