#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QDesktopWidget widget;
    int screenW=710;//寬
    int screenH=410;//高
    w.setGeometry(widget.screen()->width()/2-(screenW/2),widget.screen()->height()/2-(screenH/2),screenW,screenH);//x,y,W,H
    w.setWindowTitle("Sudoku");
    w.setFixedSize(screenW,screenH);//限制視窗大小不可任意更改
    w.show();



    return a.exec();
}
