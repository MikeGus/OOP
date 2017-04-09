#include "point.h"

Errors point_to_point_2d(Point_2d& point_2d, Point& point, Coordinates axis)
{
    switch (axis) {
    case x:
        point_2d.x = point.y;
        point_2d.y = point.z;
        break;
    case y:
        point_2d.x = point.z;
        point_2d.y = point.x;
        break;
    case z:
        point_2d.x = point.x;
        point_2d.y = point.y;
        break;
    }

    return OK;
}

Errors point_2d_to_point(Point& point, Point_2d& point_2d, Coordinates axis)
{
    switch (axis) {
    case x:
        point.y = point_2d.x;
        point.z = point_2d.y;
        break;
    case y:
        point.z = point_2d.x;
        point.x = point_2d.y;
        break;
    case z:
        point.x = point_2d.x;
        point.y = point_2d.y;
        break;
    }

    return OK;
}

Errors points_to_points_2d(Point_2d* points_2d, Point* points, unsigned size, Coordinates axis)
{
    for (unsigned i = 0; i < size; ++i) {
        point_to_point_2d(points_2d[i], points[i], axis);
    }

    return OK;
}

Errors points_2d_to_points(Point* points, Point_2d* points_2d, unsigned size, Coordinates axis)
{
    for (unsigned i = 0; i < size; ++i) {
        point_2d_to_point(points[i], points_2d[i], axis);
    }

    return OK;
}
