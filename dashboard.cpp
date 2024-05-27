#include "dashboard.h"
#include "ui_dashboard.h"
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QFont>

dashboard::dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    // Load and display the map image
    QPixmap mapPixmap(":/images/uk_map.png");
    QPixmap scaledMap = mapPixmap.scaled(1600, 1300, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem* mapItem = scene->addPixmap(scaledMap);
    mapItem->setPos(0, 0);

    // Set the initial scene rectangle
    scene->setSceneRect(scaledMap.rect());
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    // Example depot data
    QList<QPair<QString, QPointF>> depots = {
        {"London", QPointF(400, 400)},
        {"Manchester", QPointF(400, 500)},
        {"Birmingham", QPointF(400, 900)}
    };

    // Add labels for each depot
    for (const auto &depot : depots) {
        QGraphicsTextItem* label = scene->addText(depot.first);
        label->setPos(depot.second);
        label->setDefaultTextColor(Qt::white);

        // Create and set the font for the label
        QFont labelFont = label->font();
        labelFont.setPointSize(20);  // Set the font size to 12 points
        labelFont.setBold(true);     // Optionally make the text bold
        label->setFont(labelFont);
    }

    // Set the QGraphicsView properties
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(48, 48, 48)));
}

dashboard::~dashboard()
{
    delete ui;
}

void dashboard::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    if (scene && !scene->sceneRect().isEmpty()) {
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}


