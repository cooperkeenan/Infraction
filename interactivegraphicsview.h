#ifndef INTERACTIVEGRAPHICSVIEW_H
#define INTERACTIVEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>

class InteractiveGraphicsView : public QGraphicsView {
public:
    InteractiveGraphicsView(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // INTERACTIVEGRAPHICSVIEW_H
