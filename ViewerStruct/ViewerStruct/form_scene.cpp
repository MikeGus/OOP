#include "form_scene.h"

void draw_model(QGraphicsScene& scene, Blueprint& model)
{
    for (unsigned i = 0; i < model.number_of_edges; ++i) {
        Edge edge = model.edges[i];
        Point_2d first = model.points[edge.start];
        Point_2d second = model.points[edge.end];

        draw_line(scene, first, second);
    }
}

void draw_line(QGraphicsScene& scene, Point_2d& first, Point_2d& second)
{
    QLine line;
    line.setLine((int)first.x, (int)first.y, (int)second.x, (int)second.y);
    scene.addLine(line);
}
