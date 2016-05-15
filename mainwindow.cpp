#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <iostream>

using namespace std;

//int cnt=5;
//QTimer *timer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();//指標指向新物件
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,700,400);
    SetBG();//呼叫!!






     //  if(scene->screenMode==1)
         // {
          // timer=new QTimer(this);
         //  timer->setInterval(1000);
          // connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
          // timer->start();

        //  }





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetBG()
{
    QImage BG;
    BG.load(":/images/BC.png");
    BG=BG.scaled(710,410);
    scene->setBackgroundBrush(BG);
    scene->Button();



}




//void MainWindow::timer_timeout()
//{
  //  cnt--;
   // ui->time->setText(QString::number(cnt));


//}





