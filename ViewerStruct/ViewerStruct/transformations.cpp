#include "transformations.h"
#include "rotation.h"
#include <cmath>


Errors apply_delete(Model& model)
{
    destroy_model(model);

    return OK;
}

//transformations
Errors apply_move(Model& model, MoveData& data)
{
    for (unsigned i = 0; i < model.number_of_points; ++i) {
        point_move(model.points[i], data);
    }

    return OK;
}


Errors apply_rotate(Model& model, RotData& data)
{
    Point center = find_center(model.points, model.number_of_points);

    Errors error = OK;

    error = apply_rotate_axis(model, data, center, x);
    if (error != OK) {
        return error;
    }

    error = apply_rotate_axis(model, data, center, y);
    if (error != OK) {
        return error;
    }

    error = apply_rotate_axis(model, data, center, z);
    if (error != OK) {
        return error;
    }

    return error;
}

Errors apply_scale(Model& model, ScaleData& data)
{
    Point center = find_center(model.points, model.number_of_points);
    for (unsigned i = 0; i < model.number_of_points; ++i) {
        point_scale(model.points[i], data, center);
    }

    return OK;
}

//point transformations
void point_move(Point& point, MoveData& data)
{
    point.x += data.dx;
    point.y += data.dy;
    point.z += data.dz;
}



void point_scale(Point& point, ScaleData& data, Point& center)
{
    point.x = center.x + (point.x - center.x) * data.k;
    point.y = center.y + (point.y - center.y) * data.k;
    point.z = center.z + (point.z - center.z) * data.k;
}

Point find_center(Point* array, unsigned size)
{
    double sum_x = 0;
    double sum_y = 0;
    double sum_z = 0;

    for (unsigned i = 0; i < size; ++i) {
        sum_x += array[i].x;
        sum_y += array[i].y;
        sum_z += array[i].z;
    }

    Point center;
    center.x = sum_x / size;
    center.y = sum_y / size;
    center.z = sum_z / size;

    return center;
}

//rotation by axis
Errors apply_rotate_axis(Model& model, RotData& data, Point& center, Coordinates axis)
{
    Errors error = OK;

    Point_2d center_2d;
    point_to_point_2d(center_2d, center, axis);

    Point_2d* points_2d = new (std::nothrow) Point_2d[model.number_of_points];
    if (points_2d == nullptr) {
        error = ALLOCATION_ERROR;
        return error;
    }

    double angle = 0;
    switch(axis) {
    case x:
        angle = data.rotx;
        break;
    case y:
        angle = data.roty;
        break;
    case z:
        angle = data.rotz;
        break;
    }

    error = points_to_points_2d(points_2d, model.points, model.number_of_points, axis);
    if (error != OK) {
        delete[] points_2d;
        return error;
    }

    error = projections_rotation(points_2d, model.number_of_points, center_2d, angle);
    if (error != OK) {
        delete[] points_2d;
        return error;
    }

    error = points_2d_to_points(model.points, points_2d, model.number_of_points, axis);
    if (error != OK) {
        delete[] points_2d;
        return error;
    }

    delete[] points_2d;

    return error;
}
