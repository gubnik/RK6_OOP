#pragma once

#include <iostream>

namespace rk6
{
	class vertex
	{
		private:
			int x;
			int y;
		public:
			vertex (int _x = 0, int _y = 0)
				: x (_x), y (_y)
			{
			}

			int get_x ();
			int get_y ();
			bool yx_is_above ();
			double compute_distance_to (vertex);
	};
	std::ostream& operator<< (std::ostream&, rk6::vertex&);
}


