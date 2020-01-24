#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QPixmap>
#include <QScrollBar>

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

private:
    Ui::MainWindow *ui;

public:
    void set_picture(QString);
    int slider_postion{0};
    double zoom_ratio{1.05};


};
#endif // MAINWINDOW_H
