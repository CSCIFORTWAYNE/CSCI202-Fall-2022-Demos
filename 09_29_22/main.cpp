#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "card.h"
#include "stackType.h"
#include "queue.h"
#include "unorderedLinkedList.h"

void setupDeck(std::set<card> &);
void setupStock(std::set<card> &, stackType<card> &);
void dealCards(stackType<card> &, unorderedLinkedList<card>[], int);

int main()
{
    srand(time(0));
    std::set<card> deck;
    setupDeck(deck);
    stackType<card> stockpile(52);
    unorderedLinkedList<card> hands[4];
    setupStock(deck, stockpile);
    dealCards(stockpile, hands, 4);

    /*for(std::set<card>::iterator c = deck.begin(); c != deck.end(); ++c)
    {
        std::cout << *c << std::endl;
    }*/
    for (int i = 0; i < 4; i++)
    {
        std::cout << "The hand for player " << i + 1 << std::endl;
        std::cout << hands[i].print() << std::endl;
    }
    std::string cardSuit;
    std::cout << "Pick a card suit (Heart, Diamond, Club, Spade): " << std::endl;
    std::cin >> cardSuit;
    std::transform(cardSuit.begin(), cardSuit.end(), cardSuit.begin(), ::tolower);
    if(strToSuit.count(cardSuit))
    {
        std::cout << "You picked a valid suit" << std::endl;
    }

    return 0;
}

void setupDeck(std::set<card> &deck)
{
    for (std::set<suitType>::const_iterator s = suits.begin(); s != suits.end(); ++s)
    {
        std::cout << "Creating " << suitToStr.at(*s) << " cards" << std::endl;
        for (std::set<faceType>::const_iterator f = faces.begin(); f != faces.end(); ++f)
        {
            deck.insert(card(*s, *f));
        }
    }
}

void setupStock(std::set<card> &deck, stackType<card> &stock)
{
    queue<card> cards(52);
    for (std::set<card>::iterator c = deck.begin(); c != deck.end(); ++c)
    {
        cards.enqueue(*c);
    }

    while (!stock.isFullStack() && !cards.isEmptyQueue())
    {
        int num = rand() % 52;
        for (int i = 0; i < num; i++)
        {
            cards.enqueue(cards.dequeue());
        }
        stock.push(cards.dequeue());
    }
}

void dealCards(stackType<card> &stock, unorderedLinkedList<card> hands[], int numItems)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < numItems; j++)
        {
            hands[j].insert(stock.pop());
        }
    }
}