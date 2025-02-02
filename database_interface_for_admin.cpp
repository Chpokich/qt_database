#include "database_interface_for_admin.h"
#include "ui_database_interface_for_admin.h"

database_interface_for_admin::database_interface_for_admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::database_interface_for_admin)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database();
    model = new QSqlTableModel(this, db);
    query = new QSqlQuery(db);
    Input_user_name = new input_user_name(this);
}

database_interface_for_admin::~database_interface_for_admin()
{
    delete ui;
    delete model;
    model = nullptr;
    delete query;
    query = nullptr;
    delete Input_user_name;
    Input_user_name = nullptr;
}

void database_interface_for_admin::on_pushButton_back_authorization_clicked()
{
    this->close();
    parentWidget()->show();
}


void database_interface_for_admin::on_pushButton_show_drivers_info_clicked()
{
    model->setTable("course_work.Водители");
    //model->setQuery("select ФИО from course_work.Водители");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_delete_row_clicked()
{
    model->removeRow(current_row);
}


void database_interface_for_admin::on_tableView_clicked(const QModelIndex &index)
{
    current_row = index.row();
}


void database_interface_for_admin::on_pushButton_add_row_clicked()
{
    model->insertRow(model->rowCount());
}


void database_interface_for_admin::on_pushButton_show_auto_park_info_clicked()
{
    model->setTable("course_work.Автопарк");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_show_auto_info_clicked()
{
    model->setTable("course_work.Транспорт");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_show_service_info_clicked()
{
    model->setTable("course_work.Обслуживание");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_show_station_info_clicked()
{
    model->setTable("course_work.Остановки");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_show_intermediate_stations_info_clicked()
{
    model->setTable("course_work.Промежуточные_остановки");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_show_ways_info_clicked()
{
    model->setTable("course_work.Маршрут");
    model->select();
    ui->tableView->setModel(model);
}


void database_interface_for_admin::on_pushButton_authorization_clicked()
{
    model->setTable("course_work.authorization");
    model->select();
    ui->tableView->setModel(model);
}

void database_interface_for_admin::on_id_entered(int id_entered)
{
    qDebug()<<"slot_id_entered ON";
    this->take_id = id_entered;
}


void database_interface_for_admin::on_pushButton_show_all_info_clicked()
{
    qDebug()<<"START database_interface_for_admin";
    connect(Input_user_name, &input_user_name::idEntered, this, &database_interface_for_admin::on_id_entered);
    Input_user_name->exec();
    query->prepare("SELECT "
                   "a.id AS auth_id, a.login, a.user_type, "
                   "d.id AS driver_id, d.\"Фамилия \", d.\"Имя\", d.\"Отчество \", d.\"Возраст\", d.\"Пол\", d.\"Рабочие_дни\", "
                   "r.id AS route_id, r.\"Номер_маршрута\", r.\"Время_движения\", "
                   "o.id AS stop_id, o.\"Отправление\", o.\"Прибытие\", o.\"Пункт_отправления\", o.\"Пункт_прибытия\" "
                   "FROM course_work.\"authorization\" a "
                   "LEFT JOIN course_work.\"Водители\" d ON a.id = d.authorization_id "
                   "LEFT JOIN course_work.\"Маршрут\" r ON a.id = r.authorization_id "
                   "LEFT JOIN course_work.\"Остановки\" o ON r.id = o.\" marshrut_id\" "
                   "WHERE a.id = :id;");

    query->bindValue(":id", this->take_id);  // Подставьте нужный ID
    qDebug()<<"take_id in admin = "<<this->take_id;
    if (query->exec()) {
        // Если запрос выполнен успешно, связываем модель с результатом
        model->setQuery(*query);
    } else {
        // В случае ошибки выводим сообщение
        qDebug() << "Query execution failed: "; // << query->lastError();
    }
    //model->setQuery(*query);
    //model->select();
    ui->tableView->setModel(model);
    qDebug()<<"STOP database_interface_for_admin";
    //query->exec();

}

