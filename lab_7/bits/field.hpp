#pragma once

#include "piece.hpp"
#include "piece_types.hpp"

namespace chess
{
    /*
     * Class for a field of a board
     */
    class field
    {
        public:
            /* Default constructor
             */
            field () : X(0), Y(0), TypePtr(nullptr) {}
            /* Another constructor
             */
            field (loc_t x, loc_t y, piece_type * typeref)
                : X (x), Y (y), TypePtr (typeref) {}
            /* Validates a move to another field
             * @param field1    Target field
             */
            bool move (field);
            /* Getter for X */
            loc_t x ();
            /* Getter for Y */
            loc_t y ();
            /* Getter for TypePtr */
            piece_type * type () { return TypePtr; }
        private:
            // X coord of a field
            loc_t X;
            // X coord of a field
            loc_t Y;
            // Piece type on a field
            piece_type * TypePtr;
    };
}
