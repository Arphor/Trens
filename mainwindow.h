#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include <QMutex>
#include <QMutexLocker>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_velocity_1_valueChanged(int value);

    void on_velocity_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    int tx1;
    int ty1;
    int tx2;
    int ty2;
    int ve1;
    int ve2;
    QMutex m;

};

#endif // MAINWINDOW_H
