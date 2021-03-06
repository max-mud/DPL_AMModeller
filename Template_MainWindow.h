#ifndef TEMPLATE_MAINWINDOW_H
#define TEMPLATE_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Template_MainWindow;
}

class Template_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Template_MainWindow(QWidget *parent = 0);
    ~Template_MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_push_button_clicked();

private:
    Ui::Template_MainWindow *ui;
};

#endif // TEMPLATE_MAINWINDOW_H
