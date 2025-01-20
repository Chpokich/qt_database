#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Login = ui->lineEdit_1->text();
    QString Password = ui->lineEdit_2->text();

    if(Login == "test" && Password == "test"){
        QMessageBox::information(this, "login", "you sucsessfully sign in!");
        hide();
        Database_interface = new database_interface(this);
        Database_interface->show();

    }else{
        QMessageBox::warning(this, "login", "wrong login or password!");
    }
}

