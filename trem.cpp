#include "trem.h"
#include <QtCore>


//Construtor
Trem::Trem(int ID, int x, int y, QMutex *m_mutex0,QMutex *m_mutex1,QMutex *m_mutex2,QMutex *m_mutex3, int *v){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->m_mutex0 = m_mutex0;
    this->m_mutex1 = m_mutex1;
    this->m_mutex2 = m_mutex2;
    this->m_mutex3 = m_mutex3;
    velocidade = v;
}


//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        while(*velocidade != 0){
            switch(ID){
            case 1:     //Trem 1
                if (y == 20 && x <300){
                    if(x == 280){
                        m_mutex0->lock();
                    }
                    x+=10;
                }else{
                    if (x == 300 && y < 140){
                        if(y == 120){
                            m_mutex2->lock();
                        }
                        y+=10;
                    }else{
                        if (x > 150 && y == 140){
                            if (x == 220){
                                m_mutex2->unlock();
                            }
                            if (x == 250){
                                m_mutex1->lock();
                            }
                            if(x == 280){
                                m_mutex0->unlock();
                            }
                            x-=10;
                        }else{
                            if(y == 130){
                                m_mutex1->unlock();
                            }
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2: //Trem 2

                if (y == 20 && x <450){
                    if(x == 320){
                        m_mutex0->unlock();
                    }
                    x+=10;
                }else{
                    if (x == 450 && y < 140){
                        y+=10;
                    }else{
                        if (x > 300 && y == 140){
                            if (x == 320){
                                m_mutex0->lock();
                            }
                            x-=10;
                        }else{
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 3: //Trem 3

                if (y == 140 && x <230){
                    if (x == 220){
                        m_mutex1->lock();
                    }
                    if (x == 130){
                        m_mutex0->lock();
                    }
                    x+=10;
                }else{
                    if (x == 230 && y < 260){
                        if (y == 160){
                            m_mutex0->unlock();
                        }
                        y+=10;
                    }else{
                        if (x > 80 && y == 260){
                            if (x == 220){
                                m_mutex1->unlock();
                            }
                            x-=10;
                        }else{
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 4:  //Trem 4

                if (y == 140 && x <380){
                    if (x == 320){
                        m_mutex0->unlock();
                    }
                    if (x == 250){
                        m_mutex2->unlock();
                    }
                    x+=10;
                }else{
                    if (x == 380 && y < 260){
                        y+=10;
                    }else{
                        if (x > 230 && y == 260){
                            if (x == 250){
                                m_mutex2->lock();
                            }
                            x-=10;
                        }else{
                            if (y == 160){
                                m_mutex0->lock();
                            }
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;


            default:
                break;
            }
            msleep(250-*velocidade);
        }

    }
}




