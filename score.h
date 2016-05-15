#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QString>
#include<QFont>

class Score:public QGraphicsTextItem
{
public:
    Score();
    int score;
    void ball_1_grade();
    void ball_2_grade();
};

#endif // SCORE_H
