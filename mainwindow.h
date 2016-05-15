#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;
    void SetBG();
    void timecounter();

//private slots:
    //void timer_timeout();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
