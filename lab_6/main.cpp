#include "dlstring.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>

int main (int argc, char ** argv)
{
    // Throw if bad arguments passed
    if (argc != 2)
        throw std::invalid_argument ("main.cpp::main(int, char**)");
    
    // Make a dlstring
    rk6::dlstring L0 = argv[1];
    
    // Find min & max values in string (STL function)
    const auto max_val = *std::max_element(L0.begin(), L0.end());
    const auto min_val = *std::min_element(L0.begin(), L0.end());
    
    // Find size of dlstring
    const auto size = L0.size();
    
    // cmdist - current max distance
    // max - max index
    // min - min index
    std::size_t cmdist = 0;
    std::size_t max = 0, min = 0;
    
    // Iterate over each node of string, squared
    for (long i = 0; i < size; i++)
    {
        for (long j = 0; j < size; j++)
        {
            auto inode = L0.get(i);
            auto jnode = L0.get(j);
            // If distance is less than cmdist or looking at the same node - skip to next loop iteration
            if (fabs(i - j) < cmdist || i == j) continue;
            // If a pair of min/max has been found and it's more than cmdist apart - buffer this pair into vars
            if ((inode->value == max_val) && (jnode->value == min_val))
            {
                max = i; min = j;
                cmdist = fabs(i - j);
            }
        }
    }
    // Regular dlstring out
    for (auto& it : L0) std::cout << it; std::cout << '\n';
    // ^ decorations out
    for (std::size_t i = 0; i < size; i++) std::cout << ((i == max || i == min) ? '^' : ' '); std::cout << '\n';
    // Swap nodes at max and min indices
    L0.stupid_swap(L0.get(max), L0.get(min));
    // Swapped dlstring out
    for (auto& it : L0) std::cout << it; std::cout << '\n';
}
