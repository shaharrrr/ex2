
#include "Player.h"
#include "utilities.h"
#include <cstring>

Player::Player(const std::string& name, int maxHP, int force)
{
    m_name = name;
    m_level = 1;
    m_force = force;
    m_maxHP = maxHP;
    m_HP = maxHP;
    m_coins = 0;
}


void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level < 10)
    {
        ++m_level;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int increaseBy)
{
    if(increaseBy > 0)
    {
        m_force *= increaseBy;
    }
}

void Player::heal(int increaseBy)
{
    if(increaseBy > 0)
    {
        if(m_HP + increaseBy > m_maxHP)
        {
            m_HP = m_maxHP;
        }
        else
        {
            m_HP += increaseBy;
        }
    }
}

void Player::damage(int decreaseBy)
{
    if(decreaseBy > 0)
    {
        if (m_HP - decreaseBy < 0)
        {
            m_HP = 0;
        }
        else
        {
            m_HP -= decreaseBy;
        }
    }
}

bool Player::isKnockedOut() const
{
    if(m_HP == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int increaseBy)
{
    if(increaseBy > 0)
    {
        m_coins += increaseBy;
    }
}

bool Player::pay(int decreaseBy)
{
    if(decreaseBy < 0 || m_coins < decreaseBy)
    {
        return false;
    }
    m_coins -= decreaseBy;
    return true;
}

int Player::getAttackStrength() const
{
    return (m_level+m_force);
}