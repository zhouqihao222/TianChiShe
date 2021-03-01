#ifndef WALL_H
#define WALL_H

#include <QRectF>
#include <QVector>

class wall
{
public:
   wall();
   virtual ~wall();

   void createwall();

   static const int thestartX=0;
   static const int thestartY=0;
   static const int w = 900;
   static const int h = 600;

   QVector<QRectF> thewall;//墙
};

#endif // WALL_H
