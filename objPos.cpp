#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

//Copy Constructor
objPos::objPos( const objPos &a )
{
    pos = new Pos;
    pos->x = a.pos->x;
    pos->y = a.pos->y;
    symbol = a.symbol;

}

//Copy Assignment constructor 
objPos& objPos:: operator=(const objPos &s)
{

    if (this == &s)
        return *this; // Handle self-assignment

    // Delete the existing Pos object to prevent memory leaks
    delete pos;

    // Allocate new memory and copy the data
    this -> pos = new Pos;
    this -> pos->x = s.pos->x;
    this -> pos->y = s.pos->y;
    this -> symbol = s.symbol;

    return *this; // Return the current object to allow chained assignments

}

objPos::~objPos()
{
    delete pos;
}


void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
