#ifndef INCIDENTWIDGET_H
#define INCIDENTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QEnterEvent>
#include <QMouseEvent>

class IncidentWidget : public QFrame
{
    Q_OBJECT

public:
    // Updated constructor to include 'notes' parameter
    IncidentWidget(const QString& driver, const QString& incident, const QString& date, const QString& notes, QWidget* parent = nullptr);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();  // Signal to handle widget click

private:
    QLabel* nameLabel;
    QLabel* incidentLabel;
    QLabel* dateLabel;
    bool isHovered = false;

    void updateStyleSheet();
};

#endif // INCIDENTWIDGET_H
