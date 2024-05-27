#pragma once

#include <map>
#include <fstream>
#include <string>

namespace rk6
{
    /* Class for performing a search within a file
     * Could be made into a function for this specific task
     * Left as a class due to OOP requirement
     */
    class fsearch
    {
        // I love aliases
        using search_data = std::map<std::size_t, std::string>;
        public:
            fsearch (const std::string&);
            search_data run_search (std::size_t);
        private:
            std::fstream File;
    };
}
