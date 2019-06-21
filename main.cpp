#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene(); ///kreira se scena

    MyRect *player = new MyRect(); /// kreiranje itema kojeg zelimo u sceni
    player->setRect(0,0,100,100); /// kreiranje itema sa koordinatama 0,0 i
    ///velicinom i duzinom od 100x i 100y pixela

    scene->addItem(player); /// u scenu dodajemo taj item
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    QGraphicsView *view = new QGraphicsView(scene); ///posaljemo mu scenu koju je potrebno
    ///vizualizirati, saljemo je kao pointer
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// ovo sluzi da se scrool bar ne ide u
    ///vjecnost tj da metci izadju iz scene a ne da idu u beskonacnost
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);/// ista stvar samo da ne idemo
    ///verticalno u bekonacnost



    view->show(); ///prikazujemo scenu
    view->setFixedSize(1024,800);///rezolucija prozora
    scene->setSceneRect(0,0,1024,800);
    player->setPos(view->width()/2,view->height()-player->rect().height()-5);///centitramo objekt u sredinu zato ide
    /// /2 a za y smo uzeli velicinu scene i oduzeli joj 5 tako da objekt samo malo viri iznad okvira prozora

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(stvori()) );
    timer->start(2000);///objekt se pojavi svako 2 sekunde

    return a.exec();
}
