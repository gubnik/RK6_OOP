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

    class piece_type
    {
        public:
            virtual bool move    (field, field) = 0;
            virtual bool attack  (field, field) = 0;
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
