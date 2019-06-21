#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QObject>



class MyRect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void stvori(); ///zelimo periodicki pozivat ovu funkciju pa je povezujemo sa timerom i zato je stavljamo u
    ///public slots
};


#endif // MYRECT_H
