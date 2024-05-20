#pragma once

#include "piece.hpp"
#include "piece_types.hpp"

namespace chess
{
    class field
    {
        friend king_type;
        friend knight_type;
        friend tzar_type;

        public:
            field () : X(0), Y(0), TypePtr(nullptr) {}
            field (loc_t x, loc_t y, piece_type * typeref)
                : X (x), Y (y), TypePtr (typeref) {}
            bool move (field);
            loc_t x ();
            loc_t y ();
            piece_type * type () { return TypePtr; }
        private:
            loc_t X;
            loc_t Y;
            piece_type * TypePtr;
    };
}
