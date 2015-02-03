#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::login)
{
  ui->setupUi(this);

}

login::~login()
{
  delete ui;
}

void login::on_pushButton_clicked()
{
   ui->label_4->setText("");
  //database connection
      QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName("C:/Users/vravic2/Desktop/Chinook_Sqlite.sqlite");


       QString username, password;
       username = ui->lineEdit->text();
       password = ui->lineEdit_2->text();
       gmode = ui->comboBox->currentText();

       if(mydb.open())
       ui->label_4->setText("connected to DB");
      else
       ui->label_4->setText("Connection failure");

      QSqlQuery qry;
         int count=0;
      if(qry.exec("select * from Players where username ='"+username+"' and pswd ='"+password+"' "))
      {
          while(qry.next())
          count++;
      }
      else
      {
          ui->label_4->setText("Couldnt execute the query");
      }
      if(count==1)
      {
          ui->label_4->setText("Authentication successful");
          mydb.close();
          mydb.removeDatabase(QSqlDatabase::defaultConnection);
          aiGame = new onePlayerGame(this,age,name,email,country,gmode);
                  aiGame->show();
                  this->hide();
      }
      else
      {
          ui->label_4->setText("Login or password is incorrect!");
          ui->label_4->setStyleSheet("color: red");
      }
}

void login::on_pushButton_2_clicked()
{
  this->close();
}
