#include "exletter_set.hpp"

#include <stdexcept>
#include <iostream>

int main (int argc, char ** argv)
{
	if (argc != 3) throw std::invalid_argument ("Must pass 2 strings as arguments");
	rk6::exletter_set first_set (argv[1]);
	rk6::exletter_set second_set (argv[2]);
	std::cout << "Reoccuring characters : " << (char*)(first_set & second_set) << " (total : "
		<< (first_set, second_set) << ")\n";
	return 0;
}
