//
// Created by dror6 on 04/05/2022.
//

#ifndef MTMCHKIN_PLAYER_H
#define MTMCHKIN_PLAYER_H
#include <string>

class Player {
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
public:
    /*
     * C'tor of Player class:
     *
     * @param name - The name of the player.
     * @param maxHp - The max value of the player's HP.
     * @param force - The initial force of the player.
     * @result
     *      A new instance of Player
     */
    Player(const std::string& name, int maxHP = 100, int force = 5);

    /*
    * C'tor to the "default player" - A player with the deafuilt name "", level 1, force 5, maxHP 100, HP 100, coins 0.
    */
    Player(): m_name(""), m_level(1), m_force(5), m_maxHP(100), m_HP(100), m_coins(0) {}

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    /*
     * Printing the Player's information on the screen:
     *
     * @return
     *      void
    */
    void printInfo() const;


    /*
     * Increasing the Player's level bt 1, if the current level is 10, does nothing:
     *
     * @return
     *      void
    */
    void levelUp();

    /*
     * Returning the Player's level:
     *
     * @return
     *      The Player's level
    */
    int getLevel() const;

    /*
     * Increasing the player's force by a given value:
     *
     * @param increaseBy - The value by which the force is increased.
     * @return
     *      void
    */
    void buff(int increaseBy);

    /*
     * Increasing the player's HP by a given value:
     *
     * @param increaseBy - The value by which the HP is increased.
     * @return
     *      void
    */
    void heal(int increaseBy);

    /*
     * Decreasing the player's HP by a given value:
     *
     * @param decreaseBy - The value by which the HP is decreased.
     * @return
     *      void
    */
    void damage(int decreaseBy);

    /*
     * Checking if the player's HP is zero:
     *
     * @return
     *      true - if the player's HP is zero.
     *      false - else.
    */
    bool isKnockedOut() const;

    /*
     * Increasing the player's coins by a given value:
     *
     * @param increaseBy - The value by which the coins are increased.
     * @return
     *      void
    */
    void addCoins(int increaseBy);

    /*
     * Decreasing the player's coins by a given value, if possible:
     *
     * @param decreaseBy - The value by which the coins are decreased.
     * @return
     *      true - if the paymemt was successful (the player had enough coins).
     *      false - else.
    */
    bool pay(int decreaseBy);

    /*
     * Returning the player's attack strength (level+force):
     *
     * @return
     *      The player's attack strength.
    */
    int getAttackStrength() const;


};


#endif //MTMCHKIN_PLAYER_H
