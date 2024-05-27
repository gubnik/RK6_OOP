#include "fsearch.hpp"

#include <stdexcept>
#include <iostream>

using namespace rk6;

fsearch::fsearch (const std::string& FileName)
{
    File.open(FileName);
    if (!File.is_open())
        throw std::runtime_error("rk6::fsearch::fsearch : unable to open file '" + FileName + "'");
}

fsearch::search_data fsearch::run_search (std::size_t minsize)
{
    // AKA std::map<std::size_t, std::string>
    fsearch::search_data Data;
    std::string S;
    std::size_t counter = 0;
    // BEHOLD! A forbidden technique of knowing the damn overload
    while (File >> S)
    {
        counter++;
        // Easy as that
        if (S.size() > minsize) Data[counter] = S;
    }
    return Data;
}
