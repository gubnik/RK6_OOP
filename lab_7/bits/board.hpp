#pragma once

#include "field.hpp"

namespace chess
{
    /* Class for a chess board
     */
    class board
    {
        public:
            board ();
            board_t <8> data();
            field * get (loc_t, loc_t);
            field * set (loc_t, loc_t, piece_type *);
        private:
            board_t <8> Data;
    };
}
