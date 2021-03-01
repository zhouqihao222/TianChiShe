#include "startwindow.h"
#include "ui_startwindow.h"

startwindow::startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startwindow)
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

    connect(ui->no,&QPushButton::clicked,this,&startwindow::close);
    connect(ui->yes,&QPushButton::clicked,this,&startwindow::thegame);

    ui->athu->setText(QString("制作人：周启豪"));
    ui->athu->setStyleSheet("color: #FFFFFF;");
    ui->athu->setFont(QFont("微软雅黑",9));
    ui->edition->setText(QString("版本：1.0"));
    ui->edition->setStyleSheet("color: #FFFFFF;");
    ui->edition->setFont(QFont("微软雅黑",9));

}


void startwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
       l_press = true;
       l_pos = event->globalPos();
    }
    event->ignore();

}
void startwindow::mouseMoveEvent(QMouseEvent *event)
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
void startwindow::mouseReleaseEvent(QMouseEvent *event)
{
    l_press=false;
    event->ignore();
}
void startwindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
        this->close();
        break;
     }
}
void startwindow::thegame()
{
    //1代表Game,0代表start,2代表end
   emit managerMasseg(0,1);
}


startwindow::~startwindow()
{
    delete ui;
}



