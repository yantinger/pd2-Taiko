#include "score.h"

Score::Score()
{
    score=0;
    setPlainText(QString("score:")+QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",20));

}

void Score::ball_1_grade()
{

    score=score+100;
    setPlainText(QString("score:")+QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",20));

}

void Score::ball_2_grade()
{
    score=score+200;
    setPlainText(QString("score:")+QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",20));


}

