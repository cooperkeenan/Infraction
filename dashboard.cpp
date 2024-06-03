#include "dashboard.h"
#include "ui_dashboard.h"
#include "incidentwidget.h"
#include "infractionwidget.h"

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QVBoxLayout>

dashboard::dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);


    //Set up infraction counter container
    QWidget *containerWidget = ui->widgetContainer;
    if (containerWidget) {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(containerWidget->layout());

        InfractionWidget* infractionDisplay = new InfractionWidget(this);
        infractionDisplay->setInfractions(32);  // Example setting an initial value

        // Setup the shadow effect
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(infractionDisplay);
        shadowEffect->setBlurRadius(15);
        shadowEffect->setXOffset(5);
        shadowEffect->setYOffset(5);
        shadowEffect->setColor(QColor(0, 0, 0, 150));
        infractionDisplay->setGraphicsEffect(shadowEffect);

        layout->addWidget(infractionDisplay);

    } else {
        qDebug() << "widgetContainer not found!";
    }


    //Setup up map graphics view
    QPixmap mapPixmap(":/images/uk_map.png");
    if (!mapPixmap.isNull()) {
        QPixmap scaledMap = mapPixmap.scaled(1600, 1300, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem* mapItem = scene->addPixmap(scaledMap);
        mapItem->setPos(0, 0);
        scene->setSceneRect(scaledMap.rect());
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    // Assuming QVBoxLayout is properly setup in your UI Designer
    QVBoxLayout* layout = static_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    }

    // Example data in dashboard.cpp where IncidentInfo is used
    QList<IncidentInfo> incidents = {
        {"John Doe", "Speeding", "2024-05-31", "Exceeded speed limit by 15 mph in a residential zone."},
        {"Jane Smith", "Red light crossing", "2024-05-30", "Crossed intersection during red light at Main St."},
        {"Jim Beam", "Illegal parking", "2024-05-29", "Parked in a no-parking zone outside of shopping mall."}
    };

    foreach (const IncidentInfo &incident, incidents) {
        IncidentWidget* widget = new IncidentWidget(incident.driver, incident.incident, incident.date, incident.notes, this);
        layout->addWidget(widget);
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
