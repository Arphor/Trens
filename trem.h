#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QSemaphore>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int, QMutex*, QMutex*, QMutex*, QMutex*, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*, int*);  //construtor
    void run();         //função a ser executada pela thread


//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   mutable QMutex *m_mutex0;
   mutable QMutex *m_mutex1;
   mutable QMutex *m_mutex2;
   mutable QMutex *m_mutex3;
   mutable QSemaphore *s0;
   mutable QSemaphore *s1;
   mutable QSemaphore *s2;
   mutable QSemaphore *s3;
   mutable QSemaphore *s4;
   int ID;          //ID do trem
   int *velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
