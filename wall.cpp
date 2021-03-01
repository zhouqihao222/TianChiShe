#include "wall.h"

wall::wall()
{

}
void wall::createwall()
{
    int theX=0;
    int theY=0;
    for (; theY < h; theY+=20)
    {
        theX = thestartX;
        for (; theX < w; theX+=20)
        {
//            if (theY == 0 || theY == h - 20 || theY == 60||theX ==0||theX == w-20)
//            {
//               thewall.push_back(QRectF(theX,theY,20,20));
//            }
            if (theY == 40)
            {
               thewall.push_back(QRectF(theX,theY,20,20));
            }
        }
    }
}
wall::~wall()
{

}
