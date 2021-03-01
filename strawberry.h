#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include <QRectF>
#include<QTimer>

class strawberry
{
public:
    strawberry();
    virtual ~strawberry();
    void createstrawberry();
    void strawberrydel();
    bool is_alive;

    QRectF thestrawberry;//草莓
};

#endif // STRAWBERRY_H
