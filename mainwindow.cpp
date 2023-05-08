#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ve1 = 100;
    ve2 = 100;
    ve3 = 100;
    ve4 = 100;
    ve5 = 100;
    ve6 = 100;
    ve7 = 100;

    //Cria o trem com seu (ID, posição X, posição Y)


    trem1 = new Trem(1,150, 20, &m0, &m1, &m2, NULL, &ve1);
    trem2 = new Trem(2,300, 20, &m0, NULL, NULL, NULL, &ve2);
    trem3 = new Trem(3, 80, 140, &m1, &m5, NULL, NULL, &ve3);
    trem4 = new Trem(4, 230, 140, &m2, &m3, &m5, &m6, &ve4);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));


    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();



}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3:
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4:
        ui->label_trem4->setGeometry(x, y, 21, 17);
        break;
    default:
        break;
    }
}


MainWindow::~MainWindow()
{
    m0.~QMutex();
    m1.~QMutex();
    m2.~QMutex();
    m3.~QMutex();
    m4.~QMutex();
    m5.~QMutex();
    m6.~QMutex();
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 *
void MainWindow::on_pushButton_clicked()
{
    trem1->start();
    trem2->start();
}

*/

/*
 * Ao clicar, trens param execução

void MainWindow::on_pushButton_2_clicked()
{
    trem1->terminate();
    trem2->terminate();
}
*/

void MainWindow::on_velocity_1_valueChanged(int value)
{
    ve1 = value;
}



void MainWindow::on_velocity_2_valueChanged(int value)
{
    ve2 = value;
}


void MainWindow::on_velocity_3_valueChanged(int value)
{
    ve3 = value;
}

