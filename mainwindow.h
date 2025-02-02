#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include "database_interface_for_user.h"
#include "database_interface_for_admin.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

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
signals:
    void signal_username_to_ui(QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    database_interface_for_admin* Database_interface_for_admin;
    database_interface_for_user* Database_interface_for_user;
    //QSqlTableModel *model;
    QSqlQuery *query;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
