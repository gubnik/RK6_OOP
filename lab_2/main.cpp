#include "vertex.hpp"

#include <cmath>
#include <stdexcept>

int main (int argc, char ** argv)
{
    // If bad arguments passed, throw an error
    if (argc != 4)
        throw std::invalid_argument ("Arguments must consist of 3 doubles: 2 for vertex coordinates, 1 for distance");
    
    // Creating a vertex object with provided coordinates
    rk6::vertex provided (atof(argv[1]), atof(argv[2]));
    
    // Calculate an angle between OX and a line from (0, 0) to a provided vertex
    const double angle = (!provided.get_x() && !provided.get_y()) ? atan(1) : atan(provided.get_y() / provided.get_x());
    
    // Create a vertex that lies on an imaginary circle using a static method
    rk6::vertex on_circle = rk6::vertex::polar(angle, atof(argv[3]));

    // Print the result in std::cout
    std::cout << "Vertex on a circle " << on_circle << " has a distance of "
        << provided.compute_distance_to(on_circle) << " from a provided vertex " << provided << " \n";
    return 0;
}
