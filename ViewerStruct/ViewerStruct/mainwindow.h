#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include "errors.h"
#include "actions.h"
#include "data_blueprint.h"
#include "form_scene.h"
#include "deg_to_rad.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_movBtn_clicked();

    void on_rotBtn_clicked();

    void on_scaleBtn_clicked();

    void on_loadBtn_clicked();

    void on_delBtn_clicked();

private:
    Ui::MainWindow *ui;
    Blueprint model;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
