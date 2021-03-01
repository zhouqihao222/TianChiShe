#include "strawberry.h"
#include"wall.h"

strawberry::strawberry()
{
    is_alive=false;
}
 void strawberry::createstrawberry()
 {
     is_alive=true;
     qsrand(int(time(0)));
     thestrawberry=(QRectF(wall::thestartX+30+qrand()%((wall::w-50)/30)*20,wall::thestartY+80+qrand()%((wall::h-50)/30)*20,20,20));
 }
 void strawberry::strawberrydel()
 {
     thestrawberry.moveTo(-1,-1);
 }
 strawberry::~strawberry()
 {

 }
