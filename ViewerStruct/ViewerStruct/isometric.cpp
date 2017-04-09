#include "isometric.h"

Point_2d to_isometric_view(Point& point)
{
    const double sin = sqrt(2) / 4;

    Point_2d new_point;
    new_point.x = point.x - point.z * sin;
    new_point.y = point.z * sin - point.y;

    return new_point;
}

