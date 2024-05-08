#pragma once

#include "dlist.hpp"

namespace rk6
{
    /*
     * I could just do
     *   using dlstring = rk6::list<char>;
     */
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

