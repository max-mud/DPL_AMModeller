#include "MainWindow.h"

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
    //scene->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 127);"));

    model_tree = new QTreeWidget(this);
    model_tree->setObjectName(QStringLiteral("treeWidget"));

    //QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
    //__qtreewidgetitem->setText(0, QStringLiteral("maxmud"));
    //model_tree->setHeaderItem(__qtreewidgetitem);

    show_hide_model_tree = new QPushButton(this);
    show_hide_model_tree->setObjectName(QStringLiteral("show_hide_model_tree"));
    show_hide_model_tree_icon = new QIcon();
    show_hide_model_tree_icon->addFile(QStringLiteral(":/Icons/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
    show_hide_model_tree->setIcon(*show_hide_model_tree_icon);
    //show_hide_model_tree->setFlat(true);

    this->setCentralWidget(scene);
    this->setObjectName(QStringLiteral("MainWindow"));
    this->setWindowTitle("AMModeller");
    this->setGeometry(650,350,500,500);

    timer = new QTimer(this);
    connect(show_hide_model_tree, SIGNAL(clicked(bool)), this, SLOT(on_show_hide_model_tree_clicked()));
    connect(timer, SIGNAL(timeout()), this, SLOT(modelTreeAnimation()));
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    window_height = event->size().height();
    window_width = event->size().width();
    scene->setGeometry(QRect(0, 0, event->size().width(), event->size().height()));
    model_tree->setGeometry(QRect(0, 0, window_width * model_tree_width_animation_percent, window_height * model_tree_height_animation_percent));
    show_hide_model_tree->setGeometry(QRect(model_tree->pos().x() + model_tree->width(), 0, 16, 16));
    show_hide_model_tree->setIconSize(QSize(show_hide_model_tree->size().width(), show_hide_model_tree->size().height()));
}

void MainWindow::modelTreeAnimation()
{
    float step = 0.1;
    if (is_model_tree_animation_dirrection_right)
    {
        float relationship = 1./0.3;
        model_tree_width_animation_percent += step;
        model_tree_height_animation_percent += step * relationship;
        model_tree->setGeometry(QRect(0, 0, window_width * model_tree_width_animation_percent, window_height * model_tree_height_animation_percent));
        show_hide_model_tree->setGeometry(QRect(model_tree->pos().x() + model_tree->width(), 0, 16, 16));
        show_hide_model_tree->setIconSize(QSize(show_hide_model_tree->size().width(), show_hide_model_tree->size().height()));

        if (model_tree_height_animation_percent >= 1.)
            model_tree_height_animation_percent = 1.;
        if (model_tree_width_animation_percent >= 0.3)
            model_tree_width_animation_percent = 0.3;
    }
    else
    {
        float relationship = 1./0.3;
        model_tree_width_animation_percent -= step;
        model_tree_height_animation_percent -= step * relationship;
        model_tree->setGeometry(QRect(0, 0, window_width * model_tree_width_animation_percent, window_height * model_tree_height_animation_percent));
        show_hide_model_tree->setGeometry(QRect(model_tree->pos().x() + model_tree->width(), 0, 16, 16));
        show_hide_model_tree->setIconSize(QSize(show_hide_model_tree->size().width(), show_hide_model_tree->size().height()));

        if (model_tree_height_animation_percent <= 0.)
            model_tree_height_animation_percent = 0.;
        if (model_tree_width_animation_percent <= 0.)
            model_tree_width_animation_percent = 0.;
    }

    if (model_tree_width_animation_percent == 0.)
    {
        timer->stop();
        model_tree->hide();
    }
    else
        model_tree->show();

    if (model_tree_width_animation_percent == model_tree_width_percent)
    {
        timer->stop();

        model_tree->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        model_tree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }
}

void MainWindow::on_show_hide_model_tree_clicked()
{
    model_tree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    model_tree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    is_model_tree_animation_dirrection_right = !is_model_tree_animation_dirrection_right;
    if (is_model_tree_animation_dirrection_right)
    {
        show_hide_model_tree_icon->addFile(QStringLiteral(":/Icons/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        show_hide_model_tree->setIcon(*show_hide_model_tree_icon);
    }
    else
    {
        show_hide_model_tree_icon->addFile(QStringLiteral(":/Icons/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        show_hide_model_tree->setIcon(*show_hide_model_tree_icon);
    }

    timer->start();
}
