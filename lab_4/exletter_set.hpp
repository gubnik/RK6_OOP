#pragma once

#include <cstdint>

namespace rk6
{
	class exletter_set
	{
		private:
			uint32_t encoded [2] = {0};

		public:
			exletter_set () {}
			exletter_set (const char *);
			uint32_t get_encoded_lower ();
			uint32_t get_encoded_upper ();
			exletter_set operator& (const exletter_set&);
			operator char * ();
			uint32_t operator, (const exletter_set&);
	};
}
