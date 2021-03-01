#include "snake.h"
#include <iostream>
#include <conio.h>

snake::snake()
{

}
void snake::snakebody(int len,QPointF topLeft,snake::Directions dir,int Width,int Height)
{
    S_width = Width;
    S_height = Height;
    S_len = len;
    S_direction = dir;

//初始化蛇
    if(dir==Directions::W)
    {
           for(int i=0;i<S_len;i++)
           {
               s_body.append(QRectF(topLeft+QPoint(0,i*S_height),topLeft+QPoint(0,i*S_height)+QPointF(S_width,S_height)));
           }
    }
    else if (dir==Directions::S)
    {
           for(int i=0;i<S_len;i++)
           {
               s_body.append(QRectF(topLeft-QPoint(0,i*S_height),topLeft-QPoint(0,i*S_height)+QPointF(S_width,S_height)));
           }
    }
    else if (dir==Directions::A)
    {
           for(int i=0;i<S_len;i++)
           {
               s_body.append(QRectF(topLeft+QPoint(i*S_width,0),topLeft+QPoint(i*S_width,0)+QPointF(S_width,S_height)));
           }
    }
    else if (dir==Directions::D)
    {
           for(int i=0;i<S_len;i++)
           {
               s_body.append(QRectF(topLeft-QPoint(i*S_width,0),topLeft-QPoint(i*S_width,0)+QPointF(S_width,S_height)));
           }
    }
}

//向上移动时增加蛇节点
void snake::Upadd()
{
  s_body.insert(0,QRectF(s_body.at(0).topLeft()+QPointF(0,-12),s_body.at(0).topRight()));
}
//向下移动时增加蛇节点
void snake::Downadd()
{
  s_body.insert(0,QRectF(s_body.at(0).bottomLeft(),s_body.at(0).bottomRight()+QPointF(0,12)));
}
//向左移动时增加蛇节点
void snake::Leftadd()
{
  s_body.insert(0,QRectF(s_body.at(0).topLeft()+QPointF(-12,0),s_body.at(0).bottomLeft()));
}
//向右移动时增加蛇节点
void snake::Rightadd()
{
  s_body.insert(0,QRectF(s_body.at(0).topRight(),s_body.at(0).bottomRight()+QPointF(12,0)));
}
//移动......
void snake::MoveUp()
{
    if(S_direction != Directions::S)
    {
       Upadd();
       S_direction = Directions::W;
    }
}
void snake::MoveDown()
{
    if(S_direction != Directions::W)
    {
       Downadd();
       S_direction = Directions::S;
    }
}
void snake::MoveLeft()
{
    if(S_direction != Directions::D)
    {
       Leftadd();
       S_direction = Directions::A;
    }
}
void snake::MoveRight()
{
    if(S_direction != Directions::A)
    {
       Rightadd();
       S_direction = Directions::D;
    }
}

void snake::move()
{
    if(S_direction==Directions::W)
    {
       MoveUp();
    }
    else if (S_direction==Directions::S)
    {
       MoveDown();
    }else if (S_direction==Directions::A)
    {
       MoveLeft();
    }else if (S_direction==Directions::D)
    {
       MoveRight();
    }
}
void snake::growp()
{
    QRectF s_unit(0, 0, 12,12);
    s_body.push_back(s_unit);
    S_len++;
}
snake::~snake()
{
}

