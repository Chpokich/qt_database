#include "database_interface.h"
#include "ui_database_interface.h"

database_interface::database_interface(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::database_interface)
{
    ui->setupUi(this);
}

database_interface::~database_interface()
{
    delete ui;
}
