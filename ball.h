#ifndef BALL_H
#define BALL_H
#include <QGraphicsPixmapItem>

class Ball: public QGraphicsPixmapItem
{
public:
    Ball();

    void advance(int phase);
    int speed;
};

#endif // BALL_H
