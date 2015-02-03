#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    ~Player();

   /* int getRemainShips();
    int addPlayerCash(int playerNumber, int amount);
    int getPlayerCash(int amount);*/

protected:
    /* move to human player class
    QString name;
    QString email;
    QString country;
    int age;
    */

   /* FleetShip* ships[6];
    int playerNumber;
    int playerCash;
    Weapon* playerWeapon;*/
    int playerBoard [10][10];

};


class AIPlayer : public Player
{
public:
    AIPlayer();
};


class HumanPlayer : public Player
{
public:
    HumanPlayer();
};

#endif // PLAYER_H
