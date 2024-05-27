#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>
#include <QDebug>  // For debugging
#include <QCoreApplication>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    dashboardWidget(new dashboard(this))  // Initialize the dashboard widget
{
    ui->setupUi(this);

    // Connect the continue button to the slot
    connect(ui->btn_continue, &QPushButton::clicked, this, &MainWindow::on_btn_continue_clicked);
    // Connect the login button to the slot
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);

    // Optionally hide the dashboard initially or setup accordingly
    dashboardWidget->hide();  // If you want to add it directly to the main window later
    // If using a QStackedWidget, you might add the dashboard to the stack:
    ui->stackedWidget->addWidget(dashboardWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//Attempt to connect to database
void MainWindow::on_btn_connectDB_clicked()
{
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).filePath("../Resources/db/InfractionDB.sqlite");
    qDebug() << "Database path:" << dbPath;
    sqlitedb.setDatabaseName(dbPath);

    QFile dbFile(dbPath);
    if (!dbFile.exists()) {
        qDebug() << "Database file does not exist:" << dbPath;
    } else {
        qDebug() << "Database file found:" << dbPath;
    }


    if (!sqlitedb.open()) {
        QMessageBox::information(this, "Not Connected", "Database Not Connected");
    } else {
        QMessageBox::information(this, "Connected", "Database is connected successfully");
    }
}


//Continue to Sign in
void MainWindow::on_btn_continue_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


//Sign in Function
void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        qDebug() << "Displaying input error message box";
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM managers WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Displaying query error message box";
        QMessageBox::critical(this, "Error", "Failed to execute query: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        qDebug() << "Displaying success message box";
        // Proceed to the next page or perform other actions
        ui->stackedWidget->setCurrentWidget(dashboardWidget);
    } else {
        qDebug() << "Displaying incorrect credentials message box";
        QMessageBox::warning(this, "Failed", "Incorrect username or password.");
    }
}
