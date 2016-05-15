#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QKeyEvent>
#include <Qtimer>
#include <time.h>
#include"btn.h"
#include "ball.h"
#include"score.h"
#include"timecounter.h"

class Scene:public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void Button();
    void GameStart();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ballrun();
    void keyPressEvent(QKeyEvent *event);
    //void scorequit();
    void clock();

    Score *score1;

    Timecounter *timer1;

    Btn *startbtn;
    Btn *exitbtn;
    Btn *returnbtn;
    Btn *rightface;
    Btn *leftface;
    Btn *feet;
    Btn *rule;
    Btn *title;
    Btn *again;
    Btn *finalpic;

    Ball *ball1;
    Ball *ball2;

    int screenMode;
    //rand
    QList<int> rand_list;
    QList<Ball*> ball_list;

    QTimer *ballspeed;
    QTimer *ballgenerate;


    int num_ball;//共產生多少球
    int number;//要消除的序號
   //int score=0;


    /*timer*/
    private slots:
        void timer_timeout();


    void random()
    {
            rand_list.push_back(rand()%2+1);

            if(rand_list.back()==1)
            {

                ball1 = new Ball();
                QPixmap bl1;
                bl1.load(":/images/ball1.png");
                bl1 = bl1.scaled(150,150);
                ball1->setPixmap(bl1);
                ball1->setPos(270,60);
                addItem(ball1);
                ball_list.push_back(ball1);
                num_ball++;
            }
            else if(rand_list.back()==2)
            {

                ball2 = new Ball();
                QPixmap bl2;
                bl2.load(":/images/ball2.png");
                bl2 = bl2.scaled(150,150);
                ball2->setPixmap(bl2);
                ball2->setPos(270,60);
                addItem(ball2);
                ball_list.push_back(ball2);
                num_ball++;
            }
            if(100 >ball_list[number]->pos().x())
            {
                number++;
            }
   }




};




#endif // SCENE_H
