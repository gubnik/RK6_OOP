#pragma once

#include <iostream>

namespace rk6
{
    class vertex;
    class line;

    std::ostream& operator<< (std::ostream&, rk6::vertex);
    std::ostream& operator<< (std::ostream&, rk6::line);

    class vertex
    {
        friend class line;
        friend std::ostream& rk6::operator<< (std::ostream&, rk6::vertex);

        private:
            double x;
            double y;
       
        public:
            vertex (double _x = 0, double _y = 0) : x (_x), y (_y) {}
            double get_x ();
            double get_y ();

    };

    class line
    {
        friend std::ostream& rk6::operator<< (std::ostream&, rk6::line);
        private:
            vertex v1, v2;

        public:
            line (vertex _v1 = {}, vertex _v2 = {}) : v1 (_v1), v2 (_v2) {}
            double distance_from_zero ();
    };
}
