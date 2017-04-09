#include "rotation.h"

Errors projections_rotation(Point_2d* points, unsigned size, Point_2d& center, double fi)
{
    Errors error = OK;
    for (unsigned i = 0; (i < size) && (error == OK); ++i)
    {
        error = projection_rotation(points[i], center, fi);
    }

    return error;
}

Errors projection_rotation(Point_2d& point, Point_2d& center, double fi)
{
    double sin_z = sin(fi);
    double cos_z = cos(fi);
    double new_x = center.x + (point.x - center.x) * cos_z - (point.y - center.y) * sin_z;
    double new_y = center.y + (point.y - center.y) * cos_z + (point.x - center.x) * sin_z;
    point.x = new_x;
    point.y = new_y;

    return OK;
}

