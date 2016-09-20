#include "MainWindow.h"

MyQTreeWidget::MyQTreeWidget(QObject *parent)
{
}

void MyQTreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
//    QPainter *paint = new QPainter(this);
//    paint->setOpacity(0.5);
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(0, 0, 100, 100);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initialize();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initialize()
{
    scene = new Scene(this);
    scene->setObjectName(QStringLiteral("Scene"));
    this->setCentralWidget(scene);
    this->setObjectName(QStringLiteral("MainWindow"));
    this->setWindowTitle("AMModeller");
    this->setGeometry(650,350,500,500);
    //setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
    treeWidget = new MyQTreeWidget(scene->parent());
    //treeWidget;
    //QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
    //__qtreewidgetitem->setText(0, QStringLiteral("maxmud"));
    //treeWidget->setHeaderItem(__qtreewidgetitem);
    treeWidget->setObjectName(QStringLiteral("treeWidget"));
    treeWidget->setGeometry(QRect(0, 0, 256, this->geometry().height()));
    //treeWidget->setAttribute(Qt::WA_TranslucentBackground);
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    treeWidget->setGeometry(QRect(0, 0, 256, event->size().height()));
}
