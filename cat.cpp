#include "cat.h"
#include"wall.h"

cat::cat(snake *theSnake,food *theFood):b(theSnake),c(theFood)
{
    is_alive=false;
}
void cat::createcat()
{
      qsrand(int(time(0)));
      thecat=(QRectF(wall::thestartX+30+qrand()%((wall::w-50)/30)*20,wall::thestartY+80+qrand()%((wall::h-50)/30)*20,50,50));
      for(int i=0; i<b->s_body.length(); i++)
    {
        while (thecat.toRect()==c->thefood.toRect()||thecat.contains(b->s_body.at(i).topLeft()+QPointF(6,10)))
       {
              qsrand(int(time(0)));
              thecat=(QRectF(wall::thestartX+30+qrand()%((wall::w-50)/30)*20,wall::thestartY+80+qrand()%((wall::h-50)/30)*20,50,50));
        }
    }
    is_alive=true;

}
cat::~cat()
{

}

