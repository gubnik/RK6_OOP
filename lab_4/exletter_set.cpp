#include "exletter_set.hpp"

#include <string>
#include <bitset>
#include <stdexcept>
#include <cctype>

rk6::exletter_set::exletter_set (const char * p)
{
	for ( ; *p ; ++p)
	{
		if (!isalpha(*p)) throw std::runtime_error ("rk6::exletter_set only supports latin alphabet characters");
		if (islower(*p)) encoded[0] |= (1 << (*p - 'a'));
		else (isupper(*p)) encoded[1] |= (1 << (*p - 'A'));
	}
}

uint32_t rk6::exletter_set::get_encoded_lower ()
{
	return encoded [0];
}

uint32_t rk6::exletter_set::get_encoded_upper ()
{
	return encoded [1];
}

rk6::exletter_set rk6::exletter_set::operator& (const rk6::exletter_set& exlset)
{
	rk6::exletter_set temp;
	temp.encoded[0] = this -> encoded[0] & exlset.encoded[0];
	temp.encoded[1] = this -> encoded[1] & exlset.encoded[1];
	return temp;
}

rk6::exletter_set::operator char * ()
{
	static std::string ret_str;
	ret_str = "";
	std::bitset<26> bits_lower (this -> encoded [0]);
	std::bitset<26> bits_upper (this -> encoded [1]);
	for (std::size_t i = 0; i < 26; i++) if (bits_lower[i]) ret_str += (i + 'a');
	for (std::size_t i = 0; i < 26; i++) if (bits_upper[i]) ret_str += (i + 'A');
	return const_cast<char *>(ret_str.data());
}

uint32_t rk6::exletter_set::operator, (const rk6::exletter_set& exlset)
{
	uint32_t ret = 0;
	rk6::exletter_set combined = *this & exlset;
	uint32_t blower = combined.encoded[0];
	while (blower)
	{
		blower &= (blower - 1);
		ret++;
	}
	uint32_t bupper = combined.encoded[1];
	while (bupper)
	{
		bupper &= (bupper - 1);
		ret++;
	}
	return ret;
}
