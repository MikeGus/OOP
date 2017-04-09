#include "data_real.h"
#include <new>

Model init_model()
{
    Model model;
    model.number_of_points = 0;
    model.number_of_edges = 0;
    model.edges = nullptr;
    model.points = nullptr;

    return model;
}

Errors allocate_model(Model& model)
{
    model.points = new(std::nothrow) Point[model.number_of_points];
    if (!model.points) {
        return ALLOCATION_ERROR;
    }

    model.edges = new(std::nothrow) Edge[model.number_of_edges];
    if (!model.edges) {
        delete[] model.points;
        return ALLOCATION_ERROR;
    }

    return OK;
}

Errors read_sizes(unsigned& number_of_points, unsigned& number_of_edges, FILE* file)
{
    Errors error = OK;

    if (fscanf(file, "%u%u", &(number_of_points), &(number_of_edges)) != good_sizes_read) {
        error =  CORRUPTED_FILE;
    }

    return error;
}

Errors read_point(Point& point, FILE* file)
{
    Errors error = OK;
    if (fscanf(file, "%lf%lf%lf", &(point.x), &(point.y), &(point.z)) != good_point_read) {
        error =  CORRUPTED_FILE;
    }

    return error;
}

Errors read_edge(Edge& edge, FILE* file)
{
    Errors error = OK;
    if (fscanf(file, "%u%u", &(edge.start), &(edge.end)) != good_edge_read) {
        error = CORRUPTED_FILE;
    }

    return error;
}

Errors read_points(Point* points, unsigned number_of_points, FILE* file)
{
    Errors error = OK;
    Point buf_point;
    for (unsigned i = 0; (i < number_of_points) && (error != CORRUPTED_FILE); ++i) {
        read_point(buf_point, file);
        points[i] = buf_point;
    }

    return error;
}

Errors read_edges(Edge* edges, unsigned number_of_edges, FILE* file)
{
    Errors error = OK;
    Edge buf_edge;
    for (unsigned i = 0; (i < number_of_edges) && (error != CORRUPTED_FILE); ++i) {
        read_edge(buf_edge, file);
        edges[i] = buf_edge;
    }

    return error;
}

Errors read_model_data(Model& model, FILE* file)
{
    Errors error = read_points(model.points, model.number_of_points, file);
    if (error != OK) {
        return error;
    }

    error = read_edges(model.edges, model.number_of_edges, file);

    return error;
}

Errors read_model(Model& model, FILE* file)
{
    Errors error = OK;
    Model buffer_model = init_model();

    error = read_sizes(buffer_model.number_of_points, buffer_model.number_of_edges, file);
    if (error != OK) {
        return error;
    }

    error = allocate_model(buffer_model);
    if (error != OK) {
        return error;
    }

    error = read_model_data(buffer_model, file);
    if (error != OK) {
        destroy_model(buffer_model);
        return error;
    }

    destroy_model(model);
    model = buffer_model;

    return OK;
}

void destroy_model(Model& model)
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
