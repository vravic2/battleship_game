#include "signin.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    ui->tenButton->hide();
    ui->fifteenButton->hide();
    ui->twentyButton->hide();
    ui->spinBox->setMaximum(99);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setValue(10);
    ui->name_box->setMaxLength(25);
    ui->countryBox->setMaxLength(25);
    ui->emailBox->setMaxLength(25);
    ui->onePlayerButton->hide();
    ui->twoPlayerButton->hide();
    ui->buttonBox->hide();
    ui->startButton->hide();

}

SignIn::~SignIn()
{
    delete ui;
}

/*void SignIn::on_buttonBox_accepted()
{
    name = ui->name_box->text();
    email = ui->emailBox->text();
    country = ui->countryBox->text();
    age = ui->spinBox->value();
    if(name.length() > 0){
        ui->buttonBox->hide();
        ui->countryBox->hide();
        ui->emailBox->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->name_box->hide();
        ui->spinBox->hide();

        ui->tenButton->show();
        ui->fifteenButton->show();
        ui->twentyButton->show();
    }
}*/

/*void SignIn::on_buttonBox_rejected()
{
    this->destroy();
}*/

void SignIn::on_onePlayerButton_clicked()
{
    ui->onePlayerButton->hide();
    ui->twoPlayerButton->hide();
    ui->startButton->show();

}

void SignIn::on_tenButton_clicked()
{
    ui->tenButton->hide();
    ui->fifteenButton->hide();
    ui->twentyButton->hide();

    /*ui->buttonBox->show();
    ui->countryBox->show();
    ui->emailBox->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->name_box->show();
    ui->spinBox->show();*/
    ui->onePlayerButton->show();
    ui->twoPlayerButton->show();

}

void SignIn::on_nextButton_clicked()
{

    //saving all the values in database.
    name = ui->name_box->text();
    email = ui->emailBox->text();
    country = ui->countryBox->text();
    age = ui->spinBox->value();
    pswd = ui->pswd_box->text();
    confpswd = ui->confirm_pswd->text();
    if(name.length() > 0 && pswd.length() > 0 && confpswd==pswd){
        ui->buttonBox->hide();
        ui->confirm_pswd->hide();
        ui->countryBox->hide();
        ui->emailBox->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_7->hide();
        ui->name_box->hide();
        ui->spinBox->hide();
        ui->pswd_box->hide();

        ui->tenButton->show();
        ui->fifteenButton->show();
        ui->twentyButton->show();
        ui->nextButton->hide();
    }
    else if(name.length() < 0)
   ui->label->setStyleSheet("color: red");
    else if(pswd.length() < 0)
   ui->label_5->setStyleSheet("color: red");

      else
      {
          ui->label_5->setStyleSheet("color: red");
          ui->label_7->setStyleSheet("color: red");
      }
    }



void SignIn::on_cancelSignIn_clicked()
{
    this->destroy();
}

void SignIn::on_startButton_clicked()
{
    QSqlDatabase mydbs = QSqlDatabase::addDatabase("QSQLITE");
     mydbs.setDatabaseName("C:/Users/vravic2/Downloads/Chinook_Sqlite.sqlite");
     QString password;
     name = ui->name_box->text();
     password = ui->pswd_box->text();
     email = ui->emailBox->text();
     country = ui->countryBox->text();
     age = ui->spinBox->value();

     if(mydbs.open())
        ui->label_6->setText("connected to DB but");
     else
        ui->label_6->setText("Connection failure");

     QSqlQuery query;
          query.prepare("INSERT INTO Players (username, pswd, Age, Email, Country) "
                        "VALUES (:username, :pass, :age, :mail, :country)");
          query.bindValue(":username", name);
          query.bindValue(":pass", password);
          query.bindValue(":age", age);
          query.bindValue(":mail", email);
          query.bindValue(":country", country);
     if(query.exec())
     {
        this->close();
        //ui->label_6->setText("Account is created successfully.");
         playerLogin = new login;
         playerLogin->show();
     }
     else
       {
        qDebug() << "SqLite error:" << query.lastError().text();
        ui->label_6->setText("prob in query");
       }
}
