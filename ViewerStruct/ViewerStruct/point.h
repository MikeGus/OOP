#ifndef POINT_H
#define POINT_H
#include "errors.h"

enum Coordinates {
    x = 0,
    y,
    z
};


struct Point {

    double x;
    double y;
    double z;
};

struct Point_2d {

    double x;
    double y;
};

Errors points_to_points_2d(Point_2d* points_2d, Point* points, unsigned size, Coordinates axis);
Errors points_2d_to_points(Point* points, Point_2d* points_2d, unsigned size, Coordinates axis);

Errors point_to_point_2d(Point_2d& point_2d, Point& point, Coordinates axis);
Errors point_2d_to_point(Point& point, Point_2d &point_2d, Coordinates axis);

#endif // POINT_H
