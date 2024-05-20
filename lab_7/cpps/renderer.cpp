#include "../bits/renderer.hpp"

using namespace chess::render;

void renderer::collect (board Board)
{
    for (loc_t i = 0; i < 64; i++)
    {
        if (Board.data()[i].type()) ToRender[i] = Board.data()[i].type()->display();
        else ToRender[i] = ' ';
    }
}

void renderer::draw ()
{
    for (loc_t x = 0; x < 8; x++)
    {
        std::cout << 8 - x << ' ';
        for (loc_t y = 0; y < 8; y++)
        {
            char r = ToRender[x * 8 + y];
#if defined (HIGH_CONTRAST)
            const char * dec = (r == ' ')
                ? ((x + y + 1) % 2) ? "\033[0;101m" : "\033[0;102m"
                : ((x + y + 1) % 2) ? "\033[0;91m" : "\033[0;92m";
#else
            const char * dec = (r == ' ')
                ? ((x + y + 1) % 2) ? "\033[0;100m" : "\033[0;107m"
                : ((x + y + 1) % 2) ? "\033[0;90m" : "\033[0;97m";
#endif
            std::cout << dec << r << "\033[0m" << ' ';
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
