#include "linechartwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <algorithm>

LineChartWidget::LineChartWidget(QWidget *parent)
    : QWidget(parent) {}

void LineChartWidget::setMonthlyData(const QVector<int>& data) {
    monthlyData = data;
    update(); // Trigger a repaint
}

void LineChartWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::blue, 2));

    int padding = 10;
    int w = width() - 2 * padding;
    int h = height() - 2 * padding;

    if (monthlyData.isEmpty()) return;

    int maxDataValue = *std::max_element(monthlyData.begin(), monthlyData.end());
    double xStep = static_cast<double>(w) / (monthlyData.size() - 1);
    double yStep = static_cast<double>(h) / maxDataValue;

    for (int i = 0; i < monthlyData.size() - 1; ++i) {
        QPointF p1(padding + i * xStep, height() - padding - monthlyData[i] * yStep);
        QPointF p2(padding + (i + 1) * xStep, height() - padding - monthlyData[i + 1] * yStep);
        painter.drawLine(p1, p2);
    }
}
