#ifndef CARD_H
#define CARD_H
#include <set>
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>

enum class suitType
{
    HEARTS,
    SPADES,
    DIAMONDS,
    CLUBS
};
enum class faceType
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

const std::set<suitType> suits = 
{
    suitType::HEARTS, 
    suitType::SPADES, 
    suitType::DIAMONDS, 
    suitType::CLUBS
};
const std::set<faceType> faces = 
{
    faceType::ACE, 
    faceType::TWO, 
    faceType::THREE, 
    faceType::FOUR, 
    faceType::FIVE, 
    faceType::SIX, 
    faceType::SEVEN, 
    faceType::EIGHT, 
    faceType::NINE, 
    faceType::TEN, 
    faceType::JACK, 
    faceType::QUEEN, 
    faceType::KING
};
const std::map<suitType, std::string> suitToStr = 
{
    {suitType::HEARTS, "♥"}, 
    {suitType::SPADES, "♠"}, 
    {suitType::DIAMONDS, "♦"}, 
    {suitType::CLUBS, "♣"}
};

const std::map<faceType, std::string> faceToStr =
{
    {faceType::ACE, "A"}, 
    {faceType::TWO, "2"}, 
    {faceType::THREE,"3"}, 
    {faceType::FOUR, "4"}, 
    {faceType::FIVE, "5"}, 
    {faceType::SIX, "6"}, 
    {faceType::SEVEN, "7"}, 
    {faceType::EIGHT, "8"}, 
    {faceType::NINE, "9"}, 
    {faceType::TEN, "10"}, 
    {faceType::JACK, "J"}, 
    {faceType::QUEEN, "Q"}, 
    {faceType::KING, "K"}
};
const std::map<std::string, suitType> strToSuit =
{
    {"heart",suitType::HEARTS}, 
    {"spade",suitType::SPADES}, 
    {"diamond",suitType::DIAMONDS}, 
    {"club",suitType::CLUBS}
};

class card
{
public:
    card(suitType = suitType::HEARTS, faceType = faceType::ACE);
    void setSuit(suitType);
    void setFace(faceType);
    suitType getSuit();
    faceType getFace();
    bool operator<(const card &) const;
    bool operator==(const card&) const;
    bool operator!=(const card&) const;
    friend std::ostream& operator<<(std::ostream&, const card&);

private:
    suitType suit;
    faceType face;
};

#endif