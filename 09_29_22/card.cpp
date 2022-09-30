#include "card.h"

card::card(suitType s, faceType f)
{
    setSuit(s);
    setFace(f);
}
void card::setSuit(suitType s)
{
    if(suits.count(s))
        suit = s;
    else 
        throw std::out_of_range("Suit not recognized");
}
void card::setFace(faceType f)
{
    if(faces.count(f))
        face = f;
    else    
        throw std::out_of_range("Face not recognized");
}
suitType card::getSuit()
{
    return suit;
}
faceType card::getFace()
{
    return face;
}
bool card::operator<(const card& oc) const
{
    return this->suit < oc.suit || this->face < oc.face;
}

bool card::operator==(const card& oc) const
{
    return this->suit == oc.suit && this->face == oc.face;
}
bool card::operator!=(const card& oc) const
{
    return this->suit != oc.suit || this->face != oc.face;
}

std::ostream& operator<<(std::ostream& out, const card& c)
{
    out << faceToStr.at(c.face) << suitToStr.at(c.suit);
    return out;
}