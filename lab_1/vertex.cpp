#include "vertex.hpp"

#include <cmath>

int rk6::vertex::get_x ()
{
	return x;
}

int rk6::vertex::get_y ()
{
	return y;
}

bool rk6::vertex::yx_is_above ()
{
	return this->y > this->x;
}

double rk6::vertex::compute_distance_to (rk6::vertex V)
{
	return sqrt(pow(V.x - this->x, 2) + pow(V.y - this->y, 2));
}

std::ostream& rk6::operator<< (std::ostream& out, rk6::vertex& vref)
{
	out << '(' << vref.get_x() << ", " << vref.get_y() << ')';
	return out;
}
