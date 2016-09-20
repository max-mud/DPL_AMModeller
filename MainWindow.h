#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "Scene.h"

class MyQTreeWidget : public QWidget
{
    Q_OBJECT

public:
    MyQTreeWidget(QObject *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Scene *scene;
    MyQTreeWidget *treeWidget;

    void initialize();

protected:
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
