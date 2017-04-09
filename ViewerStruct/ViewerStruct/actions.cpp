#include "transformations.h"

Errors apply_action(Blueprint& blueprint, Actions action, ActionData& data)
{
    static Model model = init_model();
    Errors error = OK;
    switch(action) {
    case MOVE:
        error = apply_move(model, data.move_data);
        break;

    case ROTATE:
        error = apply_rotate(model, data.rot_data);
        break;

    case SCALE:
        error = apply_scale(model, data.scale_data);
        break;

    case LOAD:
        error = apply_load(model, data.file_name);
        break;

    case DELETE:
        error = apply_delete(model);
        break;

    case TO_PROJECTION:
        error = apply_to_projection(blueprint, model, data.projection_data);
        break;

    default:
        error = WRONG_COMMAND;
    }

    return error;
}
