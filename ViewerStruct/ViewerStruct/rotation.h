#ifndef ROTATION_H
#define ROTATION_H

#include <cmath>
#include "point.h"

Errors projections_rotation(Point_2d* points, unsigned size, Point_2d& center, double fi);
Errors projection_rotation(Point_2d& point, Point_2d& center, double fi);

#endif // ROTATION_H
