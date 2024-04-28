#include "geom.hpp"

int main (int argc, char ** argv)
{
    if (argc % 4 == 0) throw std::invalid_argument ("Must pass doubles for pairs of pairs of vertices");
    for (std::size_t i = 0; i < argc / 4; i++)
    {
        rk6::line l (rk6::vertex(atof(argv[4 * i + 1]), atof(argv[4 * i + 2])),
                     rk6::vertex(atof(argv[4 * i + 3]), atof(argv[4 * i + 4])));
        std::cout << "Line '" << l << "' is " << l.distance_from_zero() << " units away from (0, 0)\n";
    }
    return 0;
}
