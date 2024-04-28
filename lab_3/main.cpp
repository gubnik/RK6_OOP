#include "letter_set.hpp"

#include <string>

int main (int argc, char ** argv)
{
	// If bad arguments passed, throw an error
	if (argc != 3)
		throw std::invalid_argument ("Must pass 2 strings as an argument");
	
	// Creating sets for provided strings + a combined set of both strings
	rk6::letter_set first_set (argv[1]);
	rk6::letter_set second_set (argv[2]);
	rk6::letter_set combined_set ((std::string(argv[1]) + std::string(argv[2])).data());
	
	// Printing it out, easy as that
	std::cout << "First set : " << first_set << '\n';
	std::cout << "Second set : " << second_set << '\n';
	std::cout << "Combined set : " << combined_set << '\n';
	std::cout << "Reoccuring characters : " << (combined_set ^ (first_set ^ second_set)) << '\n';
	std::cout << "Missing characters : " << ~combined_set << '\n';

	return 0;
}
