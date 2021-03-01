#ifndef FOOD_H
#define FOOD_H

#include <QRectF>
#include<QTime>
#include"snake.h"


class food
{
public:
    food();
    virtual ~food();
    void createpos();

    snake *a;

    QRectF thefood;//食物
};

#endif // FOOD_H
