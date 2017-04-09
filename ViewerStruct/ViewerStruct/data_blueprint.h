#ifndef DATAISOMETRIC_H
#define DATAISOMETRIC_H
#include "data_real.h"
#include <new>
#include "data_projection.h"

struct Blueprint {

    unsigned number_of_points;
    unsigned number_of_edges;
    Point_2d* points;
    Edge* edges;
};

Blueprint init_blueprint();
Errors create_blueprint(Blueprint& blueprint, Model& model, ProjectionData& data);
void destroy_blueprint(Blueprint& model);

#endif // DATAISOMETRIC_H
