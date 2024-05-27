#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QGraphicsScene>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class dashboard; }
QT_END_NAMESPACE

class dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::dashboard *ui;
    QGraphicsScene *scene;
};

#endif // DASHBOARD_H
