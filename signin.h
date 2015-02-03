#ifndef SIGNIN_H
#define SIGNIN_H
#include "login.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

#include <QDialog>
#include "oneplayergame.h"
#include <QString>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();

private slots:
    //void on_buttonBox_accepted();

    //void on_buttonBox_rejected();

    void on_onePlayerButton_clicked();

    void on_tenButton_clicked();

    void on_nextButton_clicked();

    void on_cancelSignIn_clicked();

    void on_startButton_clicked();

private:
    Ui::SignIn *ui;
    login* playerLogin;
    QSqlDatabase mydb;
    onePlayerGame* aiGame;
    QString name;
    QString email;
    QString country;
    QString confpswd;
    QString pswd;
    int age;

};

#endif // SIGNIN_H
