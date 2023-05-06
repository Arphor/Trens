#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int *x, int *y, int *xc, int *yc, QMutex *m_mutex, int *v){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->xc = xc;
    this->yc = yc;
    this->m_mutex = m_mutex;
    velocidade = v;
}


//Função a ser executada após executar trem->START
void Trem::run(){
    QMutex m;
    while(true){
        switch(ID){
        case 1:     //Trem 1

            if (*y == 30 && *x==320){
                m_mutex->lock();
                *x+=10;
            }

            if (*y == 30 && *x <320){
                *x+=10;
            }else{
                if (*x == 330 && *y < 150){
                    while(*y < 150){
                        *y+=10;
                        emit updateGUI(ID, *x,*y);
                        msleep(200-*velocidade);
                    }
                    qDebug() << "unlock";
                    m_mutex->unlock();
                }else{
                    if (*x > 60 && *y == 150){
                        *x-=10;
                    }else{
                        *y-=10;
                    }
                }
            }
            emit updateGUI(ID, *x,*y);    //Emite um sinal
            break;
        case 2: //Trem 2

            if (*y == 30 && *x <600){
                *x+=10;
            }else{
                if (*x == 600 && *y < 150){
                    *y+=10;
                }else{
                    if (*x > 330 && *y == 150){
                        *x-=10;
                    }else{
                        qDebug() << "esperando" << *y;
                        m_mutex->lock();
                        while(*y > 30){
                            *y=*y;
                            emit updateGUI(ID, *x,*y);
                            msleep(200-*velocidade);
                        }
                        m_mutex->unlock();
                    }
                }
            }
            emit updateGUI(ID, *x,*y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(200-*velocidade);
    }
}




