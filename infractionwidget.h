// infractionwidget.h
#ifndef INFRACTIONWIDGET_H
#define INFRACTIONWIDGET_H

#include <QWidget>

class InfractionWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int infractions READ getInfractions WRITE setInfractions NOTIFY infractionsChanged)

public:
    explicit InfractionWidget(QWidget *parent = nullptr);
    int getInfractions() const;
    void setInfractions(int newInfractions);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void infractionsChanged();

private:
    int infractions;
};

#endif // INFRACTIONWIDGET_H
