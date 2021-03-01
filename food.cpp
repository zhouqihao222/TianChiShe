#include "food.h"
#include"wall.h"
#include"Game.h"


food::food()
{

}
void food::createpos()
{

    qsrand(int(time(0)));
//            m_x = wall::StartX + 2 + rand() % (wall::w - 8);
//            m_y = wall::StartY + 4 + rand() % (wall::h - 2);
//            while (!wall::checkPointInTheWall(m_x, m_y) || !snake::checkPointInTheSnake(this))
//            {
//                srand(int(time(0)));
//                m_x = wall::StartX + 2 + rand() % (wall::w - 8);
//                m_y = wall::StartY + 4 + rand() % (wall::h - 2);
//            }
    thefood=(QRectF(wall::thestartX+30+qrand()%((wall::w-50)/30)*20,wall::thestartY+80+qrand()%((wall::h-50)/30)*20,20,20));
//    for(int i=0; i<a->s_body.length(); i++)
//  {
//      while (thefood.toRect()==b->cat.toRect()||thefood.contains(a->s_body.at(i).topLeft()+QPointF(b->TheWidth/2,b->TheHeight/2)))
//     {
//            qsrand(int(time(0)));
//            thefood=(QRectF(wall::thestartX+30+qrand()%((wall::w-50)/30)*20,wall::thestartY+80+qrand()%((wall::h-50)/30)*20,35,35));
//      }
//  }
}
food::~food()
{

}
