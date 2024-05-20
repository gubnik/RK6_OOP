#include "../bits/board.hpp"

#include <iostream>

using namespace chess;

board::board ()
{
    for (loc_t y = 0; y < 8; y++) for (loc_t x = 0; x < 8; x++)
    {
        Data[x * 8 + y] = field (x, y, nullptr);
    }
}

board_t<8> board::data() { return Data; }

field * board::get (loc_t x, loc_t y)
{
    return &Data[x * 8 + y];
}

field * board::set (loc_t x, loc_t y, piece_type * ntype)
{
    //std::cout << (int)x << ' ' << (int)y << '\n';
    Data[x * 8 + y] = field (x, y, ntype);
    return &Data[x * 8 + y];
}
