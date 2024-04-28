#include "letter_set.hpp"

#include <stdexcept>
#include <bitset>
#include <cctype>

rk6::letter_set::letter_set (const char * p)
{
    encoded = 0;
    for ( ; *p; ++p)
    {
        if (!isalpha(*p)) throw std::runtime_error ("rk6::letter_set only supports latin alphabet characters");
        encoded |= (1 << (tolower(*p) - 'a'));
    }
}

uint32_t rk6::letter_set::get_encoded ()
{
    return encoded;
}

rk6::letter_set rk6::letter_set::operator~ ()
{
    letter_set temp;
    temp.encoded = ~this->encoded;
    return temp;
}

rk6::letter_set rk6::letter_set::operator^ (const letter_set& lset)
{
    letter_set temp;
    temp.encoded = this->encoded ^ lset.encoded;
    return temp;
}

std::ostream& rk6::operator<< (std::ostream& out, letter_set lset)
{
    std::bitset<26> bin (lset.get_encoded());
    for (std::size_t i = 0; i < 26; i++)
        if (bin[i]) out << (char)('a' + i);
    return out;
}
