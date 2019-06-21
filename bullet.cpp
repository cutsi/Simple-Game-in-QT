#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>
#include "enemy.h"
#include <QGraphicsItem>
Bullet::Bullet()
{
    setRect(0,0,10,50); ///kreiramo metak sirine 10 duzine 50
    QTimer * timer = new QTimer();/// svaki put kad timer bude 0 signal ce se poslati, povezujemo slot sa ovom
    ///funkcijom connect
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);///svaki 50milisekndi signal ce se emitirati ili metak ce se pomicat
}
void Bullet::move()
{

    QList<QGraphicsItem*> sudarajuci_elementi = collidingItems(); /// list pointera sudarajucih elemenata, gotova
    ///collidingItems() funkcija koja provjerava da li se dva objekta sudaraju
    ///vraca listu pointera za sve sudarajjuce elemente u listi
    /// u toj listi spremamo sve objekte koji se sudaraju sa metcima
    int n=collidingItems().size();
    for(int i=0;i<n;++i)///sa ovim forom cemo vidit sa kojim tocno objektima se metci sudaraju
    {
        if(typeid(*(sudarajuci_elementi[i])) == typeid(Enemy))///zelimo provjeriti da li je tip od sudarajuceg
            ///elementa jednak neprijatelju a dobijemo ga tako da ga dereferenciramo
       {
            scene()->removeItem(sudarajuci_elementi[i]);
            scene()->removeItem(this);
            delete sudarajuci_elementi[i];
            delete this;
            return; ///prekid u slucaju kolizije, program se srusi ako dopustimo daljne pomicanje metka prema gore
       }

    }

    setPos(x(),y()-10); ///bullet ide gore po 10pixela po 50 milisekundi
    if(pos().y()+50 < 0)/// pošto je najvisa koordinata 0, zelimo provjeriti da li je y os
        ///manja od nule i ako koji item prijedje tu granicu da se izbrise da ne zauzima nepotrebno
        /// mjesto u memoriji, u ovom slucaju zelimo izbrisati metke koji izadju iz scene
    {
        scene()->removeItem(this);
        delete this;
        ///qDebug() << "metak izbrisan";

    }
}
