#include "database_interface_for_user.h"
#include "ui_database_interface_for_user.h"

void database_interface_for_user::slot_take_username_from_main(QString uname)
{
    qDebug()<<"slot_username ON";
    qDebug()<<"uname = "<<uname;
    this->user_name = uname;
    qDebug()<<"this->user_name = "<<this->user_name;
    qDebug()<<"slot_username OFF";
     model_handler();
}

database_interface_for_user::database_interface_for_user(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::database_interface_for_user)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database();
    query = new QSqlQuery(db);
    model = new QSqlTableModel(this,db);
}

database_interface_for_user::~database_interface_for_user()
{
    delete ui;
}

void database_interface_for_user::model_handler()
{
    qDebug()<<"model_handler RUN";
    query->prepare("SELECT "
                  "a.id AS auth_id, "
                  "a.login, "
                  "a.user_type, "
                  "d.id AS driver_id, "
                  "d.\"Фамилия \", "  // Пробел в конце
                  "d.\"Имя\", "
                  "d.\"Отчество \", "  // Пробел в конце
                  "d.\"Возраст\", "
                  "d.\"Пол\", "
                  "d.\"Рабочие_дни\", "
                  "r.id AS route_id, "
                  "r.\"Номер_маршрута\", "
                  "r.\"Время_движения\", "
                  "o.id AS stop_id, "
                  "o.\"Отправление\", "
                  "o.\"Прибытие\", "
                  "o.\"Пункт_отправления\", "
                  "o.\"Пункт_прибытия\" "
                  "FROM "
                  "course_work.\"authorization\" a "
                  "LEFT JOIN "
                  "course_work.\"Водители\" d ON a.id = d.authorization_id "
                  "LEFT JOIN "
                  "course_work.\"Маршрут\" r ON a.id = r.authorization_id "
                  "LEFT JOIN "
                  "course_work.\"Остановки\" o ON r.id = o.\" marshrut_id\" "
                  "WHERE "
                  "a.login = :login");

     query->bindValue(":login", this->user_name);

    if(query->exec()){
        qDebug()<<"query run sucsessful!";
        model->setQuery(*query);
    }else{
        qDebug()<<"query ERROR!"<<query->lastError();
    }
    ui->tableView->setModel(model);
}


