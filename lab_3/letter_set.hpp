#pragma once

#include <cstdint>
#include <iostream>

namespace rk6
{
	class letter_set
	{
		private:
			uint32_t encoded;

		public:
			letter_set () : encoded (0) {}
			letter_set (const char *);
			uint32_t get_encoded ();
			letter_set operator~ ();
			letter_set operator^ (const letter_set&);
			letter_set operator& (const letter_set&);
	};
	std::ostream& operator<< (std::ostream&, letter_set);
}
