#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "actions.h"
#include "errors.h"
#include "data_real.h"
#include "action_load.h"

void point_move(Point& point, MoveData& data);
void point_rotate(Point& point, RotData& data, Point& center);
void point_scale(Point& point, ScaleData& data, Point &center);
Point find_center(Point* array, unsigned size);

Errors apply_move(Model& model, MoveData& data);
Errors apply_rotate(Model& model, RotData& data);
Errors apply_scale(Model& model, ScaleData& data);
Errors apply_delete(Model& model);

Errors apply_rotate_axis(Model& model, RotData& data, Point& center, Coordinates axis);
#endif // TRANSFORMATIONS_H
