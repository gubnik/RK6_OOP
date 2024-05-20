#pragma once

#include <array>

namespace chess
{
    using loc_t = char;
    using color = bool;

    class piece_type;
    class field;

    template <loc_t Size> using board_t = std::array<field, Size * Size>;
    template <loc_t Size> using render_board_t = std::array<char, Size * Size>;

    /*
     * Abstract class for a chess piece
     */
    class piece_type
    {
        public:
            /* Validates a general move
             * @param field1    Current field
             * @param field2    Target field
             */
            virtual bool move    (field, field) = 0;
            /* Validates a move that attacks another piece
             * @param field1    Current field
             * @param field2    Target field
             */
            virtual bool attack  (field, field) = 0;
            /* Character associated with a piece
             */
            virtual char display () = 0;
    };
    
    class king_type : public virtual piece_type
    {
        public:
            bool move    (field, field) override;
            bool attack  (field, field) override;
            char display () override;
    };
    
    class knight_type : public virtual piece_type
    {
        public:
            bool move   (field, field) override;
            bool attack (field, field) override;
            char display () override;
    };
    
    class tzar_type : public king_type, public knight_type
    {
        public:
            bool move   (field, field) override;
            bool attack (field, field) override;
            char display () override;
    };
}
