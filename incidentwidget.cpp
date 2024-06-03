#include "incidentwidget.h"
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QDebug>

void IncidentWidget::updateStyleSheet()
{
    QString baseStyle = "QFrame {"
                        " padding: 10px;"
                        " border-radius: 8px;"  // Rounded corners
                        " border: 0px solid #444;"  // Single border for the whole widget
                        " background-color: %1;"   // Background color
                        " color: #EEE;"            // Light text for contrast
                        " box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);"  // Subtle shadow for depth
                        "}";
    QString bgColor = isHovered ? "#313745" : "#2A2F3A";  // Slightly lighter on hover
    setStyleSheet(baseStyle.arg(bgColor));
}

// Constructor setup
// Assuming each IncidentInfo structure might also have a 'notes' field
struct IncidentInfo {
    QString driver;
    QString incident;
    QString date;
    QString notes;  // Additional field for notes
};

// Update constructor to include notes
IncidentWidget::IncidentWidget(const QString& driver, const QString& incident, const QString& date, const QString& notes, QWidget* parent)
    : QFrame(parent), isHovered(false)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);

    nameLabel = new QLabel("Driver: " + driver, this);
    incidentLabel = new QLabel("Incident: " + incident, this);
    dateLabel = new QLabel("Date: " + date, this);
    QLabel* notesLabel = new QLabel("Notes: " + notes, this);

    nameLabel->setStyleSheet("font-size: 16pt; font-weight: bold; color: #FFF; padding: 5px; background: transparent;");
    incidentLabel->setStyleSheet("font-size: 14pt; color: #AAA; padding: 5px; background: transparent;");
    dateLabel->setStyleSheet("font-size: 16pt; color: #AAA; padding: 5px; background: transparent;");
    notesLabel->setStyleSheet("font-size: 14pt; color: #CCC; padding: 5px; background: transparent;");

    layout->addWidget(nameLabel);
    layout->addWidget(incidentLabel);
    layout->addWidget(dateLabel);
    layout->addWidget(notesLabel);

    setLayout(layout);
    updateStyleSheet();


    // Apply drop shadow effect
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(5);
    shadowEffect->setXOffset(3);
    shadowEffect->setYOffset(3);
    shadowEffect->setColor(Qt::black);
    setGraphicsEffect(shadowEffect);
}




void IncidentWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}

void IncidentWidget::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    isHovered = true;
    updateStyleSheet();
}

void IncidentWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    isHovered = false;
    updateStyleSheet();
}
