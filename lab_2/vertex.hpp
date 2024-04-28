#pragma once

#include <iostream>

namespace rk6
{
    class vertex
    {
        private:
            double x;
            double y;
        public:
            vertex (double _x = 0, double _y = 0)
                : x (_x), y (_y)
            {
            }

            double get_x ();
            double get_y ();
            double compute_distance_to (rk6::vertex);
            static rk6::vertex polar (double, double);
    };
    std::ostream& operator<< (std::ostream&, rk6::vertex&);
}


