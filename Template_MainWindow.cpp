#include "Template_MainWindow.h"
#include "ui_Template_MainWindow.h"

Template_MainWindow::Template_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Template_MainWindow)
{
    ui->setupUi(this);
}

Template_MainWindow::~Template_MainWindow()
{
    delete ui;
}
