#include "chess"

int main (int argc, char ** argv)
{
    // Creating a board
    chess::board Board;
    // Buffering a pointer to piece type we're using
    chess::piece_type * type = &chess::pieces::TZAR;
    // Pointer to a field with a piece
    chess::field * field_ptr;
    // If a second argument was provided, parse it into a location
    if (argc == 2)
    {
        const char x = argv[1][0];
        const char y = argv[1][1];
        const int py = ((x > 'h') ? 'h' : (x < 'a') ? 'a': x) - 'a';
        const int px = 8 - (((y > '8') ? '8' : (y < '1') ? '1' : y) - '1') - 1;
        field_ptr = Board.set(px, py, type);
    }
    // ...else set a default
    else field_ptr= Board.set(4, 3, type);
    // Creating a renderer
    chess::render::renderer Renderer;
    // Rendering a single frame
    Renderer.render(Board);
    // Variables for entering a position
    chess::loc_t x, y;
    // Entering a location in a standard notation i.e. "a5", "e8" etc.
    while (std::cin >> x >> y)
    {
        // Calculating a new location in board's array
        const int py = ((x > 'h') ? 'h' : (x < 'a') ? 'a': x) - 'a';
        const int px = 8 - (((y > '8') ? '8' : (y < '1') ? '1' : y) - '1') - 1;
        // If move is impossible, skip to the next iteration with an error message 
        if (!(field_ptr->move(*Board.get(px, py))))
        {
            std::cout << "Unable to make a move\n";
            continue;
        }
        // Putting a null to the previous position
        Board.set(field_ptr->x(), field_ptr->y(), nullptr);
        // Setting a new address of a field with a piece
        field_ptr = Board.set(px, py, type);
        // Rendering the board
        Renderer.render(Board);
    }
}
