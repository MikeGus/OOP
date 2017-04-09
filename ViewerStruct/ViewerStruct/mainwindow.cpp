#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, ui->graphicsView->width(),\
                               ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    model = init_blueprint();
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::on_movBtn_clicked()
{
    ActionData data;

    MoveData move_data;
    //get data from fields
    move_data.dx = (ui->movX->text()).toDouble();
    move_data.dy = (ui->movY->text()).toDouble();
    move_data.dz = (ui->movZ->text()).toDouble();

    data.move_data = move_data;

    //send data to calculation domain
    Errors error = apply_action(model, MOVE, data);
    if (error == OK) {
        ProjectionData proj_data;
        proj_data.type = isometric;
        data.projection_data = proj_data;
        error = apply_action(model, TO_PROJECTION, data);
    }

    //drawing
    ui->graphicsView->scene()->clear();
    draw_model(*scene, model);
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_rotBtn_clicked()
{
    ActionData data;
    RotData rot_data;

    //get data from fields
    rot_data.rotx = deg_to_rad((ui->rotX->text()).toDouble());
    rot_data.roty = deg_to_rad((ui->rotY->text()).toDouble());
    rot_data.rotz = deg_to_rad((ui->rotZ->text()).toDouble());

    data.rot_data = rot_data;

    //send data to calculation domain
    Errors error = apply_action(model, ROTATE, data);
    if (error == OK) {
        ProjectionData proj_data;
        proj_data.type = isometric;
        data.projection_data = proj_data;
        error = apply_action(model, TO_PROJECTION, data);
    }
    apply_action(model, TO_PROJECTION, data);

    //drawing
    ui->graphicsView->scene()->clear();
    draw_model(*scene, model);
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_scaleBtn_clicked()
{
    ActionData data;
    ScaleData scale_data;

    //get data from fields
    scale_data.k = (ui->scaleK->text()).toDouble();

    data.scale_data = scale_data;

    //send data to calculation domain
    Errors error = apply_action(model, SCALE, data);
    if (error == OK) {
        ProjectionData proj_data;
        proj_data.type = isometric;
        data.projection_data = proj_data;
        error = apply_action(model, TO_PROJECTION, data);
    }

    //drawing
    ui->graphicsView->scene()->clear();
    draw_model(*scene, model);
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_loadBtn_clicked()
{
    //get data from fields
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл", ".");
    if (file_name.length() <= 0)
        return;

    char *str_file_name = new char[file_name.length() + 1];
    strcpy (str_file_name, file_name.toStdString().c_str());

    ActionData data;
    data.file_name = str_file_name;

    //send data to calculation domain
    Errors error = apply_action(model, LOAD, data);
    if (error == OK) {
        ProjectionData proj_data;
        proj_data.type = isometric;
        data.projection_data = proj_data;
        error = apply_action(model, TO_PROJECTION, data);
    }

    //working with errors
    switch (error)
    {
    case OK:
        //drawing
        ui->graphicsView->scene()->clear();
        draw_model(*scene, model);
        ui->graphicsView->viewport()->update();
        break;
    case CORRUPTED_FILE:
        QMessageBox::information(this, "Загрузка модели", "Некорректный файл!");
        break;
    case MISSING_FILE:
        QMessageBox::information(this, "Загрузка модели", "Файл не найден!");
        break;
    case ALLOCATION_ERROR:
        QMessageBox::information(this, "Загрузка модели", "Ошибка выделения памяти!");
        break;
    case WRONG_COMMAND:
        QMessageBox::information(this, "Загрузка модели", "Неверная команда!");
    }

    delete[] data.file_name;
}

void MainWindow::on_delBtn_clicked()
{
    ActionData data;
    apply_action(model, DELETE, data);

    ui->graphicsView->scene()->clear();
    ui->graphicsView->viewport()->update();
}
