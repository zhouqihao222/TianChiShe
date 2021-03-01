#include "endwindow.h"
#include"Game.h"
#include"startwindow.h"
#include "ui_endwindow.h"

endwindow::endwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::endwindow)
{
    ui->setupUi(this);
    setFixedSize(900,600);
    //窗口无边框
    setWindowFlag(Qt::FramelessWindowHint);
    //设置窗体背景色为黑色
    this->setStyleSheet("QWidget{background:black}");
    //设置窗口的透明度
    setWindowOpacity(0.9);
    //设置下方应用图标
    this->setWindowIcon(QIcon(":/resource/tubiao.png"));
    sound3=new QSound(":/music/false.wav");

    sound3->play();

    connect(ui->end,&QPushButton::clicked,this,&endwindow::close);
    connect(ui->again,&QPushButton::clicked,this,&endwindow::againgame);

}
void endwindow::againgame()
{

    emit managerMasseg(2,0);

}

void endwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
       l_press = true;
       l_pos = event->globalPos();
    }
    event->ignore();

}
void endwindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint move_pos;
    if(l_press)
    {
        move_pos=event->globalPos()-l_pos;
        l_pos = event->globalPos();
        window()->move(window()->pos()+move_pos);
    }
    event->ignore();
}
void endwindow::mouseReleaseEvent(QMouseEvent *event)
{
    l_press=false;
    event->ignore();
}
void endwindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
        this->close();
        break;
     }
}
endwindow::~endwindow()
{
    delete ui;
    delete sound3;
}
