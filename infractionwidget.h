#ifndef INFRACTIONWIDGET_H
#define INFRACTIONWIDGET_H

#include <QWidget>
#include <QFrame>

class InfractionWidget : public QFrame {
    Q_OBJECT
    Q_PROPERTY(int infractions READ getInfractions WRITE setInfractions NOTIFY infractionsChanged)

public:
    explicit InfractionWidget(const QString& label, QWidget *parent = nullptr);
    int getInfractions() const;
    void setInfractions(int newInfractions);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void infractionsChanged();

private:
    int infractions;
    QString m_label;

    void setupUI();
};

#endif // INFRACTIONWIDGET_H
