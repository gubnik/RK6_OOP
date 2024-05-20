#pragma once

#include "board.hpp"
#include "piece_types.hpp"

#include "../config.hpp"

#include <iostream>

namespace chess::render
{
    /*
     * TODO: Implement X11 and ncurses
     * Class for rendering a chess board into std::cout
     */
    class renderer
    {
        public:
            renderer() {}
        private:
            void collect (board);
            void draw ();
        public:
            void render (board);
        private:
            render_board_t<8> ToRender;
    };
}
