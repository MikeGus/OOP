#include "data_blueprint.h"

Blueprint init_blueprint()
{
    Blueprint model;
    model.number_of_edges = 0;
    model.number_of_points = 0;
    model.edges = nullptr;
    model.points = nullptr;

    return model;
}

Errors read_sizes_blueprint(Blueprint& blueprint, unsigned number_of_points, unsigned number_of_edges)
{
    blueprint.number_of_points = number_of_points;
    blueprint.number_of_edges = number_of_edges;
    return OK;
}

Errors allocate_blueprint(Blueprint& model, unsigned number_of_points, unsigned number_of_edges)
{
    model.points = new(std::nothrow) Point_2d[number_of_points];
    if (!model.points) {
        return ALLOCATION_ERROR;
    }

    model.edges = new(std::nothrow) Edge[number_of_edges];
    if (!model.edges) {
        delete[] model.points;
        return ALLOCATION_ERROR;
    }

    return OK;
}

Errors read_points_blueprint(Point_2d* blueprint_points, Point* model_points, unsigned number, ProjectionData& data)
{
    switch(data.type) {
    case isometric:
        for (unsigned i = 0; i < number; ++i) {
            blueprint_points[i] = to_isometric_view(model_points[i]);
        }
        break;

    default:
        break;
    }

    return OK;
}

Errors read_edges_blueprint(Edge* blueprint_edges, Edge* model_edges, unsigned number)
{
    for (unsigned i = 0; i < number; ++i) {
        blueprint_edges[i] = model_edges[i];
    }
    return OK;
}

Errors read_blueprint_data(Blueprint& blueprint, Model& model, ProjectionData& data)
{
    Errors error = read_points_blueprint(blueprint.points, model.points, blueprint.number_of_points, data);
    if (error != OK) {
        return error;
    }
    error = read_edges_blueprint(blueprint.edges, model.edges, blueprint.number_of_edges);

    return error;
}

Errors create_blueprint(Blueprint& blueprint, Model& model, ProjectionData& data)
{
    Blueprint buf_blueprint = init_blueprint();

    Errors error = OK;

    error = read_sizes_blueprint(buf_blueprint, model.number_of_points, model.number_of_edges);
    if (error != OK) {
        return error;
    }

    error = allocate_blueprint(buf_blueprint, buf_blueprint.number_of_points, buf_blueprint.number_of_edges);
    if (error != OK) {
        return error;
    }

    error = read_blueprint_data(buf_blueprint, model, data);
    if (error != OK) {
        destroy_blueprint(buf_blueprint);
        return error;
    }

    destroy_blueprint(blueprint);
    blueprint = buf_blueprint;
    return error;
}

void destroy_blueprint(Blueprint& model)
{
    if (model.edges) {
        delete[] model.edges;
        model.edges = nullptr;
    }
    if (model.points) {
        delete[] model.points;
        model.points = nullptr;
    }
    model.number_of_edges = 0;
    model.number_of_points = 0;
}

