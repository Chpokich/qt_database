#include "input_user_name.h"
#include "ui_input_user_name.h"

input_user_name::input_user_name(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::input_user_name)
{
    ui->setupUi(this);
    //Database_interface_for_admin = new database_interface_for_admin(this);
    //connect(Input_user_name, &input_user_name::idEntered, this, &database_interface_for_admin::on_id_entered);
}

input_user_name::~input_user_name()
{
    delete ui;
}


void input_user_name::on_lineEdit_input_id_returnPressed()
{
    int id_entered = 0;
    qDebug()<<"START input_user_name";
    //database_interface_for_admin *adm = new database_interface_for_admin(this);
    id_entered = ui->lineEdit_input_id->text().toInt();
    qDebug()<<"take_id in input_user_name = "<<id_entered;
    //void idEntered(int id_entered);
    emit idEntered(id_entered);
    //this->close();
    qDebug()<<"END input_user_name";
    this->close();
}

