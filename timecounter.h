#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H
#include<QGraphicsTextItem>
#include<QString>
#include<QFont>

class Timecounter:public QGraphicsTextItem
{
public:
    Timecounter();
    int cnt;
    void decreasingtime();
};

#endif // TIMECOUNTER_H
