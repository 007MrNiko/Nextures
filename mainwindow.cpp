#include "mainwindow.h"
#include "ui_mainwindow.h"

/*To do
 * 1) Fix position after changing n x n
 * 2) Add toolbar (rotate, reset, zoom) by buttons
 * 3) UI/UX
 * 4) Check at UNIX
 * 5) Download support
 * 6) PSD opening
 * 7) Add slider fixed positions 3x3 5x5 7x7 9x9 12x12 15x15 17x17 19x19 21x21
 */

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

void MainWindow::set_picture(QString picture_location, int size_nxn){
    QPixmap texture(picture_location);
    //current_picture = texture;
    static_picture = texture;
    create_picture(size_nxn);

    scene->addPixmap(current_picture);
    ui->texture_viewer->setScene(scene);
}

void MainWindow::create_picture(int size_nxn){
    int width = static_picture.width();
    int height = static_picture.height();

    QPixmap cache_for_picture(width*size_nxn, height*size_nxn);
    for (int i{0}; i<width*size_nxn; i+=width){
        for (int j{0}; j<height*size_nxn; j+=height) {
            QPainter painter(&cache_for_picture);
            painter.drawPixmap(QPoint(i,j),static_picture);
            painter.save();
        }
    }

    current_picture = cache_for_picture;

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

    set_picture(opened_file, size_of_image);

}

void MainWindow::on_zoom_slider_valueChanged(int value)
{
    if(value > slider_postion_zoom){
        ui->texture_viewer->scale(zoom_ratio,zoom_ratio);
    }
    else {
        ui->texture_viewer->scale(1/zoom_ratio,1/zoom_ratio);
    }
    slider_postion_zoom = value;
    QString info = QString::number(value)+ "%";
    ui->zoom_status->setText(info);
}

void MainWindow::on_angle_slider_valueChanged(int value)
{
    if(value > slider_postion_angle){
        ui->texture_viewer->rotate(10);
        slider_postion_angle+=10;
    }
    else {
        ui->texture_viewer->rotate(-10);
        slider_postion_angle-=10;
    }
    QString info = QString::number(value)+ "°";
    ui->angle_status->setText(info);
}

void MainWindow::on_multiplication_slider_valueChanged(int value)
{
    /*if(value % 3 != 0){
        //value+=2;
        ui->multiplication_slider->setValue(value+1);

    }*/

    scene->clear();
    create_picture(value);

    scene->addPixmap(current_picture);
    ui->texture_viewer->scale(1,1);
    ui->texture_viewer->setScene(scene);

    QString info = QString::number(value) + "x" + QString::number(value);
    ui->multiplication_status->setText(info);

    //ui->texture_viewer->setTransform(QTransform());
}
