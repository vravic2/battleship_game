#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "gamerules.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Battleship Extreme");
    setFixedSize(720, 430);
    gamerules = new GameRules(this);
    //newPlayer = new SignIn;
}

MainWindow::~MainWindow()
{
    delete ui;
}



// Displays the game rules
void MainWindow::on_pushButton_2_clicked()
{
    //GameRules gamerules;
    gamerules->setModal(true);
    gamerules->exec();

}

// Quit the game
void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton answer;
    answer = QMessageBox::question(this, "Quit?",
                      "Are you sure you want to quit?");

    if(answer == QMessageBox::Yes){
        exit(-1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    newPlayer = new SignIn;
    newPlayer->show();

}

void MainWindow::on_pushButton_5_clicked()
{
  playerLogin = new login;
  playerLogin->show();
}
