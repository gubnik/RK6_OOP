#include "fsearch.hpp"

#include <iostream>
#include <stdexcept>

/* If I ever see code of a kind we were shown during the seminar I'll fucking kill myself
 * THIS is OOP, not that mess of whatever the professor found in usr/include folder
 * THIS is OOP, organised and hierarchical, beautiful in its order
 * THIS is OOP, where an object serves its intended purpose
 * THIS is OOP, praise be!
 */
int main (int argc, char ** argv)
{
    // Throw if bad args
    if (argc < 3)
        throw std::invalid_argument ("main.cpp::main : bad arguments");
    // Make file name and minimal allowed string lenght
    const std::string FileName (argv[1]);
    const std::size_t MinStrSize = atoi(argv[2]);
    if (MinStrSize <= 0)
        throw std::invalid_argument ("main.cpp::main : bad arguments");
    /* Creating fsearch object from a file name
     * It's basically a wrapper around std::fstream so no need for heap alloc
     */
    rk6::fsearch FS (FileName);
    /* I would like to use structure binding so I could write it like
     * for (auto& [id, str] : FS.run_search(MinStrSize))
     * {
     *     std::cout << id << " : " << str << '\n';
     * }
     * but we use C++11
     */
    for (auto& it : FS.run_search(MinStrSize))
    {
        std::cout << it.first << " : " << it.second << '\n';
    }
}
