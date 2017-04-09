#include "action_to_projection.h"


Errors apply_to_projection(Blueprint& blueprint, Model& model, ProjectionData& data)
{
    Errors error = create_blueprint(blueprint, model, data);

    return error;
}
