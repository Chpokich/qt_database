#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("db2092_03");
    db.setHostName("172.20.7.54");
    db.setPort(5432);
    db.setUserName("st2092");
    db.setPassword("pwd_2092");
    qDebug() << QSqlDatabase::drivers();

    Database_interface_for_user = new database_interface_for_user(this);

    //slot connects

    qDebug()<<"connect func START";
    connect(this, &MainWindow::signal_username_to_ui, Database_interface_for_user, &database_interface_for_user::slot_take_username_from_main);
    qDebug()<<"connect func END";



    if (!db.open())
    {
        QString errorMessage = db.lastError().text();  // Получаем описание ошибки
        QMessageBox::warning(this, "Ошибка подключения", "Не удалось подключиться: " + errorMessage);
    } else {
        QMessageBox::warning(this, "Успех", "Подключение успешно!"); 
    }

    query = new QSqlQuery(db);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString query_login;
    QString query_password;
    QString query_user_type;

    QString user_type_user = "user";
    QString user_type_admin = "admin";
    uint8_t counter_error = 0;
    query->prepare("SELECT login, password, user_type FROM course_work.authorization");

    if (query->exec()) {
        // Если запрос выполнен успешно
        QMessageBox::information(this, "Успех", "Запрос выполнен успешно!");

        // Чтение данных
        while (query->next()) {
             query_login = query->value(0).toString();
             query_password = query->value(1).toString();
             query_user_type = query->value(2).toString();
             qDebug() << "Login: " << query_login << ", Password: " << query_password << ", User_type: " << query_user_type;

             QString Login = ui->lineEdit_1->text();
             QString Password = ui->lineEdit_2->text();

             if(Login == query_login && Password == query_password){
                 if(query_user_type == user_type_admin){
                     QMessageBox::information(this, "login", "you sucsessfully sign in!");
                     hide();
                     Database_interface_for_admin = new database_interface_for_admin(this);
                     Database_interface_for_admin->show();
                     counter_error = 0;
                     break;
                 }else if(query_user_type == user_type_user){
                     QMessageBox::information(this, "login", "you sucsessfully sign in!");
                     //connect(this, &MainWindow::signal_username_to_ui, Database_interface_for_user, &database_interface_for_user::slot_take_username_from_main);
                     qDebug()<<"login = "<<Login;
                     emit signal_username_to_ui(Login);
                     hide();
                     //Database_interface_for_user = new database_interface_for_user(this);
                     Database_interface_for_user->show();
                     counter_error = 0;
                     break;
                 }else{
                     QMessageBox::warning(this, "auth", "something went wrong with user type in database!");
                     break;
                 }


             }else{
                 counter_error++;
             }
        }
        if(counter_error > 0){
            QMessageBox::warning(this, "login", "wrong login or password!");
        }
    } else {
        // Если запрос не выполнен
        QString errorMessage = query->lastError().text();
        QMessageBox::information(this, "Ошибка", "Ошибка выполнения запроса: " + errorMessage);
    }


}

