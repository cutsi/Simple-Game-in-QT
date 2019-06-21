#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>


class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
public slots:///member funk koje mogu biti povezane sa nekim signalom
    void move();

};

#endif // BULLET_H
