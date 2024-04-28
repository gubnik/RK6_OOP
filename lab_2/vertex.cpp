#include "vertex.hpp"

#include <cmath>

double rk6::vertex::get_x ()
{
	return x;
}

double rk6::vertex::get_y ()
{
	return y;
}

double rk6::vertex::compute_distance_to (rk6::vertex v)
{
	return sqrt(pow(v.x - this->x, 2) + pow(v.y - this->y, 2));
}

rk6::vertex rk6::vertex::polar (double angle_in_radians, double distance)
{
	return rk6::vertex (cos(angle_in_radians) * distance, sin(angle_in_radians) * distance);
}

std::ostream& rk6::operator<< (std::ostream& out, rk6::vertex& vref)
{
	out << '(' << vref.get_x() << ", " << vref.get_y() << ')';
	return out;
}
