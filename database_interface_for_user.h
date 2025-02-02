#ifndef DATABASE_INTERFACE_FOR_USER_H
#define DATABASE_INTERFACE_FOR_USER_H

#include <QDialog>
#include <qdebug.h>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


namespace Ui {
class database_interface_for_user;
}

class database_interface_for_user : public QDialog
{
    Q_OBJECT

public:
    explicit database_interface_for_user(QWidget *parent = nullptr);
    ~database_interface_for_user();

public slots:
    void slot_take_username_from_main(QString uname);

private slots:
    void model_handler();

private:
    Ui::database_interface_for_user *ui;
    QString user_name;
    QSqlTableModel *model;
    QSqlQuery *query;
};

#endif // DATABASE_INTERFACE_FOR_USER_H
