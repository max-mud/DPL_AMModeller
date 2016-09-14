#include "Scene_template.h"
#include "ui_Scene_template.h"

Scene_template::Scene_template(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Scene_template)
{
    ui->setupUi(this);
}

Scene_template::~Scene_template()
{
    delete ui;
}
