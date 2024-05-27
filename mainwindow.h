#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "dashboard.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_connectDB_clicked();
    void on_btn_continue_clicked();  // Ensure this matches the implementation
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase sqlitedb;
    dashboard *dashboardWidget;
};
#endif // MAINWINDOW_H
