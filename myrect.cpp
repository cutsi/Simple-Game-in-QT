#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include <QDebug>
#include "enemy.h"


void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)/// ne zelimo da nam objekt izlazi iz scene(prozora)
        {
             setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 1024) /// 100=velicina objekta, 1024 sirina scene
        {
            setPos(x()+10,y());
        }
    }

    else if (event->key() == Qt::Key_Space)///zelimo sa ovom tipkom ispucati metak
    {
        Bullet * bullet = new Bullet();///sa ovim ga stvaramo
        bullet->setPos(x()+45,y()-40);///postavljamo polozaj metka u odnosu na objekt
        scene()->addItem(bullet);/// dodajemo bullet u scenu
    }
}


void MyRect::stvori()
{
    Enemy * enemy = new Enemy(); ///kreiramo neprijatelja
    scene()->addItem(enemy);/// svaki item ima funk scene koja vraca pointer u kojoj se sceni nalazi
}
