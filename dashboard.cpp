#include "dashboard.h"
#include "ui_dashboard.h"
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QLabel>

dashboard::dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    QPixmap mapPixmap(":/images/uk_map.png");
    if (!mapPixmap.isNull()) {
        QPixmap scaledMap = mapPixmap.scaled(1600, 1300, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem* mapItem = scene->addPixmap(scaledMap);
        mapItem->setPos(0, 0);
        scene->setSceneRect(scaledMap.rect());
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    QVBoxLayout* layout = static_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    QStringList infractions = {"Speeding", "Red light crossing", "Illegal parking", "Unbuckled seatbelt", "Speeding", "Red light crossing", "Illegal parking", "Unbuckled seatbelt", "Speeding", "Red light crossing", "Illegal parking", "Unbuckled seatbelt"};
    foreach (const QString &infraction, infractions) {
        QLabel* label = new QLabel(infraction, ui->scrollAreaWidgetContents);
        layout->addWidget(label);
    }

    QList<QPair<QString, QPointF>> depots = {
        {"London", QPointF(400, 1100)},
        {"Manchester", QPointF(290, 700)},
        {"Birmingham", QPointF(300, 900)}
    };

    foreach (const auto &depot, depots) {
        QGraphicsTextItem* label = scene->addText(depot.first);
        label->setPos(depot.second);
        label->setDefaultTextColor(Qt::white);
        QFont labelFont = label->font();
        labelFont.setPointSize(20);
        labelFont.setBold(true);
        label->setFont(labelFont);
    }

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(48, 48, 48)));
}

void dashboard::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    if (scene && !scene->sceneRect().isEmpty()) {
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

dashboard::~dashboard()
{
    delete ui;
}
