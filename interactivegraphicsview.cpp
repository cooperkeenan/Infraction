#include "interactivegraphicsview.h"

InteractiveGraphicsView::InteractiveGraphicsView(QWidget *parent)
    : QGraphicsView(parent) {}

void InteractiveGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    QPointF point = mapToScene(event->pos());
    qDebug() << "Mouse hover at:" << point;
}

void InteractiveGraphicsView::mousePressEvent(QMouseEvent *event) {
    QPointF point = mapToScene(event->pos());
    qDebug() << "Mouse clicked at:" << point;
}
