#ifndef ACTIONS_H
#define ACTIONS_H

#include "errors.h"
#include "data_real.h"
#include "data_blueprint.h"
#include "data_move.h"
#include "data_rotate.h"
#include "data_scale.h"
#include "data_blueprint.h"
#include "action_to_projection.h"

enum Actions {

    MOVE = 0,
    ROTATE = 1,
    SCALE = 2,
    LOAD = 3,
    DELETE = 4,
    TO_PROJECTION = 5
};

union ActionData {

    Actions action;
    char* file_name;
    MoveData move_data;
    RotData rot_data;
    ScaleData scale_data;
    ProjectionData projection_data;
};

Errors apply_action(Blueprint& model, Actions action, ActionData& data);

#endif // ACTIONS_H
