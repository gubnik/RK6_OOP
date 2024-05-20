#include "../bits/piece.hpp"
#include "../bits/field.hpp"

using namespace chess;

#include <iostream>

bool king_type::move (field F, field T)
{
    const loc_t dx = std::abs(F.x() - T.x());
    const loc_t dy = std::abs(F.y() - T.y());
    return (dx == 1 && dy == 0) || (dy == 1 && dx == 0) || (dx == 1 && dy == 1);
}

bool king_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char king_type::display () { return 'K'; }

bool knight_type::move (field F, field T)
{
    const loc_t dx = std::abs(F.x() - T.x());
    const loc_t dy = std::abs(F.y() - T.y());
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

bool knight_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char knight_type::display () { return 'k'; }

bool tzar_type::move (field F, field T)
{
    return king_type::move(F, T) || knight_type::move(F, T);
}

bool tzar_type::attack (field F, field T)
{
    return this->move(F, T);
}

inline char tzar_type::display () { return 'Z'; }
