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

    void on_velocity_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    Trem *trem7;
    int ve1;
    int ve2;
    int ve3;
    int ve4;
    int ve5;
    int ve6;
    int ve7;
    QMutex m0;
    QMutex m1;
    QMutex m2;
    QMutex m3;
    QMutex m4;
    QMutex m5;
    QMutex m6;

};

#endif // MAINWINDOW_H
