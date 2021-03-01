#ifndef CAT_H
#define CAT_H

#include <QRectF>
#include<QTimer>
#include"snake.h"
#include"food.h"


class cat
{
public:
    cat(snake *,food *);
    virtual ~cat();
    void createcat();

    snake *b;
    food *c;
    bool is_alive;

    QRectF thecat;//猫
};

#endif // CAT_H
