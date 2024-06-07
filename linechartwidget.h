#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include <QWidget>
#include <QVector>

class LineChartWidget : public QWidget {
    Q_OBJECT

public:
    explicit LineChartWidget(QWidget *parent = nullptr);

    void setMonthlyData(const QVector<int> &data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<int> monthlyData;
};

#endif // LINECHARTWIDGET_H
