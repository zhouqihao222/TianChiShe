#include "passwindow.h"
#include"Game.h"
#include"startwindow.h"
#include "ui_passwindow.h"

passwindow::passwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwindow)
{
    ui->setupUi(this);
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


    connect(ui->end,&QPushButton::clicked,this,&passwindow::close);
    connect(ui->again,&QPushButton::clicked,this,&passwindow::againGame);

   // ui->levup->setText(QString("当前得分:")+QString("%1").arg(scores));
    ui->levup->setText(QString("恭喜通关，等级上限+1！"));
    ui->levup->setStyleSheet("color: #FFFFFF;");
    ui->levup->setFont(QFont("微软雅黑",18));
}

void passwindow::againGame()
{

    emit managerMasseg(3,0);

}

void passwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
       l_press = true;
       l_pos = event->globalPos();
    }
    event->ignore();

}
void passwindow::mouseMoveEvent(QMouseEvent *event)
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
void passwindow::mouseReleaseEvent(QMouseEvent *event)
{
    l_press=false;
    event->ignore();
}
void passwindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
        this->close();
        break;
     }
}

passwindow::~passwindow()
{
    delete ui;
}
