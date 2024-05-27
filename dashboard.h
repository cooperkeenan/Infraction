#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

namespace Ui {
class dashboard;  // This is a forward declaration for the namespace Ui that the UIC generates.
}

class dashboard : public QWidget {
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private:
    Ui::dashboard *ui;  // Pointer to the generated UI class
};

#endif // DASHBOARD_H
