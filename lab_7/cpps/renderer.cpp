#include "../bits/renderer.hpp"

using namespace chess::render;

void renderer::collect (board Board)
{
#if defined (RENDER_DANGER)
#define DANGER '.' 
    for (loc_t i = 0; i < 64; i++)
    {
        if (Board.data()[i].type()) ToRender[i] = Board.data()[i].type()->display();
        else ToRender[i] = ' ';
    }
    std::array<loc_t, 64> danger;
    loc_t c = 0;
    for (loc_t i = 0; i < 64; i++)
    {
        if (ToRender[i] != ' ')
        {
            piece_type * tptr = Board.data()[i].type();
            if (!tptr) continue;
            for (loc_t j = 0; j < 64; j++)
            {
                if (i == j) continue;
                if (tptr->move(Board.data()[i], Board.data()[j])) ToRender[j] = DANGER;
            }
        }
    }
#else
    for (loc_t i = 0; i < 64; i++)
    {
        if (Board.data()[i].type()) ToRender[i] = Board.data()[i].type()->display();
        else ToRender[i] = ' ';
    }
#endif
}

void renderer::draw ()
{
    for (loc_t x = 0; x < 8; x++)
    {
        std::cout << 8 - x << ' ';
        for (loc_t y = 0; y < 8; y++)
        {
            char r = ToRender[x * 8 + y];
#if defined (DISABLE_COLORS)
            const char * dec = "";
#else
#if defined (HIGH_CONTRAST)
            const char * dec = (r == ' ')
                ? ((x + y + 1) % 2) ? "\033[0;101m" : "\033[0;102m"
#if defined (RENDER_DANGER)
                : (r == DANGER)
                ? "\033[0;104m"
#endif
                : ((x + y + 1) % 2) ? "\033[0;91m" : "\033[0;92m";
#else
            const char * dec = (r == ' ')
                ? ((x + y + 1) % 2) ? "\033[0;100m" : "\033[0;107m"
#if defined (RENDER_DANGER)
                : (r == DANGER)
                ? "\033[0;104m"
#endif
                : ((x + y + 1) % 2) ? "\033[0;90m" : "\033[0;97m";
#endif
#endif
            std::cout << dec << r
#ifndef DISABLE_COLORS
                << "\033[0m"
#endif
                << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "  ";
    for (loc_t y = 0; y < 8; y++) std::cout << (char)('a' + y) << ' ';
    std::cout << '\n';
}

void renderer::render (board Board)
{
    collect(Board);
    draw();
}
