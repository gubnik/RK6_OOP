#pragma once

#include "dlist.hpp"

namespace rk6
{
    class dlstring;
    class dlstring : public list<char>
    {
        public:
            dlstring () {}
            dlstring (const char * p)
            {
                for (; *p; ++p) this->push_front(*p);
            }
    };
}

rk6::dlstring operator""_dl (const char * p, std::size_t n)
{
    rk6::dlstring ret {};
    for (std::size_t i = 0; i < n; i++) ret.push_front (p[i]);
    return ret;
}
