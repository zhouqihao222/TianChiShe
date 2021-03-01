#include "Game.h"
#include "cat.h"
#include "ui_Game.h"

Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
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

    //音效
    sound=new QSound(":/music/eatfood.wav");
    sound1=new QSound(":/music/eatstra.wav");
    sound2=new QSound(":/music/eatcat.wav");
    bgm=new QSound(":/music/bgm.wav");


    //初始化地图
    b=new wall();
    b->createwall();

    //初始化蛇
    c=new snake();
    c->snakebody();

    //初始化食物
    a= new food();
    a->createpos();

    //初始化猫
    d=new cat(c,a);
    //初始化草莓
    e=new strawberry();

    //定时器
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timeOut()));
    timer->start(speed);

    cat_timer = new QTimer(this);
    cat_timer->setInterval(8000);
    connect(cat_timer,&QTimer::timeout,this,[=]{
       setcat();
    });
    cat_timer->start();

    strawberry_timer= new QTimer(this);
    strawberry_timer->setInterval(20000);
    connect(strawberry_timer,&QTimer::timeout,this,[=]{
       setstrawberry();
    });
    strawberry_timer->start();


//    myPlayer= new QMediaPlayer(this);
//    myPlayer->setMedia(QUrl::fromLocalFile(":/music/bgm.mp3"));
//    myPlayer->setVolume(200);//设置声音大小
//    myPlayer->play();

      bgm->play();
      bgm_timer= new QTimer(this);
      bgm_timer->setInterval(95000);
      connect(bgm_timer,&QTimer::timeout,this,[=]{
        bgm->play();
    });
      bgm_timer->start();


}
//界面刷新
void Game::timeOut()
{

  if(a->thefood.contains(c->s_body.at(0).topLeft()+QPointF(TheWidth/2,TheHeight/2)))
    {
        sound->play();
        a->createpos();
        c->growp();
        c->S_len++;
    }
  if(d->is_alive)
  {
      if(d->thecat.contains(c->s_body.at(0).topLeft()+QPointF(TheWidth/2,TheHeight/2)))
      {
          sound2->play();
          setcat();
          DeleteLast();
          c->S_len--;
      }
  }
  if(e->is_alive)
  {
      if(e->thestrawberry.contains(c->s_body.at(0).topLeft()+QPointF(TheWidth/2,TheHeight/2)))
      {
          sound1->play();
          e->strawberrydel();
          c->growp();
          c->S_len++;
      }
  }

        switch (move)
      {
        case W:
            c->MoveUp();
            break;
        case S:
            c->MoveDown();
            break;
        case D:
            c->MoveRight();
            break;
        case A:
            c->MoveLeft();
            break;
        default:
            break;
       }
    DeleteLast();
    update();
}

//删除结尾数据
void Game::DeleteLast()
{
    c->s_body.removeLast();
}

//绘图
void Game::paintEvent(QPaintEvent *)
{
        theuserlev();
        s_speed();
        QPainter painter(this);

        //QPen: 用于绘制几何图形的边缘,由颜色,宽度,线风格等参数组成
        //QBrush: 用于填充几何图形的调色板,由颜色和填充风格组成
        QPen pen;
        QBrush brush;

        painter.setRenderHint(QPainter::Antialiasing);
        brush.setStyle(Qt::SolidPattern);
        pen.setColor(Qt::white);
        painter.setPen(pen);

       //画食物
        painter.drawPixmap(a->thefood.toRect(),QPixmap(":/resource/food.png"));

       //画猫
       if(d->is_alive)
       {
            painter.drawPixmap(d->thecat.toRect(),QPixmap(":/resource/cat.png"));
       }

       //画草莓
       if(e->is_alive)
       {
            painter.drawPixmap(e->thestrawberry.toRect(),QPixmap(":/resource/stra.png"));
       }


       //画蛇
        for(int i=0; i<c->s_body.length(); i++)
        {
            if(i==0)
            {
               brush.setColor(Qt::red);
               painter.setBrush(brush);
               painter.drawRect(c->s_body.at(i));
            }
            else
            {
                brush.setColor(Qt::green);
                painter.setBrush(brush);
                painter.drawRect(c->s_body.at(i));
            }
        }
        //墙
//        for(QVector<QRectF>::iterator it=wall.begin();it!=wall.end();it++)
//        {
//            wall[1];
//        }
        for(auto it:b->thewall)
        painter.drawPixmap(it.toRect(),QPixmap(":/resource/thewall.png"));


        //显示得分
        ui->sourc->setText(QString("当前得分:")+QString("%1").arg(scores));
        ui->sourc->setStyleSheet("color: #FFFFFF;");
        ui->sourc->setFont(QFont("微软雅黑",18));
        //显示关卡
        ui->lev->setText(QString("当前关卡:")+QString("%1").arg(lev));
        ui->lev->setStyleSheet("color: #FFFFFF;");
        ui->lev->setFont(QFont("微软雅黑",18));
        //显示速度
        ui->speed->setText(QString("当前速度:")+QString("%1").arg(speed));
        ui->speed->setStyleSheet("color: #FFFFFF;");
        ui->speed->setFont(QFont("微软雅黑",18));
        //作者
        ui->author->setText(QString("玩家等级:")+QString("%1").arg(userlev));
        ui->author->setStyleSheet("color: #FFFFFF;");
        ui->author->setFont(QFont("微软雅黑",18));

        //游戏结束
        if(snakeStrike()||scores<0)
        {
           emit managerMasseg(1,2);
        }
        //游戏通关
        if(scores==300)
        {
          emit managerMasseg(1,3);
        }

}
//按键事件
void Game::keyPressEvent(QKeyEvent *event)
{
    s_speed();
    timer->start(speed);
    switch(event->key()){
    case Qt::Key_W:
        if(move != S){
            move = W;
        }
        break;
    case Qt::Key_S:
        if(move != W){
            move = S;
        }
        break;
    case Qt::Key_D:
        if(move != A){
            move = D;
        }
        break;
    case Qt::Key_A:
        if(move != D){
            move = A;
        }
        break;
    case Qt::Key_Escape:
        this->close();
        break;
    case Qt::Key_Space:
        if(Start && !Over)
        {
            timer->stop();
            Start = false;
        }
        else if(!Start && !Over)
        {
            timer->start(speed);
            Start=true;           
        }
        break;
    default:
        break;
    }
}

//判断蛇头是否和蛇身相撞
bool Game::snakeStrike()
{
    for(int i=0; i<c->s_body.length(); i++)
    {
        for(int j=i+1; j<c->s_body.length(); j++)
        {
            if(c->s_body.at(i) == c->s_body.at(j))
            {
                return true;
            }
        }
    }
     if(c->s_body.at(0).x()<=0||c->s_body.at(0).x() >= 900||c->s_body.at(0).y() <=60||c->s_body.at(0).y()>=600)
     {
              return true;
     }
     return false;
}
//速度
void Game::s_speed()
{
    int max_s = 40;
    int min_s = 140;
    scores=(c->s_body.length()-3)*10;
    int now_lev =(scores / ALevSpace)+1 ;
    lev = now_lev;
    speed = min_s - (min_s - max_s) / 5 * (scores / ALevSpace);
}
void Game::theuserlev()
{
    if(scores==300)
    {
       userlev+=1;
    }

}
//放置陷阱
void Game::setcat()
{
    s_speed();
    if(lev>=2)
  {
      d->createcat();
  }
}
void Game::setstrawberry()
{
    s_speed();
    if(lev>=3)
  {
      e->createstrawberry();
  }
}
 void Game::playbgm()
 {

 }

void Game::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
       l_press = true;
       l_pos = event->globalPos();
    }
    event->ignore();

}
void Game::mouseMoveEvent(QMouseEvent *event)
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
void Game::mouseReleaseEvent(QMouseEvent *event)
{
    l_press=false;
    event->ignore();
}
Game::~Game()
{
    delete ui;
    delete timer;
    delete cat_timer;
    delete bgm_timer;
    delete strawberry_timer;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete sound;
    delete sound1;
    delete sound2;
    delete myPlayer;
    delete bgm;
}

