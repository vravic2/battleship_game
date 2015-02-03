#ifndef ONEPLAYERGAME_H
#define ONEPLAYERGAME_H

#include <QMainWindow>
#include <QToolButton>
#include <QPushButton>
#include "player.h"
#include <QMessageBox>
 #include <QDebug>
#include <QMovie>
 #include <QTimer>

// global variable for burning row and column(passing variable in SLOT is not working.)
extern int burRow;
extern int burColumn;

namespace Ui {
class onePlayerGame;
}

class onePlayerGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit onePlayerGame(QWidget *parent = 0, int age = 0, QString name = "player 1", QString email = "", QString country = "", QString gmode = "Easy");
    ~onePlayerGame();

private slots:
    void on_EA1_clicked();

    void on_PA1_clicked();

    void on_carrierButton_clicked();

    void on_battleshipButton_clicked();

    void on_subButton_clicked();

    void on_cruiserButton_clicked();

    void on_patrolButton_clicked();

    void on_PA2_clicked();

    void on_PA3_clicked();

    void on_PA4_clicked();

    void on_PA5_clicked();

    void on_PA6_clicked();

    void on_PA7_clicked();

    void on_PA8_clicked();

    void on_PA9_clicked();

    void on_PA10_clicked();

    void on_PB1_clicked();

    void on_PB2_clicked();

    void on_PB3_clicked();

    void on_PB4_clicked();

    void on_PB5_clicked();

    void on_PB6_clicked();

    void on_PB7_clicked();

    void on_PB8_clicked();

    void on_PB9_clicked();

    void on_PB10_clicked();

    void on_PC1_clicked();

    void on_PC2_clicked();

    void on_PC3_clicked();

    void on_PC4_clicked();

    void on_PC5_clicked();

    void on_PC6_clicked();

    void on_PC7_clicked();

    void on_PC8_clicked();

    void on_PC9_clicked();

    void on_PC10_clicked();

    void on_PD1_clicked();

    void on_PD2_clicked();

    void on_PD3_clicked();

    void on_PD4_clicked();

    void on_PD5_clicked();

    void on_PD6_clicked();

    void on_PD7_clicked();

    void on_PD8_clicked();

    void on_PD9_clicked();

    void on_PD10_clicked();

    void on_PE1_clicked();

    void on_PE2_clicked();

    void on_PE3_clicked();

    void on_PE4_clicked();

    void on_PE5_clicked();

    void on_PE6_clicked();

    void on_PE7_clicked();

    void on_PE8_clicked();

    void on_PE9_clicked();

    void on_PE10_clicked();

    void on_PF1_clicked();

    void on_PF2_clicked();

    void on_PF3_clicked();

    void on_PF4_clicked();

    void on_PF5_clicked();

    void on_PF6_clicked();

    void on_PF7_clicked();

    void on_PF8_clicked();

    void on_PF9_clicked();

    void on_PF10_clicked();

    void on_PG1_clicked();

    void on_PG2_clicked();

    void on_PG3_clicked();

    void on_PG4_clicked();

    void on_PG5_clicked();

    void on_PG6_clicked();

    void on_PG7_clicked();

    void on_PG8_clicked();

    void on_PG9_clicked();

    void on_PG10_clicked();

    void on_PH1_clicked();

    void on_PH2_clicked();

    void on_PH3_clicked();

    void on_PH4_clicked();

    void on_PH5_clicked();

    void on_PH6_clicked();

    void on_PH7_clicked();

    void on_PH8_clicked();

    void on_PH9_clicked();

    void on_PH10_clicked();

    void on_PI1_clicked();

    void on_PI2_clicked();

    void on_PI3_clicked();

    void on_PI4_clicked();

    void on_PI5_clicked();

    void on_PI6_clicked();

    void on_PI7_clicked();

    void on_PI8_clicked();

    void on_PI9_clicked();

    void on_PI10_clicked();

    void on_PJ1_clicked();

    void on_PJ2_clicked();

    void on_PJ3_clicked();

    void on_PJ4_clicked();

    void on_PJ5_clicked();

    void on_PJ6_clicked();

    void on_PJ7_clicked();

    void on_PJ8_clicked();

    void on_PJ9_clicked();

    void on_PJ10_clicked();

    void on_EA2_clicked();

    void on_EA3_clicked();

    void on_EA4_clicked();

    void on_EA5_clicked();

    void on_EA6_clicked();

    void on_EA7_clicked();

    void on_EA8_clicked();

    void on_EA9_clicked();

    void on_EA10_clicked();

    void on_EB1_clicked();

    void on_EB2_clicked();

    void on_EB3_clicked();

    void on_EB4_clicked();

    void on_EB5_clicked();

    void on_EB6_clicked();

    void on_EB7_clicked();

    void on_EB8_clicked();

    void on_EB9_clicked();

    void on_EB10_clicked();

    void on_EC1_clicked();

    void on_EC2_clicked();

    void on_EC3_clicked();

    void on_EC4_clicked();

    void on_EC5_clicked();

    void on_EC6_clicked();

    void on_EC7_clicked();

    void on_EC8_clicked();

    void on_EC9_clicked();

    void on_EC10_clicked();

    void on_ED1_clicked();

    void on_ED2_clicked();

    void on_ED3_clicked();

    void on_ED4_clicked();

    void on_ED5_clicked();

    void on_ED6_clicked();

    void on_ED7_clicked();

    void on_ED8_clicked();

    void on_ED9_clicked();

    void on_ED10_clicked();

    void on_EE1_clicked();

    void on_EE2_clicked();

    void on_EE3_clicked();

    void on_EE4_clicked();

    void on_EE5_clicked();

    void on_EE6_clicked();

    void on_EE7_clicked();

    void on_EE8_clicked();

    void on_EE9_clicked();

    void on_EE10_clicked();

    void on_EF1_clicked();

    void on_EF2_clicked();

    void on_EF3_clicked();

    void on_EF4_clicked();

    void on_EF5_clicked();

    void on_EF6_clicked();

    void on_EF7_clicked();

    void on_EF8_clicked();

    void on_EF9_clicked();

    void on_EF10_clicked();

    void on_EG1_clicked();

    void on_EG2_clicked();

    void on_EG3_clicked();

    void on_EG4_clicked();

    void on_EG5_clicked();

    void on_EG6_clicked();

    void on_EG7_clicked();

    void on_EG8_clicked();

    void on_EG9_clicked();

    void on_EG10_clicked();

    void on_EH1_clicked();

    void on_EH2_clicked();

    void on_EH3_clicked();

    void on_EH4_clicked();

    void on_EH5_clicked();

    void on_EH6_clicked();

    void on_EH7_clicked();

    void on_EH8_clicked();

    void on_EH9_clicked();

    void on_EH10_clicked();

    void on_EI1_clicked();

    void on_EI2_clicked();

    void on_EI3_clicked();

    void on_EI4_clicked();

    void on_EI5_clicked();

    void on_EI6_clicked();

    void on_EI7_clicked();

    void on_EI8_clicked();

    void on_EI9_clicked();

    void on_EI10_clicked();

    void on_EJ1_clicked();

    void on_EJ2_clicked();

    void on_EJ3_clicked();

    void on_EJ4_clicked();

    void on_EJ5_clicked();

    void on_EJ6_clicked();

    void on_EJ7_clicked();

    void on_EJ8_clicked();

    void on_EJ9_clicked();

    void on_EJ10_clicked();

    void on_quitButton_clicked();

    void on_exitButton_clicked();

    void on_verticalButton_clicked();

    void on_horizontalButton_clicked();

    void setFireButtonIcon(int);

    void setButtonIcon(int);

    void animationQuit();
private:
    Ui::onePlayerGame *ui;

    Player* player1;
    Player* player2;
    int pBoard [100][100];
    int eBoard [100][100];
    QToolButton* eBoardPtr[10][10];
    QToolButton* pBoardPtr[10][10];
    int turn;
    int placingShips;
    int shipsToPlace;
    int whichShip;
    int orientation;
    int animeType;
    QPushButton* shipButton;
    QList<int> results;
    QList<int> nexthit;
    int concat(int x,int y);
    void initializeBoard();
    void initAiBoard();
    void placeShip(int row, int column);
    void donePlacing();
    void playerMove(int row, int column);

    QList<int> generateRandom();
    QString gmode;
    QMovie *expmovie = new QMovie("C:/Users/vravic2/Desktop/3/3/explosive.GIF");
    QMovie *movie = new QMovie("C:/Users/vravic2/Desktop/3/3/sma.GIF");


};

#endif // ONEPLAYERGAME_H
