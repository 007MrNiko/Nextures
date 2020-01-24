#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //startup functions

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_picture(QString picture_location){
    QPixmap texture(picture_location);
    //QImage texture(picture_location);

    QGraphicsScene *scene = new QGraphicsScene();
    //QGraphicsView *view = new QGraphicsView(scene);
    //QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(texture));
    //scene->addItem(item);

    scene->addPixmap(texture);
    ui->texture_viewer->setScene(scene);
}

void MainWindow::on_open_file_clicked()
{
    // seting filter data in explorer
    QString filter = "All File (*.*) ;; Image File (*.png; *.jpg; *.jpeg) ;; PSD File (*.psd)";
    // creating string with file adress
    QString opened_file = QFileDialog::getOpenFileName(this,"Open a file", QDir::homePath(), filter);

    if(opened_file == ""){ // do nothing when if path is empty "nothing selected"
        return;
    }

    ui->file_name->setText(opened_file);

    set_picture(opened_file);

}

void MainWindow::on_zoom_slider_valueChanged(int value)
{
    if(value > slider_postion){
        ui->texture_viewer->scale(zoom_ratio,zoom_ratio);
    }
    else {
        ui->texture_viewer->scale(1/zoom_ratio,1/zoom_ratio);
    }
    slider_postion = value;
}
