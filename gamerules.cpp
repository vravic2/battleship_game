#include "gamerules.h"
#include "ui_gamerules.h"

GameRules::GameRules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRules)
{
    ui->setupUi(this);
    this->setWindowTitle("Game Rules");
}

GameRules::~GameRules()
{
    delete ui;
}

void GameRules::on_pushButton_clicked()
{
    // Close the game rules window
    this->close();
}
