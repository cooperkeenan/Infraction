// infractionwidget.cpp
#include "infractionwidget.h"
#include <QPainter>
#include <QPaintEvent>

InfractionWidget::InfractionWidget(QWidget *parent) : QWidget(parent), infractions(0)
{
    // Set the size of the widget
    setMinimumSize(200, 200);
}

int InfractionWidget::getInfractions() const
{
    return infractions;
}

void InfractionWidget::setInfractions(int newInfractions)
{
    if (infractions == newInfractions)
        return;
    infractions = newInfractions;
    emit infractionsChanged();
    update();  // Cause a repaint with the new infraction count
}

void InfractionWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Background
    painter.fillRect(rect(), QColor("#303030"));  // Set to the same grey as your interface

    // Draw the ring
    QPen pen(QColor("#FF0000"), 10, Qt::SolidLine, Qt::FlatCap);  // Set pen width to 10 for the ring
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);  // Ensure it's only an outline

    // Calculate the radius based on widget size
    int radius = qMin(width(), height()) / 4;
    QPoint center(width() / 2, height() / 2);
    painter.drawEllipse(center, radius, radius);

    // Draw the infraction count text
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 24, QFont::Bold));
    painter.drawText(rect(), Qt::AlignCenter, QString::number(infractions));  // Corrected from m_infractions to infractions
}

