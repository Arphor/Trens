#include "trem.h"
#include <QtCore>


//Construtor
Trem::Trem(int ID, int x, int y, QMutex *m_mutex0,QMutex *m_mutex1,QMutex *m_mutex2,QMutex *m_mutex3, QSemaphore *s0, QSemaphore *s1, QSemaphore *s2, QSemaphore *s3, QSemaphore *s4, int *v){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->m_mutex0 = m_mutex0;
    this->m_mutex1 = m_mutex1;
    this->m_mutex2 = m_mutex2;
    this->m_mutex3 = m_mutex3;
    this->s0 = s0;
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
    this->s4 = s4;
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
                        s3->acquire(1);
                        s1->acquire(1);
                        m_mutex0->lock();
                    }
                    x+=10;
                }else{
                    if (x == 300 && y < 140){
                        if(y == 120){
                            s0->acquire(1);
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
                            if (x == 210){
                                if (s0->available() < 2){
                                    s0->release(1);
                                }
                            }
                            if(x == 280){
                                if (s3->available() < 2){
                                    s3->release(1);
                                }
                                if (s1->available() < 2){
                                    s1->release(1);
                                }
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
                        if (y == 120){
                            s2->acquire(1);
                            m_mutex2->lock();
                        }
                        y+=10;
                    }else{
                        if (x > 300 && y == 140){
                            if (x == 320){
                                m_mutex0->lock();
                            }
                            if (x == 400){
                                s3->acquire(1);
                                s1->acquire(1);
                                m_mutex1->lock();
                            }
                            if (x == 360){
                                if (s2->available() < 2){
                                    s2->release(1);
                                }
                                m_mutex2->unlock();
                            }
                            x-=10;
                        }else{
                            if (y == 120){
                                if (s3->available() < 2){
                                    s3->release(1);
                                }
                                if (s1->available() < 2){
                                    s1->release(1);
                                }
                                m_mutex1->unlock();
                            }
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 3: //Trem 3

                if (y == 140 && x <230){
                    if (x == 210){
                        m_mutex1->lock();
                    }
                    if (x == 130){
                        s3->acquire(1);
                        s0->acquire(1);
                        m_mutex0->lock();
                    }
                    x+=10;
                }else{
                    if (x == 230 && y < 260){
                        if (y == 160){
                            if (s3->available() < 2){
                                s3->release(1);
                            }
                            if(s0->available() < 2){
                                s0->release(1);
                            }
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
                        if (s1->available() < 2){
                            s1->release(1);
                        }
                        m_mutex0->unlock();
                    }
                    if (x == 250){
                        if (s3->available() < 2){
                            s3->release(1);
                        }
                        if (s0->available() < 2){
                            s0->release(1);
                        }
                        m_mutex2->unlock();
                    }
                    if (x == 280){
                        s2->acquire(1);
                        m_mutex1->lock();
                    }
                    if (x == 360){
                        m_mutex3->lock();
                    }
                    x+=10;
                }else{
                    if (x == 380 && y < 260){
                        if (y == 160){
                            if (s2->available() < 2){
                                s2->release(1);
                            }
                            m_mutex1->unlock();
                        }
                        y+=10;
                    }else{
                        if (x > 230 && y == 260){
                            if (x == 250){
                                s3->acquire(1);
                                s0->acquire(1);
                                m_mutex2->lock();
                            }
                            if (x == 360){
                                m_mutex3->unlock();
                            }
                            x-=10;
                        }else{
                            if (y == 160){
                                s1->acquire(1);
                                m_mutex0->lock();
                            }
                            y-=10;
                        }
                    }
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 5:

                if (y == 140 && x <530){
                    if (x == 470){
                        m_mutex0->unlock();
                    }
                    if (x == 400){
                        if (s2->available() < 2){
                            s2->release(1);
                        }
                        m_mutex1->unlock();
                    }
                    x+=10;
                }else{
                    if (x == 530 && y < 260){
                        y+=10;
                    }else{
                        if (x > 380 && y == 260){
                            if (x == 400){
                                qDebug() << "acquire 5";
                                s2->acquire(1);
                                m_mutex1->lock();
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




