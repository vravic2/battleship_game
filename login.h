#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "oneplayergame.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    QSqlDatabase mydb;
    onePlayerGame* aiGame;
    QString name;
    QString email;
    QString country;
    QString gmode;
    int age;
};

#endif // LOGIN_H
