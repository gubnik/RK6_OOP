#include "geom.hpp"

#include <cmath>

// Vertex

double rk6::vertex::get_x ()
{
    return x;
}

double rk6::vertex::get_y ()
{
    return y;
}

// Line

double rk6::line::distance_from_zero ()
{
    if (v1.x - v2.x == 0) return v1.x;
    else if (v1.y - v2.y == 0) return v1.y;
    const double slope = (v1.y - v2.y) / (v1.x - v2.x);
    const double y_move = slope * v1.x - v1.y;
    return fabs(y_move) / sqrt(pow(slope, 2) + 1);
}

// Operator Overloads

std::ostream& rk6::operator<< (std::ostream& out, rk6::vertex v)
{
    out << '(' << v.x << ", " << v.y << ')';
    return out;
}

std::ostream& rk6::operator<< (std::ostream& out, rk6::line l)
{
    out << '(' << l.v1 << ", " << l.v2 << ')';
    return out;
}
