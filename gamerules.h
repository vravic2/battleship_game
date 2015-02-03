#ifndef GAMERULES_H
#define GAMERULES_H

#include <QDialog>

namespace Ui {
class GameRules;
}

class GameRules : public QDialog
{
    Q_OBJECT

public:
    explicit GameRules(QWidget *parent = 0);
    ~GameRules();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameRules *ui;
};

#endif // GAMERULES_H
