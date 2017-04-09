#ifndef FORMSCENE_H
#define FORMSCENE_H
#include <QGraphicsScene>
#include <QLine>
#include "data_real.h"
#include "data_blueprint.h"
#include "isometric.h"

void draw_model(QGraphicsScene& scene, Blueprint& model);
void draw_line(QGraphicsScene& scene, Point_2d& first, Point_2d& second);

#endif // FORMSCENE_H
