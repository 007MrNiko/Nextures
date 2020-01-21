#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_picture(QString picture_location){
    QPixmap picture(picture_location);

    ui->texture_viewer->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    picture = picture.scaled(ui->texture_viewer->size(), Qt::KeepAspectRatioByExpanding);
    //ui->texture_viewer->set
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
