#include "dashboard.h"
#include "ui_dashboard.h"
#include "incidentwidget.h"
#include "infractionwidget.h"
#include "linechartwidget.h"

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>

dashboard::dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    // Set background color and shadow effect for graphicsView
    ui->graphicsView->setStyleSheet("background-color: #1E232B; border-radius: 10px;");
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(ui->graphicsView);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(5);
    shadowEffect->setYOffset(5);
    shadowEffect->setColor(QColor(0, 0, 0, 150));
    ui->graphicsView->setGraphicsEffect(shadowEffect);

    // Container widget for all infraction display components
    QWidget *containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    // Create and style the title label
    QLabel *titleLabel = new QLabel("Infraction Count");
    titleLabel->setAlignment(Qt::AlignLeft);
    titleLabel->setStyleSheet("font-size: 24px; color: white; margin-top: 10px; margin-bottom: 5px;");
    containerLayout->addWidget(titleLabel, 0, Qt::AlignLeft);

    // Setup Search Bar
    ui->lbl_searchDriver->setPlaceholderText("Search Driver");

    // Horizontal layout for infraction widgets
    QHBoxLayout *hLayout = new QHBoxLayout();
    InfractionWidget *monthlyInfractions = new InfractionWidget("Month", containerWidget);
    InfractionWidget *weeklyInfractions = new InfractionWidget("Week", containerWidget);
    monthlyInfractions->setInfractions(32);
    weeklyInfractions->setInfractions(8);

    hLayout->addWidget(monthlyInfractions);
    hLayout->addWidget(weeklyInfractions);
    containerLayout->addLayout(hLayout);

    // Adding the entire container to the right cell of the grid layout
    QGridLayout *gridLayout = ui->page->findChild<QGridLayout*>("gridLayout");
    if(gridLayout) {
        gridLayout->addWidget(containerWidget, 1, 4, Qt::AlignTop); // Adjust grid position according to your layout
    } else {
        qDebug() << "Grid layout not found!";
    }

    // Setup the map
    QPixmap mapPixmap(":/images/uk_map.png");
    if (!mapPixmap.isNull()) {
        QPixmap scaledMap = mapPixmap.scaled(1600, 1300, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem* mapItem = scene->addPixmap(scaledMap);
        mapItem->setPos(0, 0);
        scene->setSceneRect(scaledMap.rect());
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    // Add city labels with infraction counts
    QList<QPair<QString, QPointF>> depots = {
        {"London", QPointF(400, 1100)},
        {"Manchester", QPointF(400, 700)},
        {"Birmingham", QPointF(300, 900)}
    };

    QList<int> infractionCounts = {12, 15, 8};  // Example infraction counts for each depot

    for (int i = 0; i < depots.size(); ++i) {
        const auto &depot = depots[i];
        QGraphicsTextItem* label = scene->addText(depot.first);
        label->setPos(depot.second);
        label->setDefaultTextColor(Qt::white);
        QFont labelFont = label->font();
        labelFont.setPointSize(20);
        labelFont.setBold(true);
        label->setFont(labelFont);

        // Add infraction count label
        QGraphicsTextItem* infractionLabel = scene->addText(QString::number(infractionCounts[i]));
        infractionLabel->setPos(depot.second + QPointF(50, 20));  // Adjust position as needed
        infractionLabel->setDefaultTextColor(Qt::red);
        QFont infractionFont = infractionLabel->font();
        infractionFont.setPointSize(20);
        infractionFont.setBold(true);
        infractionLabel->setFont(infractionFont);
    }

    // Setup the incidents area
    QVBoxLayout* incidentsLayout = static_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (!incidentsLayout) {
        incidentsLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    }

    QList<IncidentInfo> incidents = {
        {"John Doe", "Speeding", "2024-05-31", "Exceeded speed limit by 15 mph in a residential zone."},
        {"Jane Smith", "Red light crossing", "2024-05-30", "Crossed intersection during red light at Main St."},
        {"Jim Beam", "Illegal parking", "2024-05-29", "Parked in a no-parking zone outside of shopping mall."}
    };

    foreach (const IncidentInfo &incident, incidents) {
        IncidentWidget* widget = new IncidentWidget(incident.driver, incident.incident, incident.date, incident.notes, this);
        incidentsLayout->addWidget(widget);
    }

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(30, 35, 43)));

    // Add Line Chart Widget to the layout
    LineChartWidget *lineChart = new LineChartWidget(this);
    lineChart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineChart->setFixedHeight(200); // Adjust the height as needed
    QVector<int> monthlyData = {12, 15, 8, 7, 10, 20, 30, 25, 18, 22, 5, 13}; // Example data
    lineChart->setMonthlyData(monthlyData);
    gridLayout->addWidget(lineChart, 2, 4, 1, 2, Qt::AlignTop); // Position the line chart in the grid layout
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

void dashboard::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
}
