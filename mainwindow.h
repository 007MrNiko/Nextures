#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QPixmap>
#include <QScrollBar>
#include <QGraphicsScene>

#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_file_clicked();
    void on_zoom_slider_valueChanged(int value);
    void on_angle_slider_valueChanged(int value);

    void on_multiplication_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

public:
    void set_picture(QString, int);
    void create_picture(int);
    int slider_postion_zoom{0}, slider_postion_angle{0}, size_of_image{5};
    double zoom_ratio{1.1};

    QPixmap current_picture, static_picture;
    QGraphicsScene *scene = new QGraphicsScene();


};
#endif // MAINWINDOW_H
