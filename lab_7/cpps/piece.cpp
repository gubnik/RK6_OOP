#include "../bits/piece.hpp"
#include "../bits/field.hpp"

//#include "math.h"

#define abs(x) (x < 0) ? -x : x

using namespace chess;

bool king_type::move (field F, field T)
{
    return (abs(F.X - T.X) == 1) || (abs(F.Y -T.Y) == 1);
}

bool king_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char king_type::display () { return 'K'; }

bool knight_type::move (field F, field T)
{
    return ((abs(F.X - T.X) == 2) && (abs(F.Y -T.Y) == 1))
        || ((abs(F.X - T.X) == 1) && (abs(F.Y -T.Y) == 2));
}

bool knight_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char knight_type::display () { return 'k'; }

bool tzar_type::move (field F, field T)
{
    return king_type::move(F, T) || knight_type::move(F, T);
    //return ((king_type*)this)->move(F, T) && ((knight_type*)this)->move(F, T);
}

bool tzar_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char tzar_type::display () { return 'Z'; }
