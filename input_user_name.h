#ifndef INPUT_USER_NAME_H
#define INPUT_USER_NAME_H

#include <QDialog>
//#include "database_interface_for_admin.h"

namespace Ui {
class input_user_name;
}

class input_user_name : public QDialog
{
    Q_OBJECT

public:
    explicit input_user_name(QWidget *parent = nullptr);
    ~input_user_name();
signals:
    //void idEntered(int id_entered);
    void idEntered(int);
private slots:

    void on_lineEdit_input_id_returnPressed();

private:
    Ui::input_user_name *ui;
    //database_interface_for_admin *database_interface_for_admin;
};

#endif // INPUT_USER_NAME_H
