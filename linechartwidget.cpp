#include "linechartwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QStringList>
#include <QDebug>
#include <algorithm>

LineChartWidget::LineChartWidget(QWidget *parent)
    : QWidget(parent) {}

void LineChartWidget::setMonthlyData(const QVector<int>& data) {
    monthlyData = data;
    update(); // Trigger a repaint
}

void LineChartWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    qDebug() << "Paint event called";

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int padding = 40; // Increase padding to make space for labels
    int w = width() - 2 * padding;
    int h = height() - 2 * padding;

    if (monthlyData.isEmpty()) {
        qDebug() << "Monthly data is empty";
        return;
    }

    int maxDataValue = *std::max_element(monthlyData.begin(), monthlyData.end());
    double xStep = static_cast<double>(w) / (monthlyData.size() - 1);
    double yStep = static_cast<double>(h) / maxDataValue;

    // Draw the line graph
    painter.setPen(QPen(QColor("#0072C0"), 2));
    for (int i = 0; i < monthlyData.size() - 1; ++i) {
        QPointF p1(padding + i * xStep, height() - padding - monthlyData[i] * yStep);
        QPointF p2(padding + (i + 1) * xStep, height() - padding - monthlyData[i + 1] * yStep);
        painter.drawLine(p1, p2);
    }

    // Draw the x-axis labels (months)
    QStringList months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    painter.setPen(QPen(Qt::white, 1));
    for (int i = 0; i < monthlyData.size(); ++i) {
        int x = padding + i * xStep;
        int y = height() - padding + 20;
        painter.drawText(x - 10, y, months[i]);  // Adjust position as needed
    }

    // Draw the y-axis labels (values)
    int step = maxDataValue / 5;
    for (int i = 0; i <= maxDataValue; i += step) {
        int y = height() - padding - i * yStep;
        painter.drawText(5, y + 5, QString::number(i));  // Adjust position as needed
    }

    // Draw axes
    painter.setPen(QPen(Qt::white, 1));
    painter.drawLine(padding, height() - padding, width() - padding, height() - padding);  // X-axis
    painter.drawLine(padding, padding, padding, height() - padding);  // Y-axis
}
