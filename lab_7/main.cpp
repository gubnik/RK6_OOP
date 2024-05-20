#include "chess"
#include "bits/board.hpp"

int main (int argc, char ** argv)
{
    chess::board Board;
    chess::piece_type * type = &chess::pieces::TZAR;
    chess::field * fptr = Board.set(4, 3, type);
    chess::render::renderer Renderer;
    Renderer.render(Board);
    chess::loc_t x, y;
    while (std::cin >> x >> y)
    {
        const int py = ((x > 'h') ? 'h' : (x < 'a') ? 'a': x) - 'a';
        const int px = 8 - (((y > '8') ? '8' : (y < '1') ? '1' : y) - '1') - 1;
        if (!(fptr->move(*Board.get(px, py))))
        {
            std::cout << "Unable to make a move\n";
            continue;
        }
        Board.set(fptr->x(), fptr->y(), nullptr);
        fptr = Board.set(px, py, type);
        Renderer.render(Board);
    }
}
