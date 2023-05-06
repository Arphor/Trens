#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, QMutex *m_mutex, int *v){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->m_mutex = m_mutex;
    velocidade = v;
}


//Função a ser executada após executar trem->START
void Trem::run(){
    QMutex m;
    while(true){
        while(*velocidade != 0){
            switch(ID){
            case 1:     //Trem 1
                if (y == 30 && x <330){
                    if(x == 310){
                        m_mutex->lock();
                    }
                    x+=10;
                }else{
                    if (x == 330 && y < 150){
                           y+=10;
                    }else{
                        if (x > 60 && y == 150){
                            if(x == 310){
                                m_mutex->unlock();
                            }
                            x-=10;
                        }else{
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2: //Trem 2

                if (y == 30 && x <600){
                    if(x == 350){
                        m_mutex->unlock();
                    }
                    x+=10;
                }else{
                    if (x == 600 && y < 150){
                        y+=10;
                    }else{
                        if (x > 330 && y == 150){
                            if (x == 350){
                                m_mutex->lock();
                            }
                            x-=10;
                        }else{
                            //qDebug() << "esperando" << y;
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            default:
                break;
            }
            msleep(200-*velocidade);
        }

    }
}




