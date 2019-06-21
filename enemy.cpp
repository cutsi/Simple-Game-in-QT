#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> ///za rand() funk
Enemy::Enemy()
{
    int randomNum = rand() % 700; /// stavljamo %700 jer rand vraca jako velik int a taj int treba
    ///biti u granicama scene
    setPos(/*x ce biti random broj*/randomNum,0 ); /// random num stavljamo tako da bi se neprijatelji
    ///pojavljivali nasumicno a y je 0 jer ih zelimo da se pojavljuju sa vrha
    setRect(0,0,100,100); ///kreiramo neprijatelja duzine 100 i sirine 100
    QTimer * timer = new QTimer(this);/// svaki put kad timer bude 0 signal ce se poslati, povezujemo slot
    ///sa ovom funkcijom connect
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);///svaki 50milisekndi signal ce se emitirati ili neprjatelj ce se pomicat
}
void Enemy::move()
{
    setPos(x(),y()+5); ///neprijatelj ide dolje (+5 po y osi) 5pixela po 50 milisekundi
    if(pos().y()+50 < 0)/// pošto je najvisa koordinata 0, zelimo provjeriti da li je y os
        ///manja od nule i ako koji item prijedje tu granicu da se izbrise da ne zauzima nepotrebno
        /// mjesto u memoriji, u ovom slucaju zelimo izbrisati metke koji izadju iz scene
    {
        scene()->removeItem(this);
        delete this;
        ///qDebug() << "metak izbrisan";

    }
}
