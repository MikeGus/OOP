#ifndef DATAVAULT_H
#define DATAVAULT_H

#include "point.h"
#include "errors.h"
#include "isometric.h"
#include <cstdio>

const unsigned good_sizes_read = 2;
const unsigned good_point_read = 3;
const unsigned good_edge_read = 2;


struct Edge {

    unsigned start;
    unsigned end;
};

struct Model {

    unsigned number_of_points;
    unsigned number_of_edges;
    Point* points;
    Edge* edges;
};

Model init_model();
Errors read_model(Model& model, FILE* file);

void destroy_model(Model& model);

#endif // DATAVAULT_H
