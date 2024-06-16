#include "infractionwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPainterPath>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

InfractionWidget::InfractionWidget(const QString& label, QWidget *parent) : QFrame(parent), infractions(0), m_label(label) {
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    setStyleSheet("background-color: #1E232B; border-radius: 7px;");

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(7);
    shadowEffect->setYOffset(7);
    shadowEffect->setColor(QColor(0, 0, 0, 150));
    setGraphicsEffect(shadowEffect);

    setupUI();
}

void InfractionWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Specific label for this widget
    QLabel *labelWidget = new QLabel(m_label, this);
    labelWidget->setAlignment(Qt::AlignCenter);
    labelWidget->setStyleSheet("font-size: 16px; color: white; background-color: transparent;"); // Use transparent background
    layout->addWidget(labelWidget, 0, Qt::AlignBottom);

    setLayout(layout);
}

int InfractionWidget::getInfractions() const {
    return infractions;
}

void InfractionWidget::setInfractions(int newInfractions) {
    if (infractions == newInfractions)
        return;
    infractions = newInfractions;
    emit infractionsChanged();
    update();  // Cause a repaint with the new infraction count
}

void InfractionWidget::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw rounded rectangle background
    QPainterPath path;
    path.addRoundedRect(rect(), 10, 10); // 10 radius for rounded corners
    painter.fillPath(path, QColor("#1E232B"));  // Use the same background color as set in the stylesheet

    // Draw the ring
    QPen pen(QColor("#0072C0"), 10, Qt::SolidLine, Qt::FlatCap);  // Set pen width to 10 for the ring
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);  // Ensure it's only an outline

    // Calculate the radius based on widget size
    int radius = qMin(width(), height()) / 4;
    QPoint center(width() / 2, height() / 2 - 10);
    QRectF circleRect(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);

    // Draw the full circle for count representation
    painter.drawEllipse(circleRect);

    // Draw the infraction count text
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 24, QFont::Bold));
    painter.drawText(circleRect, Qt::AlignCenter, QString::number(infractions));
}
