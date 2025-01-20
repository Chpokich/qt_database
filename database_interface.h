#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <QDialog>

namespace Ui {
class database_interface;
}

class database_interface : public QDialog
{
    Q_OBJECT

public:
    explicit database_interface(QWidget *parent = nullptr);
    ~database_interface();

private:
    Ui::database_interface *ui;
};

#endif // DATABASE_INTERFACE_H
