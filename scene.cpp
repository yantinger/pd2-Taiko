#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include<QTimer>

QTimer *timer;

using namespace std;

Scene::Scene()
{
    screenMode =0;

}


void Scene::Button()
{
    startbtn = new Btn();
    QPixmap sb;
    sb.load(":/images/St.png");
    sb=sb.scaled(150,150,Qt::KeepAspectRatio);
    startbtn->setPixmap(sb);
    startbtn->setPos(410,275);
    addItem(startbtn);

    exitbtn=new Btn();
    QPixmap eb;
    eb.load(":/images/ex.png");
    eb=eb.scaled(200,200,Qt::KeepAspectRatio);
    exitbtn->setPixmap(eb);
    exitbtn->setPos(130,300);
    addItem(exitbtn);


    title=new Btn();
    QPixmap til;
    til.load(":/images/title.png");
    til=til.scaled(650,650,Qt::KeepAspectRatio);
    title->setPixmap(til);
    title->setPos(30,35);
    addItem(title);



}
 void Scene::GameStart()
 {

     /*remove button*/
     this->removeItem(startbtn);
     this->removeItem(exitbtn);
     this->removeItem(title);

     returnbtn = new Btn();
     QPixmap rb;
     rb.load(":/images/exit.png");
     rb=rb.scaled(100,100,Qt::KeepAspectRatio);
     returnbtn->setPixmap(rb);
     returnbtn->setPos(600,300);
     addItem(returnbtn);



     feet = new Btn();
     QPixmap ft;
     ft.load(":/images/exit.png");
     ft=ft.scaled(300,300,Qt::KeepAspectRatio);
     feet->setPixmap(ft);
     feet->setPos(0,0);
     addItem(feet);

     rightface = new Btn();
     QPixmap rf;
     rf.load(":/images/right.png");
     rf=rf.scaled(400,400,Qt::KeepAspectRatio);
     rightface->setPixmap(rf);
     rightface->setPos(190,-80);
     addItem(rightface);


     leftface = new Btn();
     QPixmap lf;
     lf.load(":/images/LEFT.png");
     lf=lf.scaled(400,400,Qt::KeepAspectRatio);
     leftface->setPixmap(lf);
     leftface->setPos(-50,-70);
     addItem(leftface);


     rule = new Btn();
     QPixmap rul;
     rul.load(":/images/RUL.png");
     rul=rul.scaled(350,350,Qt::KeepAspectRatio);
     rule->setPixmap(rul);
     rule->setPos(245,245);
     addItem(rule);

     /*SCORE顯示在螢幕*/
     score1=new Score();
     score1->setPos(525,60);
     addItem(score1);

     timer1=new Timecounter();
     timer1->setPos(525,30);
     addItem(timer1);

     clock();


 }

 void Scene::ballrun()
 {
     if(screenMode==1)
     {
         ballspeed=new QTimer(this);
         ballgenerate=new QTimer(this);
         connect(ballgenerate,SIGNAL(timeout()),this,SLOT(random()));
         connect(ballspeed,SIGNAL(timeout()),this,SLOT(advance()));
         ballgenerate->start(1000);//產生球球的頻率
         ballspeed->start(20);//X-1的時間間隔

     }
    /*何時關掉*/
     if(screenMode == 0)
     {
     disconnect(ballgenerate,SIGNAL(timeout()),this,SLOT(random()));
     disconnect(ballspeed,SIGNAL(timeout()),this,SLOT(advance()));
     disconnect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
     }

     if(screenMode == 2)
     {
     disconnect(ballgenerate,SIGNAL(timeout()),this,SLOT(random()));
     disconnect(ballspeed,SIGNAL(timeout()),this,SLOT(advance()));
     disconnect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
     }


 }

 void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     if(screenMode ==0)
     {
        if(event->scenePos().x() > startbtn->pos().x() && event->scenePos().x() <= startbtn->pos().x()+140)
        {
            if(event->scenePos().y() > startbtn->pos().y() && event->scenePos().y() <= startbtn->pos().y()+105)
            {
                cout<<"Start"<<endl;
                GameStart();
                screenMode = 1;
                ballrun();
                removeItem(again);

            }
        }

        if(event->scenePos().x() > exitbtn->pos().x() && event->scenePos().x() <= exitbtn->pos().x()+140)
        {
            if(event->scenePos().y() > exitbtn->pos().y() && event->scenePos().y() <= exitbtn->pos().y()+90)
            {
                cout<<"exit"<<endl;
                QApplication::exit();

            }
        }
     }
     if(screenMode==1)
     {
         if(event->scenePos().x()>returnbtn->pos().x()&&event->scenePos().x()<returnbtn->pos().x()+80)
             if(event->scenePos().y()>returnbtn->pos().y()+10&&event->scenePos().y()<returnbtn->pos().y()+85)
             {
                 removeItem(feet);
                 removeItem(leftface);
                 removeItem(rightface);
                 removeItem(returnbtn);
                 removeItem(rule);


                 for(int i=0;i<num_ball;i++)
                 {
                     removeItem(ball_list[i]);
                 }
                 Button();
                 screenMode = 0;
                 ballrun();
                 ball_list.clear();
                 rand_list.clear();
                 number=0;
                 num_ball=0;
                 score1->score=0;
                 removeItem(score1);
                 removeItem(timer1);


             }
     }

     if(screenMode ==2)
     {
        if(event->scenePos().x() > again->pos().x() && event->scenePos().x() <= again->pos().x()+400)
        {
            if(event->scenePos().y() > again->pos().y() && event->scenePos().y() <= again->pos().y()+150)
            {
                removeItem(feet);
                removeItem(leftface);
                removeItem(rightface);
                removeItem(returnbtn);
                removeItem(rule);
                removeItem(again);
                removeItem(finalpic);
                removeItem(score1);

                for(int i=0;i<num_ball;i++)
                {
                    removeItem(ball_list[i]);
                }
                Button();
                screenMode = 0;
                ballrun();
                ball_list.clear();
                rand_list.clear();
                number=0;
                num_ball=0;
                score1->score=0;




            }
        }


     }
}

 void Scene::keyPressEvent(QKeyEvent *event)
 {

    if(screenMode==0)
    {
        if(event->key()==Qt::Key_Enter)
        {
            GameStart();
            screenMode = 1;
            ballrun();
            removeItem(again);
        }

        if(event->key()==Qt::Key_Escape)
        {
             QApplication::exit();

        }


     }
    if(screenMode==1)
    {
        if(event->key()==Qt::Key_Space)
        {

            removeItem(feet);
            removeItem(leftface);
            removeItem(rightface);
            removeItem(returnbtn);
            removeItem(rule);


            for(int i=0;i<num_ball;i++)
            {
                removeItem(ball_list[i]);
            }
            Button();
            screenMode = 0;
            ballrun();
            ball_list.clear();
            rand_list.clear();
            number=0;
            num_ball=0;
            score1->score=0;
            removeItem(score1);
            removeItem(timer1);
        }


     }


     if(screenMode ==1 && num_ball > 1)//至少要產生一顆球球
     {


         if(ball_list[number]->pos().x()<125&&ball_list[number]->pos().x()>100)
         {

             if(event->key()==Qt::Key_Left)
             {
                 if(rand_list[number]==1)
                 {
                     removeItem(ball_list[number]);
                     number++;

                     score1->ball_1_grade();
                      cout<<score1->score<<endl;


                 }
             }
         }
         if(ball_list[number]->pos().x()<125&&ball_list[number]->pos().x()>100)
         {

             if(event->key()==Qt::Key_Right)
             {
                 if(rand_list[number]==2)
                 {
                     removeItem(ball_list[number]);
                     number++;

                     score1->ball_2_grade();
                     cout<<score1->score<<endl;

                 }
             }
         }

     }

     if(screenMode==2)
     {
         if(event->key()==Qt::Key_Space)
         {

             removeItem(feet);
             removeItem(leftface);
             removeItem(rightface);
             removeItem(returnbtn);
             removeItem(rule);
             removeItem(again);
             removeItem(finalpic);
             removeItem(score1);

             for(int i=0;i<num_ball;i++)
             {
                 removeItem(ball_list[i]);
             }
             Button();
             screenMode = 0;
             ballrun();
             ball_list.clear();
             rand_list.clear();
             number=0;
             num_ball=0;
             score1->score=0;


         }


      }

 }




 void Scene::timer_timeout()
 {
   //  cnt--;
    //ui->time->setText(QString::number(cnt));
   timer1->decreasingtime();

   if(timer1->cnt==0)
   {

       removeItem(feet);
       removeItem(leftface);
       removeItem(rightface);
       removeItem(returnbtn);
       removeItem(rule);
       removeItem(timer1);
       for(int i=0;i<num_ball;i++)
       {
           removeItem(ball_list[i]);
       }

       screenMode = 2;//切成2
       ballrun();
       ball_list.clear();
       rand_list.clear();
       number=0;
       num_ball=0;

       again = new Btn();
       QPixmap ag;
       ag.load(":/images/again.png");
       ag=ag.scaled(400,400,Qt::KeepAspectRatio);
       again->setPixmap(ag);
       again->setPos(150,200);
       addItem(again);

       finalpic = new Btn();
       QPixmap fc;
       fc.load(":/images/FINAL.png");
       fc=fc.scaled(500,500,Qt::KeepAspectRatio);
       finalpic->setPixmap(fc);
       finalpic->setPos(5,5);
       addItem(finalpic);

     }
 }



 void Scene::clock()
 {

timer=new QTimer(this);
timer->setInterval(1000);
connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
timer->start();

 }


 /*void Scene::scorequit()
 {

     if(cnt==0)
     {

         removeItem(feet);
         removeItem(leftface);
         removeItem(rightface);
         removeItem(returnbtn);
         removeItem(rule);
         for(int i=0;i<num_ball;i++)
         {
             removeItem(ball_list[i]);
         }

         screenMode = 2;//切成2
         ballrun();
         ball_list.clear();
         rand_list.clear();
         number=0;
         num_ball=0;

         again = new Btn();
         QPixmap ag;
         ag.load(":/images/again.png");
         ag=ag.scaled(400,400,Qt::KeepAspectRatio);
         again->setPixmap(ag);
         again->setPos(150,200);
         addItem(again);



     }


 }*/






