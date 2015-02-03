#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class board;
}

class board : public QWidget
{
    Q_OBJECT

public:
     int Rows;
     int Columns;
     QGridLayout* layout;
     void makeBoard(int rows, int columns);

    explicit board(QWidget *parent = 0);
    ~board();

private slots:
    void Exit(QPushButton* button);

private:

     Ui::board *ui;
};

#endif // BOARD_H
