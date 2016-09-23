#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QIcon>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QTreeView>
#include "Scene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool is_model_tree_animation_dirrection_right = true;
    int window_height, window_width;
    float model_tree_height_percent = 1.;
    float model_tree_width_percent = 0.3;
    float model_tree_height_animation_percent = model_tree_height_percent;
    float model_tree_width_animation_percent = model_tree_width_percent;
    //float show_hide_model_tree_size_percent = 0.01;
    Scene *scene;
    QIcon *show_hide_model_tree_icon;
    QTreeWidget *model_tree;
    QPushButton *show_hide_model_tree;
    QTimer *timer;

    void initialize();

protected:
    void resizeEvent(QResizeEvent *);
    //void mouseMoveEvent(QResizeEvent *);

private:

signals:
    void startModelTreeAnimation();

public slots:

protected slots:

private slots:
    void on_show_hide_model_tree_clicked();
    void modelTreeAnimation();

};

#endif // MAINWINDOW_H
