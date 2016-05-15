#include "timecounter.h"

Timecounter::Timecounter()
{
    cnt=30;
    setPlainText(QString("time:")+QString::number(cnt));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",20));


}


void Timecounter::decreasingtime()
{

    cnt--;
    setPlainText(QString("time:")+QString::number(cnt));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",20));
}
