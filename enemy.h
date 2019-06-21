#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>


class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
public slots:///member funk koje mogu biti povezane sa nekim signalom
    void move();

};

#endif // ENEMY_H
