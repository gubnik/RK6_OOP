#include "vertex.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>

int main (int argc, char ** argv)
{
	// If arguments provided aren't valid, throw an error
	if (argc < 3 || !(argc % 2))
		throw std::invalid_argument ("Invalid argument passed : must be a list of pair of integers");
	const std::size_t total_pairs = argc / 2;
	// Creating new array to store vertices' addresses
	rk6::vertex ** address_storage = new rk6::vertex*[total_pairs];
	// Creating new vertex instances and storing addresses in the array
	for (std::size_t i = 0; i < total_pairs; i++)
		address_storage [i] = new rk6::vertex (atoi(argv[i * 2 + 1]), atoi(argv[i * 2 + 2]));
	double max_distance = -1;
	rk6::vertex * v1 = nullptr, * v2 = nullptr;
	for (std::size_t i = 0; i < total_pairs; i++)
	for (std::size_t j = 0; j < total_pairs; j++)
	{
		if (address_storage[i]->yx_is_above() == address_storage[j]->yx_is_above()) continue;
		double old_max = max_distance;
		max_distance = std::max(max_distance, address_storage[i]->compute_distance_to(*address_storage[j]));
		if (max_distance > old_max)
		{
			v1 = address_storage[i];
			v2 = address_storage[j];
		}
	}
	if (!v1 || !v2)
		std::cout << "None of vertices adhere to imposed condition\n";
	else std::cout << "Max distance of " << max_distance << " between vertices " << *v1 << ", " << *v2 << '\n';
	return 0;
}
