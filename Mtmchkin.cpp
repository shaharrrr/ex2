//
// Created by dror6 on 04/05/2022.
//

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    m_status = GameStatus::MidGame;
    Player player(playerName);
    m_player = player;
    m_cards = new Card [numOfCards];
    for(int i = 0; i < numOfCards; ++i)
    {
        m_cards[i] = (cardsArray[i]);
    }
    delete[] cardsArray;
    m_currentCard = 0;
    m_numOfCards = numOfCards;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}


GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

void Mtmchkin::playNextCard()
{
    m_cards[m_currentCard].printInfo();
    m_cards[m_currentCard].applyEncounter(m_player);
    m_player.printInfo();
    if(m_currentCard == m_numOfCards-1)
    {
        m_currentCard = 0;
    }
    else
    {
        m_currentCard += 1;
    }
    setStatus();
}

void Mtmchkin::setStatus()
{
    if(m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    else if(m_player.getLevel() == 10)
    {
        m_status = GameStatus::Win;
    }
}


bool Mtmchkin::isOver()
{
    if(m_status == GameStatus::Win || m_status == GameStatus::Loss)
    {
        return true;
    }
    return false;
}