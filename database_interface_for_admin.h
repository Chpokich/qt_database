#ifndef DATABASE_INTERFACE_FOR_ADMIN_H
#define DATABASE_INTERFACE_FOR_ADMIN_H

#include <QDialog>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QTextEdit>
#include "input_user_name.h"

namespace Ui {
class database_interface_for_admin;
}

class database_interface_for_admin : public QDialog
{
    Q_OBJECT

public:
    int take_id;
    explicit database_interface_for_admin(QWidget *parent = nullptr);
    ~database_interface_for_admin();
public slots:
    void on_id_entered(int id_intered);
private slots:

    void on_pushButton_show_drivers_info_clicked();

    void on_pushButton_delete_row_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_add_row_clicked();

    void on_pushButton_back_authorization_clicked();

    void on_pushButton_show_auto_park_info_clicked();

    void on_pushButton_show_auto_info_clicked();

    void on_pushButton_show_service_info_clicked();

    void on_pushButton_show_station_info_clicked();

    void on_pushButton_show_intermediate_stations_info_clicked();

    void on_pushButton_show_ways_info_clicked();

    void on_pushButton_authorization_clicked();

    void on_pushButton_show_all_info_clicked();

private:
    Ui::database_interface_for_admin *ui;
    QSqlTableModel *model;
    int current_row;
    QSqlQuery *query;
    QLineEdit *lineEdit;
    input_user_name *Input_user_name;
};

#endif // DATABASE_INTERFACE_FOR_ADMIN_H
