#include "oneplayergame.h"
#include "ui_oneplayergame.h"
#include <QGraphicsScene>
int burRow,burColumn;

onePlayerGame::onePlayerGame(QWidget *parent, int age, QString name, QString email, QString country, QString gmode) :
    QMainWindow(parent),
    ui(new Ui::onePlayerGame)
{
    ui->setupUi(this);
    ui->winLabel->hide();
    ui->playerLabel->setText(name);
    ui->gameText->setText("Place your Ships");
    ui->mode->setText(gmode);
    ui->mode->hide();
    player1 = new HumanPlayer;
    player2 = new AIPlayer;
    orientation = 1;
    initializeBoard();
    for (int i = 0;i < 10; i++){
        for(int j = 0; j < 10; j++){
            pBoard [i][j] = 0;
            eBoard [i][j] = 0;
        }
    }
    initAiBoard();
    turn = 1;
    shipsToPlace = 5;
    placingShips = 1;
    whichShip = 0;
}

onePlayerGame::~onePlayerGame()
{
    delete ui;
}

void onePlayerGame::initializeBoard()
{
    eBoardPtr [0][0] = ui->EA1;
    eBoardPtr [0][1] = ui->EA2;
    eBoardPtr [0][2] = ui->EA3;
    eBoardPtr [0][3] = ui->EA4;
    eBoardPtr [0][4] = ui->EA5;
    eBoardPtr [0][5] = ui->EA6;
    eBoardPtr [0][6] = ui->EA7;
    eBoardPtr [0][7] = ui->EA8;
    eBoardPtr [0][8] = ui->EA9;
    eBoardPtr [0][9] = ui->EA10;
    eBoardPtr [1][0] = ui->EB1;
    eBoardPtr [1][1] = ui->EB2;
    eBoardPtr [1][2] = ui->EB3;
    eBoardPtr [1][3] = ui->EB4;
    eBoardPtr [1][4] = ui->EB5;
    eBoardPtr [1][5] = ui->EB6;
    eBoardPtr [1][6] = ui->EB7;
    eBoardPtr [1][7] = ui->EB8;
    eBoardPtr [1][8] = ui->EB9;
    eBoardPtr [1][9] = ui->EB10;
    eBoardPtr [2][0] = ui->EC1;
    eBoardPtr [2][1] = ui->EC2;
    eBoardPtr [2][2] = ui->EC3;
    eBoardPtr [2][3] = ui->EC4;
    eBoardPtr [2][4] = ui->EC5;
    eBoardPtr [2][5] = ui->EC6;
    eBoardPtr [2][6] = ui->EC7;
    eBoardPtr [2][7] = ui->EC8;
    eBoardPtr [2][8] = ui->EC9;
    eBoardPtr [2][9] = ui->EC10;
    eBoardPtr [3][0] = ui->ED1;
    eBoardPtr [3][1] = ui->ED2;
    eBoardPtr [3][2] = ui->ED3;
    eBoardPtr [3][3] = ui->ED4;
    eBoardPtr [3][4] = ui->ED5;
    eBoardPtr [3][5] = ui->ED6;
    eBoardPtr [3][6] = ui->ED7;
    eBoardPtr [3][7] = ui->ED8;
    eBoardPtr [3][8] = ui->ED9;
    eBoardPtr [3][9] = ui->ED10;
    eBoardPtr [4][0] = ui->EE1;
    eBoardPtr [4][1] = ui->EE2;
    eBoardPtr [4][2] = ui->EE3;
    eBoardPtr [4][3] = ui->EE4;
    eBoardPtr [4][4] = ui->EE5;
    eBoardPtr [4][5] = ui->EE6;
    eBoardPtr [4][6] = ui->EE7;
    eBoardPtr [4][7] = ui->EE8;
    eBoardPtr [4][8] = ui->EE9;
    eBoardPtr [4][9] = ui->EE10;
    eBoardPtr [5][0] = ui->EF1;
    eBoardPtr [5][1] = ui->EF2;
    eBoardPtr [5][2] = ui->EF3;
    eBoardPtr [5][3] = ui->EF4;
    eBoardPtr [5][4] = ui->EF5;
    eBoardPtr [5][5] = ui->EF6;
    eBoardPtr [5][6] = ui->EF7;
    eBoardPtr [5][7] = ui->EF8;
    eBoardPtr [5][8] = ui->EF9;
    eBoardPtr [5][9] = ui->EF10;
    eBoardPtr [6][0] = ui->EG1;
    eBoardPtr [6][1] = ui->EG2;
    eBoardPtr [6][2] = ui->EG3;
    eBoardPtr [6][3] = ui->EG4;
    eBoardPtr [6][4] = ui->EG5;
    eBoardPtr [6][5] = ui->EG6;
    eBoardPtr [6][6] = ui->EG7;
    eBoardPtr [6][7] = ui->EG8;
    eBoardPtr [6][8] = ui->EG9;
    eBoardPtr [6][9] = ui->EG10;
    eBoardPtr [7][0] = ui->EH1;
    eBoardPtr [7][1] = ui->EH2;
    eBoardPtr [7][2] = ui->EH3;
    eBoardPtr [7][3] = ui->EH4;
    eBoardPtr [7][4] = ui->EH5;
    eBoardPtr [7][5] = ui->EH6;
    eBoardPtr [7][6] = ui->EH7;
    eBoardPtr [7][7] = ui->EH8;
    eBoardPtr [7][8] = ui->EH9;
    eBoardPtr [7][9] = ui->EH10;
    eBoardPtr [8][0] = ui->EI1;
    eBoardPtr [8][1] = ui->EI2;
    eBoardPtr [8][2] = ui->EI3;
    eBoardPtr [8][3] = ui->EI4;
    eBoardPtr [8][4] = ui->EI5;
    eBoardPtr [8][5] = ui->EI6;
    eBoardPtr [8][6] = ui->EI7;
    eBoardPtr [8][7] = ui->EI8;
    eBoardPtr [8][8] = ui->EI9;
    eBoardPtr [8][9] = ui->EI10;
    eBoardPtr [9][0] = ui->EJ1;
    eBoardPtr [9][1] = ui->EJ2;
    eBoardPtr [9][2] = ui->EJ3;
    eBoardPtr [9][3] = ui->EJ4;
    eBoardPtr [9][4] = ui->EJ5;
    eBoardPtr [9][5] = ui->EJ6;
    eBoardPtr [9][6] = ui->EJ7;
    eBoardPtr [9][7] = ui->EJ8;
    eBoardPtr [9][8] = ui->EJ9;
    eBoardPtr [9][9] = ui->EJ10;

    pBoardPtr [0][0] = ui->PA1;
    pBoardPtr [0][1] = ui->PA2;
    pBoardPtr [0][2] = ui->PA3;
    pBoardPtr [0][3] = ui->PA4;
    pBoardPtr [0][4] = ui->PA5;
    pBoardPtr [0][5] = ui->PA6;
    pBoardPtr [0][6] = ui->PA7;
    pBoardPtr [0][7] = ui->PA8;
    pBoardPtr [0][8] = ui->PA9;
    pBoardPtr [0][9] = ui->PA10;
    pBoardPtr [1][0] = ui->PB1;
    pBoardPtr [1][1] = ui->PB2;
    pBoardPtr [1][2] = ui->PB3;
    pBoardPtr [1][3] = ui->PB4;
    pBoardPtr [1][4] = ui->PB5;
    pBoardPtr [1][5] = ui->PB6;
    pBoardPtr [1][6] = ui->PB7;
    pBoardPtr [1][7] = ui->PB8;
    pBoardPtr [1][8] = ui->PB9;
    pBoardPtr [1][9] = ui->PB10;
    pBoardPtr [2][0] = ui->PC1;
    pBoardPtr [2][1] = ui->PC2;
    pBoardPtr [2][2] = ui->PC3;
    pBoardPtr [2][3] = ui->PC4;
    pBoardPtr [2][4] = ui->PC5;
    pBoardPtr [2][5] = ui->PC6;
    pBoardPtr [2][6] = ui->PC7;
    pBoardPtr [2][7] = ui->PC8;
    pBoardPtr [2][8] = ui->PC9;
    pBoardPtr [2][9] = ui->PC10;
    pBoardPtr [3][0] = ui->PD1;
    pBoardPtr [3][1] = ui->PD2;
    pBoardPtr [3][2] = ui->PD3;
    pBoardPtr [3][3] = ui->PD4;
    pBoardPtr [3][4] = ui->PD5;
    pBoardPtr [3][5] = ui->PD6;
    pBoardPtr [3][6] = ui->PD7;
    pBoardPtr [3][7] = ui->PD8;
    pBoardPtr [3][8] = ui->PD9;
    pBoardPtr [3][9] = ui->PD10;
    pBoardPtr [4][0] = ui->PE1;
    pBoardPtr [4][1] = ui->PE2;
    pBoardPtr [4][2] = ui->PE3;
    pBoardPtr [4][3] = ui->PE4;
    pBoardPtr [4][4] = ui->PE5;
    pBoardPtr [4][5] = ui->PE6;
    pBoardPtr [4][6] = ui->PE7;
    pBoardPtr [4][7] = ui->PE8;
    pBoardPtr [4][8] = ui->PE9;
    pBoardPtr [4][9] = ui->PE10;
    pBoardPtr [5][0] = ui->PF1;
    pBoardPtr [5][1] = ui->PF2;
    pBoardPtr [5][2] = ui->PF3;
    pBoardPtr [5][3] = ui->PF4;
    pBoardPtr [5][4] = ui->PF5;
    pBoardPtr [5][5] = ui->PF6;
    pBoardPtr [5][6] = ui->PF7;
    pBoardPtr [5][7] = ui->PF8;
    pBoardPtr [5][8] = ui->PF9;
    pBoardPtr [5][9] = ui->PF10;
    pBoardPtr [6][0] = ui->PG1;
    pBoardPtr [6][1] = ui->PG2;
    pBoardPtr [6][2] = ui->PG3;
    pBoardPtr [6][3] = ui->PG4;
    pBoardPtr [6][4] = ui->PG5;
    pBoardPtr [6][5] = ui->PG6;
    pBoardPtr [6][6] = ui->PG7;
    pBoardPtr [6][7] = ui->PG8;
    pBoardPtr [6][8] = ui->PG9;
    pBoardPtr [6][9] = ui->PG10;
    pBoardPtr [7][0] = ui->PH1;
    pBoardPtr [7][1] = ui->PH2;
    pBoardPtr [7][2] = ui->PH3;
    pBoardPtr [7][3] = ui->PH4;
    pBoardPtr [7][4] = ui->PH5;
    pBoardPtr [7][5] = ui->PH6;
    pBoardPtr [7][6] = ui->PH7;
    pBoardPtr [7][7] = ui->PH8;
    pBoardPtr [7][8] = ui->PH9;
    pBoardPtr [7][9] = ui->PH10;
    pBoardPtr [8][0] = ui->PI1;
    pBoardPtr [8][1] = ui->PI2;
    pBoardPtr [8][2] = ui->PI3;
    pBoardPtr [8][3] = ui->PI4;
    pBoardPtr [8][4] = ui->PI5;
    pBoardPtr [8][5] = ui->PI6;
    pBoardPtr [8][6] = ui->PI7;
    pBoardPtr [8][7] = ui->PI8;
    pBoardPtr [8][8] = ui->PI9;
    pBoardPtr [8][9] = ui->PI10;
    pBoardPtr [9][0] = ui->PJ1;
    pBoardPtr [9][1] = ui->PJ2;
    pBoardPtr [9][2] = ui->PJ3;
    pBoardPtr [9][3] = ui->PJ4;
    pBoardPtr [9][4] = ui->PJ5;
    pBoardPtr [9][5] = ui->PJ6;
    pBoardPtr [9][6] = ui->PJ7;
    pBoardPtr [9][7] = ui->PJ8;
    pBoardPtr [9][8] = ui->PJ9;
    pBoardPtr [9][9] = ui->PJ10;

}

void onePlayerGame::placeShip(int row, int column){
    switch (whichShip){
    case 5:
        if (orientation == 1){
            if (row > 7) {
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9 && pBoard[row-3][column] != 9 && pBoard[row-4][column] != 9) {
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-3][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-4][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row-2][column] = 9;
                    pBoard[row-3][column] = 9;
                    pBoard[row-4][column] = 9;
                    donePlacing();
                }
            }
            else if (row < 2){
                if (pBoard[row][column] != 9 && pBoard[row+1][column] != 9 && pBoard[row+2][column] != 9 && pBoard[row+3][column] != 9 && pBoard[row+4][column] != 9) {
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row+1][column] = 9;
                    pBoard[row+2][column] = 9;
                    pBoard[row+3][column] = 9;
                    pBoard[row+4][column] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9 && pBoard[row+1][column] != 9 && pBoard[row+2][column] != 9) {
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/a3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});


                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row-2][column] = 9;
                    pBoard[row+1][column] = 9;
                    pBoard[row+2][column] = 9;
                    donePlacing();
                }
            }
        }
        else {
            if (column > 7) {
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9 && pBoard[row][column-3] != 9 && pBoard[row][column-4] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-3]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-4]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    pBoard[row][column-3] = 9;
                    pBoard[row][column-4] = 9;
                    donePlacing();
                }
            }
            else if (column < 2){
                if (pBoard[row][column] != 9 && pBoard[row][column+1] != 9 && pBoard[row][column+2] != 9 && pBoard[row][column+3] != 9 && pBoard[row][column+4] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+3]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+4]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoard[row][column] = 9;
                    pBoard[row][column+1] = 9;
                    pBoard[row][column+2] = 9;
                    pBoard[row][column+3] = 9;
                    pBoard[row][column+4] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9 && pBoard[row][column+1] != 9 && pBoard[row][column+2] != 9) {


                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ah5.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    pBoard[row][column+1] = 9;
                    pBoard[row][column+2] = 9;
                    donePlacing();
                }
            }
        }
        break;
    case 4:
        if (orientation == 1) {
            if (row > 7) {
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9 && pBoard[row-3][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w4.jpeg);"
                                                          "background-color:rgba(255, 255, 255, 0);"
                            "border: 1px solid black"});
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-3][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row-2][column] = 9;
                    pBoard[row-3][column] = 9;
                    donePlacing();
                }
            }
            else if (row < 2){
                if (pBoard[row][column] != 9 && pBoard[row+1][column] != 9 && pBoard[row+2][column] != 9 && pBoard[row+3][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w1.jpeg);"
                                                          "background-color:rgba(255, 255, 255, 0);"
                            "border: 1px solid black"});
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+3][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row+1][column] = 9;
                    pBoard[row+2][column] = 9;
                    pBoard[row+3][column] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9 && pBoard[row+1][column] != 9) {


                     pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w3.jpeg);"
                                                           "background-color:rgba(255, 255, 255, 0);"
                             "border: 1px solid black"});
                     pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w2.jpeg);"
                                                              "background-color:rgba(255, 255, 255, 0);"
                                                              "border: 1px solid black"});
                     pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w1.jpeg);"
                                                              "background-color:rgba(255, 255, 255, 0);"
                                                              "border: 1px solid black"});
                     pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/w4.jpeg);"
                                                              "background-color:rgba(255, 255, 255, 0);"
                                                              "border: 1px solid black"});

                    // QMovie *movie = new QMovie("C:/Users/vravic2/Desktop/3/3/sma.GIF");



                     //ui->label_27->setMovie(movie);


                    //yourLabel->setMovie(movie);
                     //movie->start();

                     pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row-2][column] = 9;
                    pBoard[row+1][column] = 9;
                    donePlacing();
                }
            }
        }
        else {
            if (column > 7) {
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9 && pBoard[row][column-3] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh4.jpeg);"
                                                          "background-color:rgba(255, 255, 255, 0);"
                            "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-3]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    pBoard[row][column-3] = 9;
                    donePlacing();
                }
            }
            else if (column < 2){
                if (pBoard[row][column] != 9 && pBoard[row][column+1] != 9 && pBoard[row][column+2] != 9 && pBoard[row][column+3] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh4.jpeg);"
                                                          "background-color:rgba(255, 255, 255, 0);"
                            "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-3]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    pBoard[row][column-3] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9 && pBoard[row][column+1] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh3.jpeg);"
                                                          "background-color:rgba(255, 255, 255, 0);"
                            "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wh4.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    pBoard[row][column+1] = 9;
                    donePlacing();
                }
            }
        }
        break;
    case 3:
        if (orientation == 1) {
            if (row > 8) {
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});


                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row-2][column] = 9;
                    donePlacing();
                }
            }
            else if (row < 2){
                if (pBoard[row][column] != 9 && pBoard[row+1][column] != 9 && pBoard[row+2][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row+1][column] = 9;
                    pBoard[row+2][column] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row+1][column] != 9) {
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/s3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    pBoard[row+1][column] = 9;
                    donePlacing();
                }
            }
        }
        else {
            if (column > 8) {
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});


                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column-2] = 9;
                    donePlacing();
                }
            }
            else if (column < 2){
                if (pBoard[row][column] != 9 && pBoard[row][column+1] != 9 && pBoard[row][column+2] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column+1] = 9;
                    pBoard[row][column+2] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column+1] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/sh3.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    pBoard[row][column+1] = 9;
                    donePlacing();
                }
            }
        }
        break;
    case 2:
        if (orientation == 1) {
            if (row > 8) {
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});


                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    donePlacing();
                }
            }
            else if (row < 1){
                if (pBoard[row][column] != 9 && pBoard[row+1][column] != 9) {
                    pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row+1][column] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/p1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row-1][column] = 9;
                    donePlacing();
                }
            }
        }
        else {
            if (column > 7) {
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    donePlacing();
                }
            }
            else if (column < 2){
                if (pBoard[row][column] != 9 && pBoard[row][column+1] != 9) {
                    pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoard[row][column] = 9;
                    pBoard[row][column+1] = 9;
                    donePlacing();
                }
            }
            else{
                if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9) {
                    pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph2.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});
                    pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ph1.jpeg);"
                                                             "background-color:rgba(255, 255, 255, 0);"
                                                             "border: 1px solid black"});

                    pBoard[row][column] = 9;
                    pBoard[row][column-1] = 9;
                    donePlacing();
                }
            }
        }
        break;
      case 1:
          if (orientation == 1) {
              if (row > 8) {
                  if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row-2][column] != 9) {
                      pBoardPtr[row-2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});


                      pBoard[row][column] = 9;
                      pBoard[row-1][column] = 9;
                      pBoard[row-2][column] = 9;
                      donePlacing();
                  }
              }
              else if (row < 2){
                  if (pBoard[row][column] != 9 && pBoard[row+1][column] != 9 && pBoard[row+2][column] != 9) {
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row+2][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});

                      pBoard[row][column] = 9;
                      pBoard[row+1][column] = 9;
                      pBoard[row+2][column] = 9;
                      donePlacing();
                  }
              }
              else{
                  if (pBoard[row][column] != 9 && pBoard[row-1][column] != 9 && pBoard[row+1][column] != 9) {
                      pBoardPtr[row-1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row+1][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/c3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});

                      pBoard[row][column] = 9;
                      pBoard[row-1][column] = 9;
                      pBoard[row+1][column] = 9;
                      donePlacing();
                  }
              }
          }
          else {
              if (column > 8) {
                  if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column-2] != 9) {
                      pBoardPtr[row][column-2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});

                      pBoard[row][column] = 9;
                      pBoard[row][column-1] = 9;
                      pBoard[row][column-2] = 9;
                      donePlacing();
                  }
              }
              else if (column < 2){
                  if (pBoard[row][column] != 9 && pBoard[row][column+1] != 9 && pBoard[row][column+2] != 9) {
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column+2]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoard[row][column] = 9;
                      pBoard[row][column+1] = 9;
                      pBoard[row][column+2] = 9;
                      donePlacing();
                  }
              }
              else{
                  if (pBoard[row][column] != 9 && pBoard[row][column-1] != 9 && pBoard[row][column+1] != 9) {
                      pBoardPtr[row][column-1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch1.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch2.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoardPtr[row][column+1]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/ch3.jpeg);"
                                                               "background-color:rgba(255, 255, 255, 0);"
                                                               "border: 1px solid black"});
                      pBoard[row][column] = 9;
                      pBoard[row][column-1] = 9;
                      pBoard[row][column+1] = 9;
                      donePlacing();
                  }
              }
          }
          break;

    default:
        break;
    }
}
void onePlayerGame::animationQuit()
{
    expmovie->stop();
    connect(movie,SIGNAL(frameChanged(int)),this,SLOT(setFireButtonIcon(int)));
    movie->start();
    movie->setSpeed(150);
    // if movie doesn't loop forever, force it to.
    if (movie->loopCount() != -1)
        connect(movie,SIGNAL(finished()),movie,SLOT(start()));

    movie->start();
}
void onePlayerGame::setButtonIcon(int)
{
    pBoardPtr[burRow][burColumn]->setIconSize(QSize(pBoardPtr[1][1]->size().width(),pBoardPtr[1][1]->size().height()+6));
    pBoardPtr[burRow][burColumn]->setIcon(QIcon(expmovie->currentPixmap()));
}
void onePlayerGame::setFireButtonIcon(int)
{
    pBoardPtr[burRow][burColumn]->setIconSize(QSize(pBoardPtr[1][1]->size().width()-6,pBoardPtr[1][1]->size().height()));
    pBoardPtr[burRow][burColumn]->setIcon(QIcon(movie->currentPixmap()));
}
void onePlayerGame::donePlacing(){
    shipsToPlace--;
    shipButton->hide();
    if (shipsToPlace == 0) {
        turn = 1;
        placingShips = 0;
        ui->gameText->setText("Your Turn");
        ui->verticalButton->hide();
        ui->horizontalButton->hide();
    }
    whichShip = 0;
}


void onePlayerGame::on_carrierButton_clicked()
{
    whichShip = 5;
    shipButton = ui->carrierButton;
}

void onePlayerGame::on_battleshipButton_clicked()
{
    whichShip = 4;
    shipButton = ui->battleshipButton;
}

void onePlayerGame::on_subButton_clicked()
{
    whichShip = 3;
    shipButton = ui->subButton;
}

void onePlayerGame::on_cruiserButton_clicked()
{
    whichShip = 1;
    shipButton = ui->cruiserButton;
}

void onePlayerGame::on_patrolButton_clicked()
{
    whichShip = 2;
    shipButton = ui->patrolButton;
}

void onePlayerGame::on_PA1_clicked()
{
    if (placingShips){
        placeShip(0,0);
        return;
    }

    //playerMove(0,0);
}

void onePlayerGame::on_PA2_clicked()
{
    if (placingShips){
        placeShip(0,1);
        return;
    }
    //playerMove(0,1);

}

void onePlayerGame::on_PA3_clicked()
{
    if (placingShips){
        placeShip(0,2);
        return;
    }
    //playerMove(0,2);

}

void onePlayerGame::on_PA4_clicked()
{
    if (placingShips){
        placeShip(0,3);
        return;
    }
    //playerMove(0,3);
}

void onePlayerGame::on_PA5_clicked()
{
    if (placingShips){
        placeShip(0,4);
        return;
    }
   // playerMove(0,4);
}

void onePlayerGame::on_PA6_clicked()
{
    if (placingShips){
        placeShip(0,5);
        return;
    }
    //playerMove(0,5);
}

void onePlayerGame::on_PA7_clicked()
{
    if (placingShips){
        placeShip(0,6);
        return;
    }
    //playerMove(0,6);
}

void onePlayerGame::on_PA8_clicked()
{
    if (placingShips){
        placeShip(0,7);
        return;
    }
    //playerMove(0,7);
}

void onePlayerGame::on_PA9_clicked()
{
    if (placingShips){
        placeShip(0,8);
        return;
    }
    //playerMove(0,8);
}

void onePlayerGame::on_PA10_clicked()
{
    if (placingShips){
        placeShip(0,9);
        return;
    }
    //playerMove(0,9);
}

void onePlayerGame::on_PB1_clicked()
{
    if (placingShips){
        placeShip(1,0);
        return;
    }
    //playerMove(1,0);
}

void onePlayerGame::on_PB2_clicked()
{
    if (placingShips){
        placeShip(1,1);
        return;
    }
    //playerMove(1,1);
}

void onePlayerGame::on_PB3_clicked()
{
    if (placingShips){
        placeShip(1,2);
        return;
    }
    //playerMove(1,2);
}

void onePlayerGame::on_PB4_clicked()
{
    if (placingShips){
        placeShip(1,3);
        return;
    }
    //playerMove(1,3);
}

void onePlayerGame::on_PB5_clicked()
{
    if (placingShips){
        placeShip(1,4);
        return;
    }
    //playerMove(1,4);
}

void onePlayerGame::on_PB6_clicked()
{
    if (placingShips){
        placeShip(1,5);
        return;
    }
    //playerMove(1,5);
}

void onePlayerGame::on_PB7_clicked()
{
    if (placingShips){
        placeShip(1,6);
        return;
    }
    //playerMove(1,6);
}

void onePlayerGame::on_PB8_clicked()
{
    if (placingShips){
        placeShip(1,7);
        return;
    }
    //playerMove(1,7);
}

void onePlayerGame::on_PB9_clicked()
{
    if (placingShips){
        placeShip(1,8);
        return;
    }
    //playerMove(1,8);
}

void onePlayerGame::on_PB10_clicked()
{
    if (placingShips){
        placeShip(1,9);
        return;
    }
    //playerMove(1,9);
}

void onePlayerGame::on_PC1_clicked()
{
    if (placingShips){
        placeShip(2,0);
        return;
    }
    //playerMove(2,0);
}

void onePlayerGame::on_PC2_clicked()
{
    if (placingShips){
        placeShip(2,1);
        return;
    }
    //playerMove(2,1);
}

void onePlayerGame::on_PC3_clicked()
{
    if (placingShips){
        placeShip(2,2);
        return;
    }
    //playerMove(2,2);
}

void onePlayerGame::on_PC4_clicked()
{
    if (placingShips){
        placeShip(2,3);
        return;
    }
    //playerMove(2,3);
}

void onePlayerGame::on_PC5_clicked()
{
    if (placingShips){
        placeShip(2,4);
        return;
    }
    //playerMove(2,4);
}

void onePlayerGame::on_PC6_clicked()
{
    if (placingShips){
        placeShip(2,5);
        return;
    }
    //playerMove(2,5);
}

void onePlayerGame::on_PC7_clicked()
{
    if (placingShips){
        placeShip(2,6);
        return;
    }
    //playerMove(2,6);
}

void onePlayerGame::on_PC8_clicked()
{
    if (placingShips){
        placeShip(2,7);
        return;
    }
    //playerMove(2,7);
}

void onePlayerGame::on_PC9_clicked()
{
    if (placingShips){
        placeShip(2,8);
        return;
    }
    //playerMove(2,8);
}

void onePlayerGame::on_PC10_clicked()
{
    if (placingShips){
        placeShip(2,9);
        return;
    }
   // playerMove(2,9);
}

void onePlayerGame::on_PD1_clicked()
{
    if (placingShips){
        placeShip(3,0);
        return;
    }
    //playerMove(3,0);
}

void onePlayerGame::on_PD2_clicked()
{
    if (placingShips){
        placeShip(3,1);
        return;
    }
    //playerMove(3,1);
}

void onePlayerGame::on_PD3_clicked()
{
    if (placingShips){
        placeShip(3,2);
        return;
    }
    //playerMove(3,2);
}

void onePlayerGame::on_PD4_clicked()
{
    if (placingShips){
        placeShip(3,3);
        return;
    }
    //playerMove(3,3);
}

void onePlayerGame::on_PD5_clicked()
{
    if (placingShips){
        placeShip(3,4);
        return;
    }
    //playerMove(3,4);
}

void onePlayerGame::on_PD6_clicked()
{
    if (placingShips){
        placeShip(3,5);
        return;
    }
    //playerMove(3,5);
}

void onePlayerGame::on_PD7_clicked()
{
    if (placingShips){
        placeShip(3,6);
        return;
    }
    //playerMove(3,6);
}

void onePlayerGame::on_PD8_clicked()
{
    if (placingShips){
        placeShip(3,7);
        return;
    }
    //playerMove(3,7);
}

void onePlayerGame::on_PD9_clicked()
{
    if (placingShips){
        placeShip(3,8);
        return;
    }
    //playerMove(3,8);
}

void onePlayerGame::on_PD10_clicked()
{
    if (placingShips){
        placeShip(3,9);
        return;
    }
    //playerMove(3,9);
}

void onePlayerGame::on_PE1_clicked()
{
    if (placingShips){
        placeShip(4,0);
        return;
    }
    //playerMove(4,0);
}

void onePlayerGame::on_PE2_clicked()
{
    if (placingShips){
        placeShip(4,1);
        return;
    }
    //playerMove(4,1);
}

void onePlayerGame::on_PE3_clicked()
{
    if (placingShips){
        placeShip(4,2);
        return;
    }
    //playerMove(4,2);
}

void onePlayerGame::on_PE4_clicked()
{
    if (placingShips){
        placeShip(4,3);
        return;
    }
    //playerMove(4,3);
}

void onePlayerGame::on_PE5_clicked()
{
    if (placingShips){
        placeShip(4,4);
        return;
    }
    //playerMove(4,4);
}

void onePlayerGame::on_PE6_clicked()
{
    if (placingShips){
        placeShip(4,5);
        return;
    }
    //playerMove(4,5);
}

void onePlayerGame::on_PE7_clicked()
{
    if (placingShips){
        placeShip(4,6);
        return;
    }
    //playerMove(4,6);
}

void onePlayerGame::on_PE8_clicked()
{
    if (placingShips){
        placeShip(4,7);
        return;
    }
    //playerMove(4,7);
}

void onePlayerGame::on_PE9_clicked()
{
    if (placingShips){
        placeShip(4,8);
        return;
    }
    //playerMove(4,8);
}

void onePlayerGame::on_PE10_clicked()
{
    if (placingShips){
        placeShip(4,9);
        return;
    }
    //playerMove(4,9);
}

void onePlayerGame::on_PF1_clicked()
{
    if (placingShips){
        placeShip(5,0);
        return;
    }
    //playerMove(5,0);
}

void onePlayerGame::on_PF2_clicked()
{
    if (placingShips){
        placeShip(5,1);
        return;
    }
    //playerMove(5,1);
}

void onePlayerGame::on_PF3_clicked()
{
    if (placingShips){
        placeShip(5,2);
        return;
    }
    //playerMove(5,2);
}

void onePlayerGame::on_PF4_clicked()
{
    if (placingShips){
        placeShip(5,3);
        return;
    }
    //playerMove(5,3);
}

void onePlayerGame::on_PF5_clicked()
{
    if (placingShips){
        placeShip(5,4);
        return;
    }
    //playerMove(5,4);
}

void onePlayerGame::on_PF6_clicked()
{
    if (placingShips){
        placeShip(5,5);
        return;
    }
    //playerMove(5,5);
}

void onePlayerGame::on_PF7_clicked()
{
    if (placingShips){
        placeShip(5,6);
        return;
    }
    //playerMove(5,6);
}

void onePlayerGame::on_PF8_clicked()
{
    if (placingShips){
        placeShip(5,7);
        return;
    }
    //playerMove(5,7);
}

void onePlayerGame::on_PF9_clicked()
{
    if (placingShips){
        placeShip(5,8);
        return;
    }
    //playerMove(5,8);
}

void onePlayerGame::on_PF10_clicked()
{
    if (placingShips){
        placeShip(5,9);
        return;
    }
    //playerMove(5,9);
}

void onePlayerGame::on_PG1_clicked()
{
    if (placingShips){
        placeShip(6,0);
        return;
    }
    //playerMove(6,0);
}

void onePlayerGame::on_PG2_clicked()
{
    if (placingShips){
        placeShip(6,1);
        return;
    }
    //playerMove(6,1);
}

void onePlayerGame::on_PG3_clicked()
{
    if (placingShips){
        placeShip(6,2);
        return;
    }
    //playerMove(6,2);
}

void onePlayerGame::on_PG4_clicked()
{
    if (placingShips){
        placeShip(6,3);
        return;
    }
    //playerMove(6,3);
}

void onePlayerGame::on_PG5_clicked()
{
    if (placingShips){
        placeShip(6,4);
        return;
    }
    //playerMove(6,4);
}

void onePlayerGame::on_PG6_clicked()
{
    if (placingShips){
        placeShip(6,5);
        return;
    }
    //playerMove(6,5);
}

void onePlayerGame::on_PG7_clicked()
{
    if (placingShips){
        placeShip(6,6);
        return;
    }
    //playerMove(6,6);
}

void onePlayerGame::on_PG8_clicked()
{
    if (placingShips){
        placeShip(6,7);
        return;
    }
    //playerMove(6,7);
}

void onePlayerGame::on_PG9_clicked()
{
    if (placingShips){
        placeShip(6,8);
        return;
    }
    //playerMove(6,8);
}

void onePlayerGame::on_PG10_clicked()
{
    if (placingShips){
        placeShip(6,9);
        return;
    }
    //playerMove(6,9);
}

void onePlayerGame::on_PH1_clicked()
{
    if (placingShips){
        placeShip(7,0);
        return;
    }
    //playerMove(7,0);
}

void onePlayerGame::on_PH2_clicked()
{
    if (placingShips){
        placeShip(7,1);
        return;
    }
    //playerMove(7,1);
}

void onePlayerGame::on_PH3_clicked()
{
    if (placingShips){
        placeShip(7,2);
        return;
    }
    //playerMove(7,2);
}

void onePlayerGame::on_PH4_clicked()
{
    if (placingShips){
        placeShip(7,3);
        return;
    }
    //playerMove(7,3);
}

void onePlayerGame::on_PH5_clicked()
{
    if (placingShips){
        placeShip(7,4);
        return;
    }
    //playerMove(7,4);
}

void onePlayerGame::on_PH6_clicked()
{
    if (placingShips){
        placeShip(7,5);
        return;
    }
    //playerMove(7,5);
}

void onePlayerGame::on_PH7_clicked()
{
    if (placingShips){
        placeShip(7,6);
        return;
    }
    //playerMove(7,6);
}

void onePlayerGame::on_PH8_clicked()
{
    if (placingShips){
        placeShip(7,7);
        return;
    }
    //playerMove(7,7);
}

void onePlayerGame::on_PH9_clicked()
{
    if (placingShips){
        placeShip(7,8);
        return;
    }
    //playerMove(7,8);
}

void onePlayerGame::on_PH10_clicked()
{
    if (placingShips){
        placeShip(7,9);
        return;
    }
    //playerMove(7,9);
}

void onePlayerGame::on_PI1_clicked()
{
    if (placingShips){
        placeShip(8,0);
        return;
    }
    //playerMove(8,0);
}

void onePlayerGame::on_PI2_clicked()
{
    if (placingShips){
        placeShip(8,1);
        return;
    }
    //playerMove(8,1);
}

void onePlayerGame::on_PI3_clicked()
{
    if (placingShips){
        placeShip(8,2);
        return;
    }
    //playerMove(8,2);
}

void onePlayerGame::on_PI4_clicked()
{
    if (placingShips){
        placeShip(8,3);
        return;
    }
    //playerMove(8,3);
}

void onePlayerGame::on_PI5_clicked()
{
    if (placingShips){
        placeShip(8,4);
        return;
    }
    //playerMove(8,4);
}

void onePlayerGame::on_PI6_clicked()
{
    if (placingShips){
        placeShip(8,5);
        return;
    }
    //playerMove(8,5);
}

void onePlayerGame::on_PI7_clicked()
{
    if (placingShips){
        placeShip(8,6);
        return;
    }
    //playerMove(8,6);
}

void onePlayerGame::on_PI8_clicked()
{
    if (placingShips){
        placeShip(8,7);
        return;
    }
    //playerMove(8,7);
}

void onePlayerGame::on_PI9_clicked()
{
    if (placingShips){
        placeShip(8,8);
        return;
    }
    //playerMove(8,8);
}

void onePlayerGame::on_PI10_clicked()
{
    if (placingShips){
        placeShip(8,9);
        return;
    }
    //playerMove(8,9);
}

void onePlayerGame::on_PJ1_clicked()
{
    if (placingShips){
        placeShip(9,0);
        return;
    }
    //playerMove(9,0);
}

void onePlayerGame::on_PJ2_clicked()
{
    if (placingShips){
        placeShip(9,1);
        return;
    }
    //playerMove(9,1);
}

void onePlayerGame::on_PJ3_clicked()
{
    if (placingShips){
        placeShip(9,2);
        return;
    }
    //playerMove(9,2);
}

void onePlayerGame::on_PJ4_clicked()
{
    if (placingShips){
        placeShip(9,3);
        return;
    }
    //playerMove(9,3);
}

void onePlayerGame::on_PJ5_clicked()
{
    if (placingShips){
        placeShip(9,4);
        return;
    }
    //playerMove(9,4);
}

void onePlayerGame::on_PJ6_clicked()
{
    if (placingShips){
        placeShip(9,5);
        return;
    }
    //playerMove(9,5);
}

void onePlayerGame::on_PJ7_clicked()
{
    if (placingShips){
        placeShip(9,6);
        return;
    }
    //playerMove(9,6);
}

void onePlayerGame::on_PJ8_clicked()
{
    if (placingShips){
        placeShip(9,7);
        return;
    }
    //playerMove(9,7);
}

void onePlayerGame::on_PJ9_clicked()
{
    if (placingShips){
        placeShip(9,8);
        return;
    }
    //playerMove(9,8);
}

void onePlayerGame::on_PJ10_clicked()
{
    if (placingShips){
        placeShip(9,9);
        return;
    }
    //playerMove(9,9);
}

void onePlayerGame::on_EA1_clicked()
{
    if (placingShips){
        return;
    }
    playerMove(0,0);


    /*if (turn == 1){
        if (eBoard[0][0] == 1){
            eBoardPtr[0][0]->setStyleSheet("background-color: red");
            eBoard[0][0] = 9;
        }
        else {
            ui->EA1->setStyleSheet("background-color: white");
        }
    }
    turn = 0;
    ui->PA1->click();*/
}

void onePlayerGame::on_EA2_clicked()
{
    playerMove(0,1);

}

void onePlayerGame::on_EA3_clicked()
{
    playerMove(0,2);

}

void onePlayerGame::on_EA4_clicked()
{
    playerMove(0,3);

}

void onePlayerGame::on_EA5_clicked()
{
    playerMove(0,4);

}

void onePlayerGame::on_EA6_clicked()
{
    playerMove(0,5);

}

void onePlayerGame::on_EA7_clicked()
{
    playerMove(0,6);

}

void onePlayerGame::on_EA8_clicked()
{
    playerMove(0,7);

}

void onePlayerGame::on_EA9_clicked()
{
    playerMove(0,8);

}

void onePlayerGame::on_EA10_clicked()
{
    playerMove(0,9);

}

void onePlayerGame::on_EB1_clicked()
{
    playerMove(1,0);

}

void onePlayerGame::on_EB2_clicked()
{
    playerMove(1,1);

}

void onePlayerGame::on_EB3_clicked()
{
    playerMove(1,2);

}

void onePlayerGame::on_EB4_clicked()
{
    playerMove(1,3);

}

void onePlayerGame::on_EB5_clicked()
{
    playerMove(1,4);

}

void onePlayerGame::on_EB6_clicked()
{
    playerMove(1,5);

}

void onePlayerGame::on_EB7_clicked()
{
    playerMove(1,6);

}

void onePlayerGame::on_EB8_clicked()
{
    playerMove(1,7);

}

void onePlayerGame::on_EB9_clicked()
{
    playerMove(1,8);

}

void onePlayerGame::on_EB10_clicked()
{
    playerMove(1,9);

}

void onePlayerGame::on_EC1_clicked()
{
    playerMove(2,0);

}

void onePlayerGame::on_EC2_clicked()
{
    playerMove(2,1);

}

void onePlayerGame::on_EC3_clicked()
{
    playerMove(2,2);

}

void onePlayerGame::on_EC4_clicked()
{
    playerMove(2,3);

}

void onePlayerGame::on_EC5_clicked()
{
    playerMove(2,4);

}

void onePlayerGame::on_EC6_clicked()
{
    playerMove(2,5);

}

void onePlayerGame::on_EC7_clicked()
{
    playerMove(2,6);

}

void onePlayerGame::on_EC8_clicked()
{
    playerMove(2,7);

}

void onePlayerGame::on_EC9_clicked()
{
    playerMove(2,8);

}

void onePlayerGame::on_EC10_clicked()
{
    playerMove(2,9);

}

void onePlayerGame::on_ED1_clicked()
{
    playerMove(3,0);

}

void onePlayerGame::on_ED2_clicked()
{
    playerMove(3,1);

}

void onePlayerGame::on_ED3_clicked()
{
    playerMove(3,2);

}

void onePlayerGame::on_ED4_clicked()
{
    playerMove(3,3);

}

void onePlayerGame::on_ED5_clicked()
{
    playerMove(3,4);

}

void onePlayerGame::on_ED6_clicked()
{
    playerMove(3,5);

}

void onePlayerGame::on_ED7_clicked()
{
    playerMove(3,6);

}

void onePlayerGame::on_ED8_clicked()
{
    playerMove(3,7);

}

void onePlayerGame::on_ED9_clicked()
{
    playerMove(3,8);

}

void onePlayerGame::on_ED10_clicked()
{
    playerMove(3,9);

}

void onePlayerGame::on_EE1_clicked()
{
    playerMove(4,0);

}

void onePlayerGame::on_EE2_clicked()
{
    playerMove(4,1);

}

void onePlayerGame::on_EE3_clicked()
{
    playerMove(4,2);

}

void onePlayerGame::on_EE4_clicked()
{
    playerMove(4,3);

}

void onePlayerGame::on_EE5_clicked()
{
    playerMove(4,4);

}

void onePlayerGame::on_EE6_clicked()
{
    playerMove(4,5);

}

void onePlayerGame::on_EE7_clicked()
{
    playerMove(4,6);

}

void onePlayerGame::on_EE8_clicked()
{
    playerMove(4,7);

}

void onePlayerGame::on_EE9_clicked()
{
    playerMove(4,8);

}

void onePlayerGame::on_EE10_clicked()
{
    playerMove(4,9);

}

void onePlayerGame::on_EF1_clicked()
{
    playerMove(5,0);

}

void onePlayerGame::on_EF2_clicked()
{
    playerMove(5,1);

}

void onePlayerGame::on_EF3_clicked()
{
    playerMove(5,2);

}

void onePlayerGame::on_EF4_clicked()
{
    playerMove(5,3);

}

void onePlayerGame::on_EF5_clicked()
{
    playerMove(5,4);

}

void onePlayerGame::on_EF6_clicked()
{
    playerMove(5,5);

}

void onePlayerGame::on_EF7_clicked()
{
    playerMove(5,6);

}

void onePlayerGame::on_EF8_clicked()
{
    playerMove(5,7);

}

void onePlayerGame::on_EF9_clicked()
{
    playerMove(5,8);

}

void onePlayerGame::on_EF10_clicked()
{
    playerMove(5,9);

}

void onePlayerGame::on_EG1_clicked()
{
    playerMove(6,0);

}

void onePlayerGame::on_EG2_clicked()
{
    playerMove(6,1);

}

void onePlayerGame::on_EG3_clicked()
{
    playerMove(6,2);
}

void onePlayerGame::on_EG4_clicked()
{
    playerMove(6,3);

}

void onePlayerGame::on_EG5_clicked()
{
    playerMove(6,4);

}

void onePlayerGame::on_EG6_clicked()
{
    playerMove(6,5);

}

void onePlayerGame::on_EG7_clicked()
{
    playerMove(6,6);

}

void onePlayerGame::on_EG8_clicked()
{
    playerMove(6,7);

}

void onePlayerGame::on_EG9_clicked()
{
    playerMove(6,8);

}

void onePlayerGame::on_EG10_clicked()
{
    playerMove(6,9);

}

void onePlayerGame::on_EH1_clicked()
{
    playerMove(7,0);

}

void onePlayerGame::on_EH2_clicked()
{
    playerMove(7,1);


}

void onePlayerGame::on_EH3_clicked()
{
    playerMove(7,2);

}

void onePlayerGame::on_EH4_clicked()
{
    playerMove(7,3);

}

void onePlayerGame::on_EH5_clicked()
{
    playerMove(7,4);

}

void onePlayerGame::on_EH6_clicked()
{
    playerMove(7,5);

}

void onePlayerGame::on_EH7_clicked()
{
    playerMove(7,6);

}

void onePlayerGame::on_EH8_clicked()
{
    playerMove(7,7);

}

void onePlayerGame::on_EH9_clicked()
{
    playerMove(7,8);
}

void onePlayerGame::on_EH10_clicked()
{
    playerMove(7,9);

}

void onePlayerGame::on_EI1_clicked()
{
    playerMove(8,0);

}

void onePlayerGame::on_EI2_clicked()
{
    playerMove(8,1);

}

void onePlayerGame::on_EI3_clicked()
{
    playerMove(8,2);

}

void onePlayerGame::on_EI4_clicked()
{
    playerMove(8,3);

}

void onePlayerGame::on_EI5_clicked()
{
    playerMove(8,4);

}

void onePlayerGame::on_EI6_clicked()
{
    playerMove(8,5);

}

void onePlayerGame::on_EI7_clicked()
{
    playerMove(8,6);

}

void onePlayerGame::on_EI8_clicked()
{
    playerMove(8,7);

}

void onePlayerGame::on_EI9_clicked()
{
    playerMove(8,8);

}

void onePlayerGame::on_EI10_clicked()
{
    playerMove(8,9);

}

void onePlayerGame::on_EJ1_clicked()
{
    playerMove(9,0);

}

void onePlayerGame::on_EJ2_clicked()
{
    playerMove(9,1);

}

void onePlayerGame::on_EJ3_clicked()
{
    playerMove(9,2);

}

void onePlayerGame::on_EJ4_clicked()
{
    playerMove(9,3);

}

void onePlayerGame::on_EJ5_clicked()
{
    playerMove(9,4);

}

void onePlayerGame::on_EJ6_clicked()
{
    playerMove(9,5);

}

void onePlayerGame::on_EJ7_clicked()
{
    playerMove(9,6);

}

void onePlayerGame::on_EJ8_clicked()
{
    playerMove(9,7);

}

void onePlayerGame::on_EJ9_clicked()
{
    playerMove(9,8);

}

void onePlayerGame::on_EJ10_clicked()
{
    playerMove(9,9);

}

void onePlayerGame::playerMove(int row, int column)
{
    gmode = ui->mode->text();
    int gameFlag = 0;
    int hFlag=0,vFlag=0; // For assuming the ship's orientation.
    int hitValue;
    QMutableListIterator<int> i(nexthit);
    if (placingShips == 0 && turn == 1 && eBoard[row][column] != 2){
        if(eBoard[row][column] == 9){
            eBoard[row][column] = 2;
            eBoardPtr[row][column]->setStyleSheet("background-color: red");
        }
        else{
            eBoard[row][column] = 2;
            eBoardPtr[row][column]->setStyleSheet("background-color: white");
        }
        turn = 0;
        //pBoardPtr[column][row]->click();

        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                if(eBoard[i][j] == 9){
                    gameFlag = 1;
                }
            }
        }
        if (gameFlag == 0){
            ui->quitButton->setText("Main Menu");
            ui->winLabel->show();
            ui->winLabel->setText("You Win!");
        }
        else{
            playerMove(column, row);
        }

    }
    else if (placingShips == 0 && turn == 0)
    {
        //Easy mode
        if(gmode=="Easy")
        {
            generateRandom();
            if(pBoard[row][column] == 9){
                 pBoard[row][column] = 2;

                 //sets burning image after explosion image.
                 burRow = row;
                 burColumn = column;


                 connect(expmovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
                 expmovie->start();
                 expmovie->setSpeed(100);
                 QTimer::singleShot(1000,this , SLOT(animationQuit()));
            }
            else
            {
                pBoardPtr[row][column]->setStyleSheet({"background-image: url(C:/Users/vravic2/Desktop/3/3/wmis.png); "
                                                      "background-color:rgba(255, 255, 255, 0);"
                                                      "border: 1px solid black"});

                pBoard[row][column] = 3;

            }
        }
         //Hard mode
        else
        {
           if(nexthit.size()==0)
                generateRandom();
           else
           {
             // Making our AI to move horizontally or vertically if there is a hit.
               i.toBack();
               while (i.hasPrevious())
                   hitValue = i.previous();
                   i.remove();
                   row =hitValue/10;
                   column =hitValue%10;
                   //removes the duplicates in the list.
                   if(nexthit.contains(hitValue))
                       nexthit.removeOne(hitValue);
           }
           //If there is a HIT
           if(pBoard[row][column] == 9){
                pBoard[row][column] = 2;
                pBoardPtr[row][column]->setStyleSheet("background-color: red");

                //Ai decides the ship in vertical position
                if((pBoard[row-1][column] ==2) || (pBoard[row+1][column] ==2))
                    vFlag = 1;
                //Ai decides the ship in Horizontal position
                else if((pBoard[row][column-1] ==2) || (pBoard[row][column+1] ==2))
                    hFlag = 1;

                //Guess around for an unfinished ship[Adds values into list(excluding white,red, beyond edge values)]
                if(pBoard[row-1][column] != 3 && pBoard[row-1][column] != 2 && row-1>=0 && hFlag == 0)
                  nexthit << concat(row-1,column);
                if(pBoard[row+1][column] != 3 && pBoard[row+1][column] !=2 && ((row+1)/10) != 1 && hFlag == 0)
                   nexthit << concat(row+1,column);
                if(pBoard[row][column-1] != 3 && pBoard[row][column-1] != 2 && column-1>=0 && vFlag == 0)
                   nexthit << concat(row,column-1);
                if(pBoard[row][column+1] != 3 && pBoard[row][column+1] != 2 && ((column+1)/10) != 1 && vFlag == 0)
                   nexthit << concat(row,column+1);
            }
            else
            {

                pBoardPtr[row][column]->setStyleSheet("background-image: url(C:/Users/vravic2/Desktop/3/3/wmis.png); ");
                pBoard[row][column] = 3;
            }
        }
        turn = 1;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                if(pBoard[i][j] == 9){
                    gameFlag = 1;
                }
            }
        }
        if (gameFlag == 0){
            ui->quitButton->setText("Main Menu");
            ui->winLabel->show();
            ui->winLabel->setText("You Lose!");
        }
    }
    else{
        return;
    }
}
QList<int> onePlayerGame::generateRandom()
{
    int row, column, randomNb,randonFlag=0;
    while(randonFlag!=1)
    {
        row = rand() % 10;
        column = rand() % 10;
        randomNb = concat(row,column);
        if(!results.contains(randomNb))
        {
           randonFlag = 1;
           results << randomNb;
        }
        else
          randonFlag = 0;
        if(pBoard[row][column]==2 ||pBoard[row][column]==3)
          randonFlag = 0;
     }
    return results;

}

int onePlayerGame::concat(int x,int y)
{
  int times = 1;
  while (times <= y)
       times *= 10;
  if(y==0)
    times=10;
  return (x)*times + y;
}

void onePlayerGame::on_quitButton_clicked()
{
    QMessageBox::StandardButton answer;
    answer = QMessageBox::question(this, "Main Menu?",
                      "Go back to Main Menu?");

    if(answer == QMessageBox::Yes){
        this->close();
    }
}

void onePlayerGame::on_exitButton_clicked()
{
    QMessageBox::StandardButton answer;
    answer = QMessageBox::question(this, "Exit?",
                      "Are you sure you want to Exit?");

    if(answer == QMessageBox::Yes){
        exit(-1);
    }
}

void onePlayerGame::on_verticalButton_clicked()
{
    orientation = 1;
}

void onePlayerGame::on_horizontalButton_clicked()
{
    orientation = 0;
}

void onePlayerGame::initAiBoard(){
    eBoard[1][9] = 9;
    eBoard[2][9] = 9;
    eBoard[3][9] = 9;
    eBoard[4][9] = 9;
    eBoard[5][9] = 9;

    eBoard[3][1] = 9;
    eBoard[3][2] = 9;
    eBoard[3][3] = 9;

    eBoard[3][5] = 9;
    eBoard[4][5] = 9;
    eBoard[5][5] = 9;

    eBoard[0][5] = 9;
    eBoard[0][6] = 9;
    eBoard[0][7] = 9;
    eBoard[0][8] = 9;

    eBoard[7][6] = 9;
    eBoard[8][6] = 9;

}
