#ifndef SNAKE_H
#define SNAKE_H

#include <QRectF>
#include <QVector>

class snake
{
public:
    snake();
    virtual ~snake();

    enum Directions{A,S,D,W };

    int S_direction = Directions::W;

    int S_len;
    int S_width;
    int S_height;

    QVector<QRectF>s_body;

    void snakebody(int len = 3,QPointF topLeft=QPointF(100,300),Directions dir=Directions::W,int Width=12,int Height=12);
    void growp();
    void move();
    void s_speed();

    void Upadd();
    void Downadd();
    void Leftadd();
    void Rightadd();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

};

#endif // SNAKE_H
