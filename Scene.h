#ifndef SCENE_H
#define SCENE_H

#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVariant>
#include <QWidget>

class Scene : public QMainWindow
{
    Q_OBJECT

public:

    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    //QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupScene()
    {
        if (this->objectName().isEmpty())
            this->setObjectName(QStringLiteral("Scene"));
        this->resize(400, 300);
        menuBar = new QMenuBar(this);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        this->setMenuBar(menuBar);
        mainToolBar = new QToolBar(this);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        this->addToolBar(mainToolBar);
        //centralWidget = new QWidget(this);
        //centralWidget->setObjectName(QStringLiteral("centralWidget"));
        //this->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(this);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        this->setStatusBar(statusBar);

        retranslateScene();

        QMetaObject::connectSlotsByName(this);
    } // setupScene

    void retranslateScene()
    {
        this->setWindowTitle(QApplication::translate("Scene", "Scene", 0));
    } // retranslateScene

    explicit Scene(QWidget *parent = 0);
    ~Scene();

private:

};

#endif // SCENE_H
